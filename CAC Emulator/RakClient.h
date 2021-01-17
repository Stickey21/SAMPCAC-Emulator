#pragma once

#include "main.h"

typedef unsigned int RakNetTime;
typedef long long RakNetTimeNS;

enum RPCEnumeration
{
	RPC_ClickPlayer = 23,
	RPC_ClientJoin = 25,
	RPC_EnterVehicle = 26,
	RPC_EnterEditObject = 27,
	RPC_ScriptCash = 31,
	RPC_ServerCommand = 50,
	RPC_Spawn = 52,
	RPC_Death = 53,
	RPC_NPCJoin = 54,
	RPC_DialogResponse = 62,
	RPC_ClickTextDraw = 83,
	RPC_SCMEvent = 96,
	RPC_Chat = 101,
	RPC_SrvNetStats = 102,
	RPC_ClientCheck = 103,
	RPC_DamageVehicle = 106,
	RPC_GiveTakeDamage = 115,
	RPC_EditAttachedObject = 116,
	RPC_EditObject = 117,
	RPC_SetInteriorId = 118,
	RPC_MapMarker = 119,
	RPC_RequestClass = 128,
	RPC_RequestSpawn = 129,
	RPC_PickedUpPickup = 131,
	RPC_MenuSelect = 132,
	RPC_VehicleDestroyed = 136,
	RPC_MenuQuit = 140,
	RPC_ExitVehicle = 154,
	RPC_UpdateScoresPingsIPs = 155,

	RPC_SetPlayerName = 11,
	RPC_SetPlayerPos = 12,
	RPC_SetPlayerPosFindZ = 13,
	RPC_SetPlayerHealth = 14,
	RPC_TogglePlayerControllable = 15,
	RPC_PlaySound = 16,
	RPC_SetPlayerWorldBounds = 17,
	RPC_GivePlayerMoney = 18,
	RPC_SetPlayerFacingAngle = 19,
	RPC_ResetPlayerMoney = 20,
	RPC_ResetPlayerWeapons = 21,
	RPC_GivePlayerWeapon = 22,
	RPC_SetVehicleParamsEx = 24,
	RPC_CancelEdit = 28,
	RPC_SetPlayerTime = 29,
	RPC_ToggleClock = 30,
	RPC_WorldPlayerAdd = 32,
	RPC_SetPlayerShopName = 33,
	RPC_SetPlayerSkillLevel = 34,
	RPC_SetPlayerDrunkLevel = 35,
	RPC_Create3DTextLabel = 36,
	RPC_DisableCheckpoint = 37,
	RPC_SetRaceCheckpoint = 38,
	RPC_DisableRaceCheckpoint = 39,
	RPC_GameModeRestart = 40,
	RPC_PlayAudioStream = 41,
	RPC_StopAudioStream = 42,
	RPC_RemoveBuildingForPlayer = 43,
	RPC_CreateObject = 44,
	RPC_SetObjectPos = 45,
	RPC_SetObjectRot = 46,
	RPC_DestroyObject = 47,
	RPC_DeathMessage = 55,
	RPC_SetPlayerMapIcon = 56,
	RPC_RemoveVehicleComponent = 57,
	RPC_Update3DTextLabel = 58,
	RPC_ChatBubble = 59,
	RPC_UpdateSystemTime = 60,
	RPC_ShowDialog = 61,
	RPC_DestroyPickup = 63,
	RPC_WeaponPickupDestroy = 64,
	RPC_LinkVehicleToInterior = 65,
	RPC_SetPlayerArmour = 66,
	RPC_SetPlayerArmedWeapon = 67,
	RPC_SetSpawnInfo = 68,
	RPC_SetPlayerTeam = 69,
	RPC_PutPlayerInVehicle = 70,
	RPC_RemovePlayerFromVehicle = 71,
	RPC_SetPlayerColor = 72,
	RPC_DisplayGameText = 73,
	RPC_ForceClassSelection = 74,
	RPC_AttachObjectToPlayer = 75,
	RPC_InitMenu = 76,
	RPC_ShowMenu = 77,
	RPC_HideMenu = 78,
	RPC_CreateExplosion = 79,
	RPC_ShowPlayerNameTagForPlayer = 80,
	RPC_AttachCameraToObject = 81,
	RPC_InterpolateCamera = 82,
	RPC_SetObjectMaterial = 84,
	RPC_GangZoneStopFlash = 85,
	RPC_ApplyAnimation = 86,
	RPC_ClearAnimations = 87,
	RPC_SetPlayerSpecialAction = 88,
	RPC_SetPlayerFightingStyle = 89,
	RPC_SetPlayerVelocity = 90,
	RPC_SetVehicleVelocity = 91,
	RPC_SetPlayerDrunkVisuals = 92,
	RPC_ClientMessage = 93,
	RPC_SetWorldTime = 94,
	RPC_CreatePickup = 95,
	RPC_SetVehicleTireStatus = 98,
	RPC_MoveObject = 99,
	RPC_EnableStuntBonusForPlayer = 104,
	RPC_TextDrawSetString = 105,
	RPC_SetCheckpoint = 107,
	RPC_GangZoneCreate = 108,
	RPC_PlayCrimeReport = 112,
	RPC_SetPlayerAttachedObject = 113,
	RPC_GangZoneDestroy = 120,
	RPC_GangZoneFlash = 121,
	RPC_StopObject = 122,
	RPC_SetNumberPlate = 123,
	RPC_TogglePlayerSpectating = 124,
	RPC_PlayerSpectatePlayer = 126,
	RPC_PlayerSpectateVehicle = 127,
	RPC_SetPlayerWantedLevel = 133,
	RPC_ShowTextDraw = 134,
	RPC_TextDrawHideForPlayer = 135,
	RPC_ServerJoin = 137,
	RPC_ServerQuit = 138,
	RPC_InitGame = 139,
	RPC_RemovePlayerMapIcon = 144,
	RPC_SetPlayerAmmo = 145,
	RPC_SetPlayerGravity = 146,
	RPC_SetVehicleHealth = 147,
	RPC_AttachTrailerToVehicle = 148,
	RPC_DetachTrailerFromVehicle = 149,
	RPC_SetPlayerDrunkHandling = 150,
	RPC_DestroyPickups = 151,
	RPC_SetWeather = 152,
	RPC_SetPlayerSkin = 153,
	RPC_SetPlayerInterior = 156,
	RPC_SetPlayerCameraPos = 157,
	RPC_SetPlayerCameraLookAt = 158,
	RPC_SetVehiclePos = 159,
	RPC_SetVehicleZAngle = 160,
	RPC_SetVehicleParamsForPlayer = 161,
	RPC_SetCameraBehindPlayer = 162,
	RPC_WorldPlayerRemove = 163,
	RPC_WorldVehicleAdd = 164,
	RPC_WorldVehicleRemove = 165,
	RPC_WorldPlayerDeath = 166,
};

enum PacketEnumeration
{
	ID_INTERNAL_PING = 6,
	ID_PING,
	ID_PING_OPEN_CONNECTIONS,
	ID_CONNECTED_PONG,
	ID_REQUEST_STATIC_DATA,
	ID_CONNECTION_REQUEST,
	ID_AUTH_KEY,
	ID_BROADCAST_PINGS = 14,
	ID_SECURED_CONNECTION_RESPONSE,
	ID_SECURED_CONNECTION_CONFIRMATION,
	ID_RPC_MAPPING,
	ID_SET_RANDOM_NUMBER_SEED = 19,
	ID_RPC,
	ID_RPC_REPLY,
	ID_DETECT_LOST_CONNECTIONS = 23,
	ID_OPEN_CONNECTION_REQUEST,
	ID_OPEN_CONNECTION_REPLY,
	ID_OPEN_CONNECTION_COOKIE,
	ID_RSA_PUBLIC_KEY_MISMATCH = 28,
	ID_CONNECTION_ATTEMPT_FAILED,
	ID_NEW_INCOMING_CONNECTION = 30,
	ID_NO_FREE_INCOMING_CONNECTIONS = 31,
	ID_DISCONNECTION_NOTIFICATION,
	ID_CONNECTION_LOST,
	ID_CONNECTION_REQUEST_ACCEPTED,
	ID_CONNECTION_BANNED = 36,
	ID_INVALID_PASSWORD,
	ID_MODIFIED_PACKET,
	ID_PONG,
	ID_TIMESTAMP,
	ID_RECEIVED_STATIC_DATA,
	ID_REMOTE_DISCONNECTION_NOTIFICATION,
	ID_REMOTE_CONNECTION_LOST,
	ID_REMOTE_NEW_INCOMING_CONNECTION,
	ID_REMOTE_EXISTING_CONNECTION,
	ID_REMOTE_STATIC_DATA,
	ID_ADVERTISE_SYSTEM = 55,

	ID_PLAYER_SYNC = 207,
	ID_MARKERS_SYNC = 208,
	ID_UNOCCUPIED_SYNC = 209,
	ID_TRAILER_SYNC = 210,
	ID_PASSENGER_SYNC = 211,
	ID_SPECTATOR_SYNC = 212,
	ID_AIM_SYNC = 203,
	ID_VEHICLE_SYNC = 200,
	ID_RCON_COMMAND = 201,
	ID_RCON_RESPONCE = 202,
	ID_WEAPONS_UPDATE = 204,
	ID_STATS_UPDATE = 205,
	ID_BULLET_SYNC = 206,
};

enum PacketPriority
{
	SYSTEM_PRIORITY,
	HIGH_PRIORITY,
	MEDIUM_PRIORITY,
	LOW_PRIORITY,
	NUMBER_OF_PRIORITIES
};

enum PacketReliability
{
	UNRELIABLE = 6,
	UNRELIABLE_SEQUENCED,
	RELIABLE,
	RELIABLE_ORDERED,
	RELIABLE_SEQUENCED
};

typedef unsigned short PlayerIndex;

#pragma pack(push, 1)
struct PlayerID
{
	unsigned int binaryAddress;
	unsigned short port;

	PlayerID& operator = (const PlayerID& input)
	{
		binaryAddress = input.binaryAddress;
		port = input.port;
		return *this;
	}

	bool operator==(const PlayerID& right) const;
	bool operator!=(const PlayerID& right) const;
	bool operator > (const PlayerID& right) const;
	bool operator < (const PlayerID& right) const;
};

struct Packet
{
	PlayerIndex playerIndex;
	PlayerID playerId;
	unsigned int length;
	unsigned int bitSize;
	unsigned char* data;
	bool deleteData;
};

struct RPCParameters
{
	unsigned char* input;
	unsigned int numberOfBitsOfData;
	PlayerID sender;
	void* recipient;
	BitStream* replyToSender;
};

struct RakNetStatisticsStruct
{
	unsigned messageSendBuffer[NUMBER_OF_PRIORITIES];
	unsigned messagesSent[NUMBER_OF_PRIORITIES];
	unsigned messageDataBitsSent[NUMBER_OF_PRIORITIES];
	unsigned messageTotalBitsSent[NUMBER_OF_PRIORITIES];
	unsigned packetsContainingOnlyAcknowlegements;
	unsigned acknowlegementsSent;
	unsigned acknowlegementsPending;
	unsigned acknowlegementBitsSent;
	unsigned packetsContainingOnlyAcknowlegementsAndResends;

	unsigned messageResends;
	unsigned messageDataBitsResent;
	unsigned messagesTotalBitsResent;
	unsigned messagesOnResendQueue;

	unsigned numberOfUnsplitMessages;
	unsigned numberOfSplitMessages;
	unsigned totalSplits;

	unsigned packetsSent;

	unsigned encryptionBitsSent;
	unsigned totalBitsSent;

	unsigned sequencedMessagesOutOfOrder;
	unsigned sequencedMessagesInOrder;

	unsigned orderedMessagesOutOfOrder;
	unsigned orderedMessagesInOrder;

	unsigned packetsReceived;
	unsigned packetsWithBadCRCReceived;
	unsigned bitsReceived;
	unsigned bitsWithBadCRCReceived;
	unsigned acknowlegementsReceived;
	unsigned duplicateAcknowlegementsReceived;
	unsigned messagesReceived;
	unsigned invalidMessagesReceived;
	unsigned duplicateMessagesReceived;
	unsigned messagesWaitingForReassembly;
	unsigned internalOutputQueueSize;
	double bitsPerSecond;
	RakNetTime connectionStartTime;
};

struct NetworkID
{
	bool peerToPeer;
	PlayerID playerId;
	unsigned short localSystemId;
};

struct RPCNode
{
	uint8_t uniqueIdentifier;
	void(*staticFunctionPointer) (RPCParameters* rpcParms);
};

#pragma pack(pop)

class RakClientInterface
{
public:
	virtual ~RakClientInterface() {};
	virtual bool Connect(const char* host, unsigned short serverPort, unsigned short clientPort, unsigned int depreciated, int threadSleepTimer);
	virtual void Disconnect(unsigned int blockDuration, unsigned char orderingChannel = 0);
	virtual void InitializeSecurity(const char* privKeyP, const char* privKeyQ);
	virtual void SetPassword(const char* _password);
	virtual bool HasPassword(void) const;
	virtual bool Send(const char* data, const int length, PacketPriority priority, PacketReliability reliability, char orderingChannel);
	virtual bool Send(BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel);
	virtual Packet* Receive(void);
	virtual void DeallocatePacket(Packet* packet);
	virtual void PingServer(void);
	virtual void PingServer(const char* host, unsigned short serverPort, unsigned short clientPort, bool onlyReplyOnAcceptingConnections);
	virtual int GetAveragePing(void);
	virtual int GetLastPing(void) const;
	virtual int GetLowestPing(void) const;
	virtual int GetPlayerPing(const PlayerID playerId);
	virtual void StartOccasionalPing(void);
	virtual void StopOccasionalPing(void);
	virtual bool IsConnected(void) const;
	virtual unsigned int GetSynchronizedRandomInteger(void) const;
	virtual bool GenerateCompressionLayer(unsigned int inputFrequencyTable[256], bool inputLayer);
	virtual bool DeleteCompressionLayer(bool inputLayer);
	virtual void RegisterAsRemoteProcedureCall(int* uniqueID, void(*functionPointer) (RPCParameters* rpcParms));
	virtual void RegisterClassMemberRPC(int* uniqueID, void* functionPointer);
	virtual void UnregisterAsRemoteProcedureCall(int* uniqueID);
	virtual bool RPC(int* uniqueID, const char* data, unsigned int bitLength, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp);
	virtual bool RPC(int* uniqueID, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp);
	virtual bool RPC_(int* uniqueID, BitStream* bitStream, PacketPriority priority, PacketReliability reliability, char orderingChannel, bool shiftTimestamp, NetworkID networkID);
	virtual void SetTrackFrequencyTable(bool b);
	virtual bool GetSendFrequencyTable(unsigned int outputFrequencyTable[256]);
	virtual float GetCompressionRatio(void) const;
	virtual float GetDecompressionRatio(void) const;
	virtual void AttachPlugin(void* messageHandler);
	virtual void DetachPlugin(void* messageHandler);
	virtual BitStream* GetStaticServerData(void);
	virtual void SetStaticServerData(const char* data, const int length);
	virtual BitStream* GetStaticClientData(const PlayerID playerId);
	virtual void SetStaticClientData(const PlayerID playerId, const char* data, const int length);
	virtual void SendStaticClientDataToServer(void);
	virtual PlayerID GetServerID(void) const;
	virtual PlayerID GetPlayerID(void) const;
	virtual PlayerID GetInternalID(void) const;
	virtual const char* PlayerIDToDottedIP(const PlayerID playerId) const;
	virtual void PushBackPacket(Packet* packet, bool pushAtHead);
	virtual void SetRouterInterface(void* routerInterface);
	virtual void RemoveRouterInterface(void* routerInterface);
	virtual void SetTimeoutTime(RakNetTime timeMS);
	virtual bool SetMTUSize(int size);
	virtual int GetMTUSize(void) const;
	virtual void AllowConnectionResponseIPMigration(bool allow);
	virtual void AdvertiseSystem(const char* host, unsigned short remotePort, const char* data, int dataLength);
	virtual RakNetStatisticsStruct* const GetStatistics(void);
	virtual void ApplyNetworkSimulator(double maxSendBPS, unsigned short minExtraPing, unsigned short extraPingVariance);
	virtual bool IsNetworkSimulatorActive(void);
	virtual PlayerIndex GetPlayerIndex(void);
};