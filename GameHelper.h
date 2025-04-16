#pragma once
#include "framework.h"
#include <regex>

namespace GameHelper
{
	template <typename T>
	T* FindObject(string ObjectName, UClass* ObjectClass = nullptr)
	{
		static UObject* (*oStaticFindObject)(UClass * Class, void* InOuter, const wchar_t* Name, bool ExactClass) = decltype(oStaticFindObject)(Memory::GetAddress(LOffsets::StaticFindObject));
		return (T*)oStaticFindObject(ObjectClass, nullptr, wstring(ObjectName.begin(), ObjectName.end()).c_str(), false);
	}

	template <typename T>
	T* LoadObject(string ObjectName, UClass* ObjectClass = nullptr)
	{
		static UObject* (*oStaticLoadObject)(UObject*, UObject*, const TCHAR*, const TCHAR*, uint32_t, void*, bool) = decltype(oStaticLoadObject)(LOffsets::StaticLoadObject);
		return reinterpret_cast<T*>(oStaticLoadObject(ObjectClass, 0, wstring(ObjectName.begin(), ObjectName.end()).c_str(), nullptr, 0, nullptr, false));
	}

	TArray<AActor*> GetAllActorsOfClass(UClass* ActorClass)
	{
		TArray<AActor*> OutActors;
		UGameplayStatics::GetAllActorsOfClass(UWorld::GetWorld(), ActorClass, &OutActors);
		return OutActors;
	}

    bool IsValidLowLevel(UObject* Object)
    {
        if (!Object || IsBadReadPtr(Object, 8))
            return false;

        if (!Object->Class || IsBadReadPtr(Object->Class, 8))
            return false;

        if (UObject::GObjects->GetByIndex(Object->Index) != Object)
            return false;

        return true;
    }

	bool KickPlayer(AFortPlayerController* PlayerController, FString Reason)
	{
		if (!PlayerController)
		{
			LogWarning("AntiCheat::KickPlayer: PlayerController is NULL, aborting.");
			return false;
		}

		AFortPawn* Pawn = reinterpret_cast<AFortPawn*>(PlayerController->Pawn);
		if (!Pawn)
		{
			LogWarning("AntiCheat::KickPlayer: Pawn is NULL, aborting.");
			return false;
		}

		auto PlayerState = reinterpret_cast<AFortPlayerState*>(PlayerController->PlayerState);
		if (!PlayerState)
			LogWarning("AntiCheat::KickPlayer: PlayerState is NULL.");

		FText KickReason = UKismetTextLibrary::Conv_StringToText(Reason);
		static FName RemovedTagName = UKismetStringLibrary::Conv_StringToName(L"Cheat.RemovedFromGame");

		FGameplayTag Tag{};
		Tag.TagName = RemovedTagName;

		Pawn->ForceKill(Tag, PlayerController, PlayerController);

		PlayerController->ClientWasKicked(KickReason);
		PlayerController->ServerReturnToMainMenu();

		PlayerController->K2_DestroyActor();

		return true;
	}

	string GetAccountId(AFortPlayerControllerAthena* PlayerController)
	{
		UFortMcpProfileAthena* MCPProfile = PlayerController->AthenaProfile;
		if (*(DWORD*)(__int64(MCPProfile) + 216))
		{
			auto v7 = *(const wchar_t**)(__int64(MCPProfile) + 208);

			string PlayerName = "NULL PLAYERSTATE";

			auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
			if (PlayerState)
				PlayerName = PlayerState->GetPlayerName().ToString();

			wstring ws(v7);
			string str(ws.begin(), ws.end());

			std::regex accountIdRegex(R"(accountId=([^ ]+))");
			std::smatch match;

			if (std::regex_search(str, match, accountIdRegex))
			{
				string accountId = match[1];
				//LogInfo("Helpers::GetAccountId: ({}) AccountId={}", PlayerName, accountId);
				return accountId;
			}
		}

		LogWarning("GameHelper::GetAccountId: Could not get AccountId, should kick..?");
		return "";
	}

	AFortPlayerControllerAthena* GetPlayerByAccountID(string AccountId)
	{
		UNetDriver* NetDriver = UWorld::GetWorld()->NetDriver;
		for (int i = 0; i < NetDriver->ClientConnections.Num(); i++)
		{
			UNetConnection* ClientConnection = NetDriver->ClientConnections[i];
			if (!ClientConnection)
				continue;

			AFortPlayerControllerAthena* PlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(ClientConnection->PlayerController);
			if (!PlayerController)
				continue;

			string AccountID = GetAccountId(PlayerController);
			if (AccountID.empty())
				continue;

			if (AccountID == AccountId)
				return PlayerController;
		}

		LogWarning("GameHelper::GetPlayerByAccountID: Failed to find player with account id ({})", AccountId);
		return nullptr;
	}

	AFortPickupAthena* SpawnPickup(UFortItemDefinition* ItemDefinition, int OverrideCount, int LoadedAmmo, FVector Loc, bool bTossedFromContainer = false, AFortPawn* PawnWhoDroppedPickup = nullptr)
	{
		if (!ItemDefinition)
		{
			LogError("GameHelper::SpawnPickup: ItemDefinition is NULL.");
			return nullptr;
		}

		if (OverrideCount > 1000)
		{
			LogError("GameHelper::SpawnPickup: OverrideCount Exceeds 1000.");
			return nullptr;
		}

		auto SpawnedPickup = Spawner::SpawnActor<AFortPickupAthena>(AFortPickupAthena::StaticClass(), Loc, {});
		if (!SpawnedPickup)
		{
			LogError("GameHelper::SpawnPickup: SpawnedPickup failed to spawn.");
			return nullptr;
		}

		SpawnedPickup->bRandomRotation = true;

		//LogInfo("LootManager::SpawnPickup: ItemDefinition: {}  OverrideCount: {}  LoadedAmmo {}", ItemDefinition->GetName(), OverrideCount, LoadedAmmo);
		FFortItemEntry* PickupEntry = &SpawnedPickup->PrimaryPickupItemEntry;
		PickupEntry->ItemDefinition = ItemDefinition;
		PickupEntry->Count = OverrideCount;
		PickupEntry->LoadedAmmo = LoadedAmmo;
		PickupEntry->ReplicationKey++;
		SpawnedPickup->OnRep_PrimaryPickupItemEntry();

		SpawnedPickup->bTossed = true;
		SpawnedPickup->TossPickup(Loc, nullptr, 1, true);

		SpawnedPickup->SetReplicateMovement(true);
		SpawnedPickup->MovementComponent = reinterpret_cast<UProjectileMovementComponent*>(UGameplayStatics::SpawnObject(UProjectileMovementComponent::StaticClass(), SpawnedPickup));

		SpawnedPickup->PawnWhoDroppedPickup = PawnWhoDroppedPickup;

		SpawnedPickup->bTossedFromContainer = bTossedFromContainer;
		SpawnedPickup->OnRep_TossedFromContainer();

		return SpawnedPickup;
	}

	AFortPickupAthena* SpawnPickup(FFortItemEntry* ItemEntry, FVector Loc, bool bTossedFromContainer = false, AFortPawn* PawnWhoDroppedPickup = nullptr)
	{
		auto SpawnedPickup = Spawner::SpawnActor<AFortPickupAthena>(AFortPickupAthena::StaticClass(), Loc);
		if (!SpawnedPickup)
		{
			LogError("GameHelper::SpawnPickup: SpawnedPickup failed to spawn.");
			return nullptr;
		}

		SpawnedPickup->bRandomRotation = true;
		SpawnedPickup->PrimaryPickupItemEntry = *ItemEntry;

		SpawnedPickup->bTossed = true;
		SpawnedPickup->TossPickup(Loc, nullptr, 1, true);

		SpawnedPickup->SetReplicateMovement(true);
		SpawnedPickup->MovementComponent = reinterpret_cast<UProjectileMovementComponent*>(UGameplayStatics::SpawnObject(UProjectileMovementComponent::StaticClass(), SpawnedPickup));

		SpawnedPickup->PawnWhoDroppedPickup = PawnWhoDroppedPickup;

		SpawnedPickup->bTossedFromContainer = bTossedFromContainer;
		SpawnedPickup->OnRep_TossedFromContainer();

		return SpawnedPickup;
	}

	uint8 ToDeathCause(FGameplayTagContainer Tags, bool bWasDBNO)
	{
		static uint8 (*oToDeathCause)(FGameplayTagContainer TagContainer, char bWasDBNO) = decltype(oToDeathCause)(Memory::GetAddress(0xa835b0));
		return oToDeathCause(Tags, bWasDBNO);
	}

	void DestroyVendingMachines()
	{
		auto VendingMachineClass = GameHelper::FindObject<UClass>("/Game/Athena/Items/Gameplay/VendingMachine/B_Athena_VendingMachine.B_Athena_VendingMachine_C");
		if (VendingMachineClass)
		{
			auto VendingMachines = GameHelper::GetAllActorsOfClass(VendingMachineClass);
			if (VendingMachines.IsValid())
			{
				for (int i = 0; i < VendingMachines.Num(); i++)
				{
					VendingMachines[i]->K2_DestroyActor();
				}
			}
		}
	}

	void DestroyDebugChests()
	{
		auto DebugChestClass = GameHelper::FindObject<UClass>("/Game/Building/ActorBlueprints/Containers/Tiered_Chest_3_Child.Tiered_Chest_3_Child_C");
		if (DebugChestClass)
		{
			auto DebugChests = GameHelper::GetAllActorsOfClass(DebugChestClass);
			if (DebugChests.IsValid())
			{
				for (int i = 0; i < DebugChests.Num(); i++)
				{
					DebugChests[i]->K2_DestroyActor();
				}
			}
		}
	}

	void OverrideSupplyDropClass(UClass* OverrideSupplyDropClass = GameHelper::LoadObject<UClass>("/Game/Athena/SupplyDrops/AthenaSupplyDrop.AthenaSupplyDrop_C", UBlueprintGeneratedClass::StaticClass()))
	{
		AFortAthenaMapInfo* MapInfo = Globals::GetGameState()->MapInfo;

		if (MapInfo->SupplyDropInfoList.Num() != 0)
		{
			auto FirstSupplyDropInfo = MapInfo->SupplyDropInfoList[0];
			FirstSupplyDropInfo->SupplyDropClass = OverrideSupplyDropClass;
		}
	}
}