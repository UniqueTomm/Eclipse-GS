#pragma once
#include "framework.h"

namespace ServerManager
{
	static UNetDriver* NetDriver = nullptr;
	static bool bIsListening = false;
	static int Port = 7777;
}

namespace Server
{
	static UNetDriver* (*CreateNetDriver)(UEngine* a1, UWorld* a2, FName a3) = decltype(CreateNetDriver)(Memory::GetAddress(LOffsets::CreateNetDriver));
	static bool (*InitListen)(UNetDriver* a1, void* InNotify, FURL& LocalURL, bool bReuseAddressAndPort, FString& Error) = decltype(InitListen)(Memory::GetAddress(LOffsets::InitListen));
	static void (*SetWorld)(UNetDriver* a1, UWorld* a2) = decltype(SetWorld)(Memory::GetAddress(LOffsets::SetWorld));
	static void (*ReplicateActors)(UReplicationDriver* a1);

	static __int64 (*UWorld_GetNetMode)(UWorld* a1);
	static __int64 (*AActor_GetNetMode)(AActor* a1);
	static void (*oTickFlush)(UNetDriver* a1);
	static char (*KickPlayer)(__int64 a1, __int64 a2, __int64 a3);
	static char (*ValidationFailure)(__int64 a1, __int64 a2);
	static __int64 (*NoReservation)(__int64 a1, __int64 a2, char a3, __int64 a4);

	void Listen()
	{
		if (ServerManager::bIsListening)
			return;

		UWorld* World = UWorld::GetWorld();

		UNetDriver* NetDriver = CreateNetDriver(UEngine::GetEngine(), World, FName(282));
		if (!NetDriver)
		{
			LogError("Failed to create NetDriver.");
			return;
		}
		else
			LogInfo("Successfully created NetDriver: {}", NetDriver->GetFullName());

		ServerManager::NetDriver = NetDriver;

		World->NetDriver = NetDriver;
		NetDriver->World = World;
		NetDriver->NetDriverName = FName(282);

		FString Error;
		FURL URL = FURL();
		URL.Port = ServerManager::Port;

		InitListen(NetDriver, World, URL, false, Error);
		SetWorld(NetDriver, World);

		World->LevelCollections[0].NetDriver = NetDriver;
		World->LevelCollections[1].NetDriver = NetDriver;
		
		auto vft = *(void***)NetDriver->ReplicationDriver;
		ReplicateActors = decltype(ReplicateActors)(vft[0x53]);

		ServerManager::bIsListening = true;
		LogInfo("Server::Listen: Server Listening on port {}", ServerManager::Port);
		LogInfo("Update Server on Matchmaker!");
	}

	void hkTickFlush(UNetDriver* a1)
	{
		if (!a1)
			return;

		if (a1->ReplicationDriver && a1->ClientConnections.Num() > 0 && !a1->ClientConnections[0]->InternalAck)
			Server::ReplicateActors(a1->ReplicationDriver);

		if (GetAsyncKeyState(VK_F7) & 0x01)
		{
			if (!Globals::bStartedAircraft)
			{
				LogInfo("Game: Bus was force started.");
				Globals::GetGameState()->WarmupCountdownEndTime = 0.f;
				Globals::GetGameState()->WarmupCountdownStartTime = 0.f;
			}
		}

		return oTickFlush(a1);
	}

	__int64 UWorld_GetNetModeHook(UWorld* a1)
	{
		return 1;
	}

	__int64 AActor_GetNetModeHook(AActor* a1)
	{
		return 1;
	}

	char hkKickPlayer(__int64 a1, __int64 a2, __int64 a3)
	{
		return 1;
	}

	__int64 hkNoReservation(__int64 a1, __int64 a2, char a3, __int64 a4)
	{
		return 0;
	}

	__int64 hkValidationFailure(__int64* a1, __int64 a2)
	{
		return 0;
	}

	__int64 (*oCollectGarbage)(__int64);
	__int64 hkCollectGarbage(__int64)
	{
		return 0;
	}

	static bool bMcp = false;
	__int64 hkNoMCP()
	{
		return !bMcp;
	}

	void (*oDispatchRequest)(__int64 a1, __int64* a2, int a3);
	void hkDispatchRequest(__int64 a1, __int64* a2, int a3)
	{
		*(int*)(__int64(a2) + 0x60) = 3;
		return oDispatchRequest(a1, a2, 3);
	}

	float hkGetMaxTickRate()
	{
		return 30.f;
	}

	void (*oOnQueryProfileComplete)(UFortMcpProfileAthena* MCPProfile, __int64 a2, __int64 a3);
	void hkOnQueryProfileComplete(UFortMcpProfileAthena* MCPProfile, __int64 a2, __int64 a3)
	{
		LogInfo("Server::OnQueryProfileComplete: a2: 0x{:x}", a2);
		LogInfo("Server::OnQueryProfileComplete: a3: 0x{:x}", a3);

		LogInfo("MCPProfile: {}", MCPProfile->GetFullName());

		auto v20 = *(DWORD*)(a2 + 4); // HTTP ?

		if (v20 == 0)
			LogInfo("v20 returned 0."); // ig we can detect like this too?

		if (*(DWORD*)(__int64(MCPProfile) + 216))
		{
			auto v7 = *(const wchar_t**)(__int64(MCPProfile) + 208);

			wstring ws(v7);
			string str(ws.begin(), ws.end());
			LogInfo("v7: {}", str); // account ID
			LogInfo("AccountId: {}", str); // account ID
			LogInfo("MCPProfile:ProfileId: {}", MCPProfile->ProfileId.ToString());
		}

		LogInfo("v20: {}", v20);

		return oOnQueryProfileComplete(MCPProfile, a2, a3);
	}

	void Initialize()
	{
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::TickFlush), hkTickFlush, (void**)&oTickFlush);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::KickPlayer), hkKickPlayer);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::CollectGarbage), hkCollectGarbage);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::WorldGetNetMode), UWorld_GetNetModeHook);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::DispatchRequest), hkDispatchRequest, (void**)&oDispatchRequest);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::GetMaxTickRate), hkGetMaxTickRate);
		HookingManager::CreateHook(Memory::GetAddress(0x300905f), hkNoMCP);


		HookingManager::CreateHook(Memory::GetAddress(0x7ee1C0), hkOnQueryProfileComplete, (void**)&oOnQueryProfileComplete);
	}
}

