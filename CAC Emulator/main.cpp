#include "main.h"

uint32_t dwSAMPAddr = NULL;

typedef void(__thiscall* tRegisterAsRemoteProcedureCall)(void*, int*, void(*) (RPCParameters*));
typedef bool(__thiscall* tRPC)(void*, int*, BitStream*, PacketPriority, PacketReliability, char, bool);
tRPC oRPC;

bool RPC(int uniqueID, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp)
{
	void** pRakClient = *(void***)((*(DWORD*)(dwSAMPAddr + 0x21A0F8)) + 0x3C9);
	return (tRPC(dwSAMPAddr + 0x30B30))(pRakClient, &uniqueID, bitStream, priority, reliability, orderingChannel, shiftTimestamp);
}

void RegisterAsRemoteProcedureCall(int uniqueID, void(*functionPointer)(RPCParameters*))
{
	void** pRakClient = *(void***)((*(DWORD*)(dwSAMPAddr + 0x21A0F8)) + 0x3C9);
	return (tRegisterAsRemoteProcedureCall(dwSAMPAddr + 0x30F90))(pRakClient, &uniqueID, functionPointer);
}

//Pseudocode from IDA
void CAC_Checksum(RPCParameters* rpcParms, BYTE* pOutput)
{
	BitStream* pBitStream = new BitStream(rpcParms->input, rpcParms->numberOfBitsOfData / 8, false);
	uint8_t v14, v15, * v3 = pOutput;

	do
	{
		uint8_t* v4 = v3++;
		pBitStream->ReadBits(v4, 8, 1);
	} while (v3 != pOutput + 13);

	pBitStream->ReadBits(&v14, 8, 1);
	pBitStream->ReadBits(&v15, 8, 1);

	int v5 = v14 - 1, v13 = v14;

	if ((uint8_t)(v14 - 1) > 0xC)
	{
		do
		{
			int v6 = (uint8_t)v5--;
			pBitStream->ReadBits((uint8_t*)pOutput + v6, 8, 1);
		} while (v5 != 12);
		v13 = v14;
	}

	if (v13)
	{
		int v7 = v15, v8 = 0, v9 = 0, v10 = 0;

		do
		{
			int v11 = (v13 >> 1) + v10;
			++v8;
			v11 = v11 ^ 0xAC;
			*((uint8_t*)pOutput + v9) ^= *((uint8_t*)pOutput + (v7 + *((uint8_t*)pOutput + v11 % v13)) % v13);
			v9 = v8;
			v10 = v8;
		} while (v8 < v13);
	}
}

void CAC_Challenge(RPCParameters* rpcParms)
{
	BitStream bitStream(rpcParms->input, rpcParms->numberOfBitsOfData / 8, false);

	bitStream.SetReadOffset(0x68);
	uint8_t byteSize = 0;
	bitStream.Read(byteSize);

	uint8_t* pOutput = (uint8_t*)malloc(20 * sizeof(uint8_t));
	CAC_Checksum(rpcParms, pOutput);

	BitStream bsSend;
	bsSend.Write<uint32_t>(0x00);
	bsSend.Write((char*)pOutput, byteSize);

	RPC(183, &bsSend, HIGH_PRIORITY, RELIABLE_ORDERED, NULL, false);
	free(pOutput);
}

void CAC_ReadMemory(RPCParameters* rpcParms)
{
	BitStream bitStream(rpcParms->input, rpcParms->numberOfBitsOfData / 8, false);

	uint32_t dwAddress = 0;
	BYTE byteSize = 0;

	bitStream.Read(dwAddress);
	bitStream.Read(byteSize);

	BitStream bsSend;
	bsSend.Write<uint32_t>(dwAddress);
	bsSend.Write<uint8_t>(byteSize);

	for (auto i = 0; i < byteSize; i++)
		bsSend.Write<BYTE>(*reinterpret_cast<BYTE*>(dwAddress + i));

	RPC(185, &bsSend, HIGH_PRIORITY, RELIABLE_SEQUENCED, NULL, false);
}

std::string RandomString()
{
	std::string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");
	std::random_device rd;
	std::mt19937 generator(rd());
	std::shuffle(str.begin(), str.end(), generator);
	return str.substr(0, 32);      
}

bool __fastcall hkRPC(void* pThis, void* pUnk, int* uniqueID, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp)
{
	if (*uniqueID == RPC_ClientJoin)
	{
		std::string szHWID(Base64::Encode(RandomString()));
		uint8_t byteHWIDSize = szHWID.size();

		BitStream bsSend;
		bsSend.Write<uint16_t>(0xCAC);
		bsSend.Write<uint32_t>(0x0000A00);
		bsSend.Write<uint8_t>(byteHWIDSize);
		bsSend.Write((char*)szHWID.c_str(), byteHWIDSize);

		RPC(180, &bsSend, HIGH_PRIORITY, RELIABLE_SEQUENCED, NULL, false);

		RegisterAsRemoteProcedureCall(187, CAC_Challenge);
		RegisterAsRemoteProcedureCall(189, CAC_ReadMemory);
	}

	return oRPC(pThis, uniqueID, bitStream, priority, reliability, orderingChannel, shiftTimestamp);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call == DLL_PROCESS_ATTACH)
	{
		MH_Initialize();
		dwSAMPAddr = reinterpret_cast<uint32_t>(LoadLibraryA("samp.dll"));
		MH_CreateHook(reinterpret_cast<void*>(dwSAMPAddr + 0x30B30), &hkRPC, reinterpret_cast<void**>(&oRPC));
		MH_EnableHook(reinterpret_cast<void*>(dwSAMPAddr + 0x30B30));
	}
	return TRUE;
}

