#pragma once
#include "framework.h"

namespace PlayerController
{
	static void* (*oApplyCharacterCustomization)(void* a1, void* a2) = decltype(oApplyCharacterCustomization)(Memory::GetAddress(LOffsets::ApplyCharacterCustomization));
	void hkServerAcknowledgePossession(AFortPlayerControllerAthena* PlayerController, APawn* Pawn)
	{
		//	LogInfo("ServerAcknowledgePossession: Called.");
		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
		auto FortPawn = reinterpret_cast<APlayerPawn_Athena_C*>(Pawn);
		PlayerController->AcknowledgedPawn = FortPawn;
		if (PlayerState && FortPawn)
		{
			auto& CustomizationLoadout = PlayerController->CustomizationLoadout;

			if (CustomizationLoadout.Character)
			{
				if (CustomizationLoadout.Character->HeroDefinition)
				{
					FortPawn->CustomizationLoadout = CustomizationLoadout;
					FortPawn->OnRep_CustomizationLoadout();

					PlayerState->HeroType = CustomizationLoadout.Character->HeroDefinition;
					PlayerState->OnRep_HeroType();

					oApplyCharacterCustomization(PlayerState, FortPawn);
				}
			}
		}
		else
			LogError("ServerAcknowledgePossession: Pawn or PlayerState is null.");
	}


	void (*oServerReadyToStartMatch)(AFortPlayerController* PlayerController);
	void hkServerReadyToStartMatch(AFortPlayerControllerAthena* PlayerController)
	{
		if (!PlayerController)
			return oServerReadyToStartMatch(PlayerController);

		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
		if (!PlayerState)
			return oServerReadyToStartMatch(PlayerController);

		Abilities::ApplyAbilities(PlayerState);

		if (!Globals::bAlreadySpawned)
		{
			Globals::bAlreadySpawned = true;
			LootManager::SpawnFloorLoot();
			BuildingActor::Initialize();

			//GameHelper::OverrideSupplyDropClass();
			//GameHelper::DestroyVendingMachines();
			//GameHelper::DestroyDebugChests();
		}

		PlayerController->MatchReport = (UAthenaPlayerMatchReport*)UGameplayStatics::SpawnObject(UAthenaPlayerMatchReport::StaticClass(), PlayerController);
		PlayerController->RecordMatchStats();
		PlayerController->RecordTeamStats();

		LogInfo("PlayerState->TeamIndex: {}", (int)PlayerState->TeamIndex);

		PlayerState->SquadId = (uint8)PlayerState->TeamIndex - 2;
		PlayerState->WorldPlayerId = PlayerState->PlayerID;
		PlayerState->OnRep_PlayerTeam();
		PlayerState->OnRep_SquadId();

		return oServerReadyToStartMatch(PlayerController);
	}

	void (*oServerLoadingScreenDropped)(AFortPlayerControllerAthena* PlayerController);
	void hkServerLoadingScreenDropped(AFortPlayerControllerAthena* PlayerController)
	{
		if (!PlayerController)
		{
			LogError("PlayerController::ServerLoadingScreenDropped: PlayerController is NULL.");
			return oServerLoadingScreenDropped(PlayerController);
		}

		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
		if (!PlayerState)
		{
			LogError("PlayerController::ServerLoadingScreenDropped: PlayerState is NULL.");
			return oServerLoadingScreenDropped(PlayerController);
		}

		Inventory::SetupForPlayer(PlayerController);

		Globals::bPlayerJoined = true;

		return oServerLoadingScreenDropped(PlayerController);
	}

	void hkServerExecuteInventoryItem(AFortPlayerControllerAthena* PlayerController, FGuid ItemGuid)
	{
		if (!PlayerController)
		{
			LogError("PlayerController::ServerExecuteInventoryItem: PlayerController is NULL.");
			return;
		}

		auto Pawn = reinterpret_cast<AFortPlayerPawn*>(PlayerController->Pawn);
		if (!Pawn)
		{
			LogError("PlayerController::ServerExecuteInventoryItem: Pawn is NULL.");
			return;
		}

		FFortItemEntry* FoundReplicatedEntry = Inventory::FindItem(PlayerController, ItemGuid);

		if (FoundReplicatedEntry)
		{
			auto ItemDefinition = reinterpret_cast<UFortWeaponItemDefinition*>(FoundReplicatedEntry->ItemDefinition);
			if (ItemDefinition->IsA(UFortTrapItemDefinition::StaticClass()))
			{
				if (auto DecoDefinition = reinterpret_cast<UFortDecoItemDefinition*>(ItemDefinition))
				{
					Pawn->PickUpActor(nullptr, DecoDefinition);
					Pawn->CurrentWeapon->ItemEntryGuid = ItemGuid;

					if (auto ContextTrapTool = reinterpret_cast<AFortDecoTool_ContextTrap*>(Pawn->CurrentWeapon))
					{
						ContextTrapTool->ContextTrapItemDefinition = reinterpret_cast<UFortContextTrapItemDefinition*>(ItemDefinition);
					}

					ItemDefinition = nullptr;
				}
			}

			if (!ItemDefinition)
				return;

			Pawn->EquipWeaponDefinition(ItemDefinition, ItemGuid);
		}
	}

	bool(__fastcall* CantBuild)(UWorld*, UObject*, FVector, FRotator, char, void*, char*) = decltype(CantBuild)(Memory::GetAddress(LOffsets::CantBuild));
	void hkServerCreateBuildingActor(AFortPlayerControllerAthena* PlayerController, FBuildingClassData& BuildingClassData, FVector_NetQuantize10& BuildLoc, FRotator& BuildRot, bool bMirrored)
	{
		auto Class = BuildingClassData.BuildingClass.Get();
		TArray<AActor*> BuildingActorsToDestroy;
		char Result;

		if (!CantBuild(UWorld::GetWorld(), Class, BuildLoc, BuildRot, bMirrored, &BuildingActorsToDestroy, &Result))
		{
			for (int i = 0; i < BuildingActorsToDestroy.Num(); i++)
			{
				BuildingActorsToDestroy[i]->K2_DestroyActor();
			}

			FTransform Transform{};
			Transform.Translation = BuildLoc;
			Transform.Rotation = Spawner::FRotToQuat(BuildRot);
			Transform.Scale3D = { 1, 1, 1 };

			if (auto NewBuilding = Spawner::SpawnActor<ABuildingSMActor>(Class, Transform))
			{
				NewBuilding->bPlayerPlaced = true;
				NewBuilding->SetOwner(PlayerController);
				NewBuilding->Team = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState)->TeamIndex;
				NewBuilding->SetMirrored(bMirrored);
				NewBuilding->OnRep_Team();
				NewBuilding->InitializeKismetSpawnedBuildingActor(NewBuilding, PlayerController);

				if (NewBuilding->ResourceType == EFortResourceType::Wood)
					PlayerController->MatchReport->Stats.UsedWood += 10;
				else if (NewBuilding->ResourceType == EFortResourceType::Stone)
					PlayerController->MatchReport->Stats.UsedStone += 10;
				else if (NewBuilding->ResourceType == EFortResourceType::Metal)
					PlayerController->MatchReport->Stats.UsedMetal += 10;

				PlayerController->MatchReport->Stats.MaterialsUsed += 10;

				if (!PlayerController->bBuildFree)
					Inventory::RemoveItem(PlayerController, UFortKismetLibrary::K2_GetResourceItemDefinition(NewBuilding->ResourceType), 10);
			}
		}

		BuildingActorsToDestroy.Free();
	}

	void hkServerBeginEditingBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit)
	{
		auto Pawn = reinterpret_cast<AFortPlayerPawnAthena*>(PlayerController->Pawn);
		if (Pawn && BuildingActorToEdit)
		{
			static auto EditToolDef = GameHelper::FindObject<UFortItemDefinition>("/Game/Items/Weapons/BuildingTools/EditTool.EditTool");
			AFortInventory* WorldInventory = PlayerController->WorldInventory;
			FFortItemEntry* Entry = Inventory::FindItem(PlayerController, EditToolDef);
			PlayerController->ServerExecuteInventoryItem(Entry->ItemGuid);

			auto EditTool = reinterpret_cast<AFortWeap_EditingTool*>(Pawn->CurrentWeapon);
			EditTool->EditActor = BuildingActorToEdit;
			EditTool->OnRep_EditActor();
			BuildingActorToEdit->EditingPlayer = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
			BuildingActorToEdit->OnRep_EditingPlayer();
		}
	}

	static ABuildingSMActor* (*oBuildingSMActorReplaceBuildingActor)(ABuildingSMActor*, __int64, UClass*, int, int, uint8_t, AFortPlayerController*) = decltype(oBuildingSMActorReplaceBuildingActor)(Memory::GetAddress(0xaaedd0));
	void (*oServerEditBuildingActor)(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit, UClass* NewBuildingClass, uint8 RotationIterations, bool bMirrored);
	void hkServerEditBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToEdit, UClass* NewBuildingClass, uint8 RotationIterations, bool bMirrored)
	{
		if (!PlayerController)
		{
			LogError("PlayerController::ServerEditBuildingActor: PlayerController is NULL.");
			return oServerEditBuildingActor(PlayerController, BuildingActorToEdit, NewBuildingClass, RotationIterations, bMirrored);
		}

		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
		if (!PlayerState)
		{
			LogError("PlayerController::ServerEditBuildingActor: PlayerState is NULL.");
			return oServerEditBuildingActor(PlayerController, BuildingActorToEdit, NewBuildingClass, RotationIterations, bMirrored);
		}

		if (BuildingActorToEdit && NewBuildingClass)
		{
			FVector BuildLocation = BuildingActorToEdit->K2_GetActorLocation();

			float HealthPercent = BuildingActorToEdit->GetHealthPercent();
			if (auto BuildingActor = oBuildingSMActorReplaceBuildingActor(BuildingActorToEdit, 1, NewBuildingClass, BuildingActorToEdit->GetCurrentBuildingLevel(), RotationIterations, bMirrored, PlayerController))
			{
				BuildingActor->bPlayerPlaced = true;
			}
		}

		return oServerEditBuildingActor(PlayerController, BuildingActorToEdit, NewBuildingClass, RotationIterations, bMirrored);
	}

	void hkServerEndEditingBuildingActor(AFortPlayerController* PlayerController, ABuildingSMActor* BuildingActorToStopEditing)
	{
		if (PlayerController && PlayerController->Pawn && BuildingActorToStopEditing)
		{
			auto Pawn = reinterpret_cast<APlayerPawn_Athena_C*>(PlayerController->Pawn);

			BuildingActorToStopEditing->EditingPlayer = nullptr;
			BuildingActorToStopEditing->OnRep_EditingPlayer();

			AFortWeap_EditingTool* EditTool = reinterpret_cast<AFortWeap_EditingTool*>(Pawn->CurrentWeapon);
			if (EditTool)
			{
				EditTool->bEditConfirmed = true;
				EditTool->EditActor = nullptr;
				EditTool->OnRep_EditActor();
			}
		}
	}

	void hkServerRepairBuildingActor(AFortPlayerControllerAthena* PlayerController, ABuildingSMActor* BuildingActorToRepair)
	{
		if (!PlayerController || !BuildingActorToRepair || BuildingActorToRepair->EditingPlayer)
			return;

		const float BuildingCost = 10.0f;
		const float RepairCostMultiplier = 0.75f;

		float BuildingHealthPercent = BuildingActorToRepair->GetHealthPercent();
		float HealthPercentLost = 1.0f - BuildingHealthPercent;

		float RepairCostUnrounded = (BuildingCost * HealthPercentLost) * RepairCostMultiplier;
		float RepairCost = max(floor(RepairCostUnrounded), 1.0f);

		auto ResourceItemDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(BuildingActorToRepair->ResourceType);

		if (!ResourceItemDefinition)
			return;

		if (BuildingActorToRepair->ResourceType == EFortResourceType::Wood)
			PlayerController->MatchReport->Stats.UsedWood += RepairCost;
		else if (BuildingActorToRepair->ResourceType == EFortResourceType::Stone)
			PlayerController->MatchReport->Stats.UsedStone += RepairCost;
		else if (BuildingActorToRepair->ResourceType == EFortResourceType::Metal)
			PlayerController->MatchReport->Stats.UsedMetal += RepairCost;

		PlayerController->MatchReport->Stats.MaterialsUsed += RepairCost;

		if (!PlayerController->bBuildFree)
			Inventory::RemoveItem(PlayerController, ResourceItemDefinition, RepairCost);

		BuildingActorToRepair->RepairBuilding(PlayerController, RepairCost);
	}

	void hkServerReturnToMainMenu(AFortPlayerControllerAthena* PlayerController)
	{
		if (!PlayerController)
			return;

		PlayerController->bIsDisconnecting = true;
		PlayerController->ClientTravel(L"Frontend", ETravelType::TRAVEL_Absolute, false, {});
	}

	void (*oGetPlayerViewPoint)(AFortPlayerController* PlayerController, FVector out_Location, FRotator out_Rotation);
	void hkGetPlayerViewPoint(AFortPlayerController* PlayerController, FVector& out_Location, FRotator& out_Rotation)
	{
		if (PlayerController->StateName == FName(322))
		{
			out_Location = PlayerController->LastSpectatorSyncLocation;
			out_Rotation = PlayerController->LastSpectatorSyncRotation;
		}
		else if (auto Pawn = PlayerController->Pawn)
		{
			out_Location = Pawn->K2_GetActorLocation();
			out_Rotation = PlayerController->GetControlRotation();
			return;
		}

		return oGetPlayerViewPoint(PlayerController, out_Location, out_Rotation);
	}

	static void (*oRemoveFromAlivePlayers)(AFortGameModeAthena* GameMode, AFortPlayerController* PlayerController, APlayerState* PlayerState, APawn* FinisherPawn, UFortWeaponItemDefinition* FinishingWeapon, uint8_t DeathCause, char a7) = decltype(oRemoveFromAlivePlayers)(Memory::GetAddress(LOffsets::RemoveFromAlivePlayers));
	void (*oClientOnPawnDied)(AFortPlayerControllerZone*, FFortPlayerDeathReport);
	void hkClientOnPawnDied(AFortPlayerControllerAthena* PlayerController, FFortPlayerDeathReport DeathReport)
	{
		if (!PlayerController)
		{
			LogError("PlayerController::ClientOnPawnDied: PlayerController is NULL.");
			return;
		}

		auto DeadPawn = reinterpret_cast<AFortPlayerPawnAthena*>(PlayerController->Pawn);
		auto DeadPlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
		auto KillerPlayerState = reinterpret_cast<AFortPlayerStateAthena*>(DeathReport.KillerPlayerState);
		auto KillerPawn = reinterpret_cast<AFortPlayerPawnAthena*>(DeathReport.KillerPawn);
		if (!DeadPawn || !DeadPlayerState)
			return oClientOnPawnDied(PlayerController, DeathReport);

		if (KillerPawn && KillerPlayerState && KillerPlayerState != DeadPlayerState)
		{
			KillerPlayerState->KillScore++;
			KillerPlayerState->ClientReportKill(DeadPlayerState);
			KillerPlayerState->OnRep_Kills();

			auto KillerController = reinterpret_cast<AFortPlayerControllerAthena*>(KillerPawn->Controller);
			if (KillerController->MatchReport)
			{
				KillerController->MatchReport->Stats.Kills = KillerPlayerState->KillScore;
				FAthenaRewardResult EndOfMatchResults = KillerController->MatchReport->EndOfMatchResults;
				FAthenaAwardGroup AwardGroup{};
				AwardGroup.SeasonXp = 50;
				AwardGroup.RewardSource = ERewardSource::FirstKill;
				EndOfMatchResults.Rewards.Add(AwardGroup);
			}
		}

		LogInfo("Is DBNO: {}", DeadPawn->IsDBNO());

		FDeathInfo DeathData;
		DeathData.bDBNO = DeadPawn->IsDBNO();
		DeathData.DeathLocation = DeadPawn->K2_GetActorLocation();
		DeathData.Distance = DeathReport.KillerPawn ? DeathReport.KillerPawn->GetDistanceTo(DeadPawn) : 0;
		DeathData.DeathCause = (EDeathCause)GameHelper::ToDeathCause(DeathReport.Tags, false);
		DeathData.FinisherOrDowner = KillerPlayerState ? KillerPlayerState : DeadPlayerState;

		DeadPlayerState->DeathInfo = DeathData;
		DeadPlayerState->OnRep_DeathInfo();

		if (DeadPawn->IsDBNO())
		{
			if (KillerPawn)
				if (auto KillerController = reinterpret_cast<AFortPlayerControllerAthena*>(KillerPawn->Controller))
					KillerController->MatchReport->Stats.Downs++;

			return oClientOnPawnDied(PlayerController, DeathReport);
		}

		UAthenaPlayerMatchReport* MatchReport = PlayerController->MatchReport;

		if (MatchReport)
		{
			FAthenaRewardResult EndOfMatchResults = PlayerController->MatchReport->EndOfMatchResults;

			if (DeadPlayerState->Place < 10)
			{
				FAthenaAwardGroup AwardGroup{};
				AwardGroup.SeasonXp = 300;
				AwardGroup.BookXp = 300;
				AwardGroup.Score = 300;
				AwardGroup.RewardSource = ERewardSource::Placement;
				EndOfMatchResults.Rewards.Add(AwardGroup);
			}

			if (DeadPlayerState->Place < 25)
			{
				FAthenaAwardGroup AwardGroup{};
				AwardGroup.SeasonXp = 200;
				AwardGroup.BookXp = 200;
				AwardGroup.Score = 200;
				AwardGroup.RewardSource = ERewardSource::Placement;
				EndOfMatchResults.Rewards.Add(AwardGroup);
			}

			for (int i = 0; i < EndOfMatchResults.Rewards.Num(); i++)
			{
				auto Reward = EndOfMatchResults.Rewards[i];
				EndOfMatchResults.TotalSeasonXpGained += Reward.SeasonXp;
				EndOfMatchResults.TotalBookXpGained += Reward.BookXp;
			}

			PlayerController->MatchReport->bHasRewards = true;
			PlayerController->ClientSendEndBattleRoyaleMatchForPlayer(true, EndOfMatchResults);

			MatchReport->Stats.SecondsAlive = DeadPlayerState->SecondsAlive;
			MatchReport->bHasStats = true;
			PlayerController->ClientSendMatchStatsForPlayer(MatchReport->Stats);

			MatchReport->TeamStats.Place = DeadPlayerState->Place;
			MatchReport->TeamStats.TotalPlayers = Globals::GetGameMode()->NumPlayers;
			MatchReport->bHasTeamStats = true;

			PlayerController->ClientSendTeamStatsForPlayer(MatchReport->TeamStats);
		}

		oClientOnPawnDied(PlayerController, DeathReport);

		AActor* DamageCauser = DeathReport.DamageCauser;
		UFortWeaponItemDefinition* KillerWeaponDef = nullptr;

		AFortInventory* WorldInventory = PlayerController->WorldInventory;
		if (WorldInventory)
		{
			auto& ReplicatedEntries = WorldInventory->Inventory.ReplicatedEntries;
			if (ReplicatedEntries.IsValid())
			{
				for (int i = 0; i < ReplicatedEntries.Num(); i++)
				{
					if (ReplicatedEntries.IsValidIndex(i))
					{
						if (auto ItemDefinition = reinterpret_cast<UFortWorldItemDefinition*>(ReplicatedEntries[i].ItemDefinition))
						{
							if (ItemDefinition->bCanBeDropped)
								GameHelper::SpawnPickup(ItemDefinition, ReplicatedEntries[i].Count, ReplicatedEntries[i].LoadedAmmo, DeadPawn->K2_GetActorLocation(), DeadPawn);
						}
					}
				}
			}
		}

		LogInfo("DamageCauser: {}", DamageCauser->GetName());

		if (DeathData.DeathCause != EDeathCause::Unspecified && DeathData.DeathCause != EDeathCause::FallDamage && DeathData.DeathCause != EDeathCause::OutsideSafeZone && DamageCauser)
		{
			if (DamageCauser->IsA(AFortProjectileBase::StaticClass()))
			{
				auto ProjectileBase = reinterpret_cast<AFortProjectileBase*>(DamageCauser);
				if (GameHelper::IsValidLowLevel(ProjectileBase->Owner))
				{
					auto Weapon = reinterpret_cast<AFortWeapon*>(ProjectileBase->Owner);
					if (Weapon->WeaponData)
						KillerWeaponDef = Weapon->WeaponData;
					else
						LogError("Weapon not valid.");
				}
			}
			else
			{

				if (auto Weapon = reinterpret_cast<AFortWeapon*>(DamageCauser))
				{
					KillerWeaponDef = Weapon->WeaponData;
				}
				else
					LogError("Weapon not valid.");
			}
		}

		oRemoveFromAlivePlayers(Globals::GetGameMode(), PlayerController, KillerPlayerState == DeadPlayerState ? nullptr : KillerPlayerState, KillerPawn, KillerWeaponDef, (int)DeathData.DeathCause, 0);
		PlayerController->bMarkedAlive = false;

		if (!Globals::GetGameMode()->bAllowSpectateAfterDeath)
			return oClientOnPawnDied(PlayerController, DeathReport);

		if (DeathReport.KillerPawn)
			PlayerController->PlayerToSpectateOnDeath = DeathReport.KillerPawn;

		auto& PlayerArray = Globals::GetGameState()->PlayerArray;
		if (!PlayerArray)
			return oClientOnPawnDied(PlayerController, DeathReport);

		for (int i = 0; i < PlayerArray.Num(); i++)
		{
			if (!PlayerArray.IsValidIndex(i))
				continue;

			auto CurrentPlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerArray[i]);
			if (!CurrentPlayerState)
				continue;

			auto CurrentPlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(CurrentPlayerState->Owner);
			if (!CurrentPlayerController)
				continue;

			if (CurrentPlayerController->bMarkedAlive)
				continue;

			if (GameHelper::IsValidLowLevel(CurrentPlayerState->SpectatingTarget))
			{
				auto SpecPC = reinterpret_cast<AFortPlayerControllerAthena*>(CurrentPlayerState->SpectatingTarget->Owner);
				if (GameHelper::IsValidLowLevel(SpecPC) && SpecPC->bMarkedAlive)
					continue;
			}

			if (auto SpectatingTarget = SpectatingManager::GetPlayerToSpectate(CurrentPlayerController))
			{
				Async::runAsync(2000, [CurrentPlayerController]() {
					CurrentPlayerController->SpectateOnDeath();
					});

				CurrentPlayerState->SpectatingTarget = reinterpret_cast<AFortPlayerStateAthena*>(SpectatingTarget);
				CurrentPlayerState->OnRep_SpectatingTarget();
			}
		}
	}

	void hkServerAttemptInventoryDrop(AFortPlayerControllerAthena* PlayerController, FGuid ItemGuid, int32 Count)
	{
		if (!PlayerController)
			return;

		auto Pawn = reinterpret_cast<APlayerPawn_Athena_C*>(PlayerController->Pawn);
		if (!Pawn)
		{
			LogError("PlayerController::ServerAttemptInventoryDrop: Pawn is NULL.");
			return;
		}

		AFortInventory* WorldInventory = PlayerController->WorldInventory;
		if (!WorldInventory)
		{
			LogError("PlayerController::ServerAttemptInventoryDrop: WorldInventory is NULL.");
			return;
		}

		FFortItemEntry* ReplicatedEntry = Inventory::FindItem(PlayerController, ItemGuid);

		if (!ReplicatedEntry || Count > ReplicatedEntry->Count)
			return;

		auto SpawnedPickup = GameHelper::SpawnPickup(ReplicatedEntry->ItemDefinition, Count, ReplicatedEntry->LoadedAmmo, Pawn->K2_GetActorLocation(), false, Pawn);
		if (!SpawnedPickup)
		{
			LogError("PlayerController::ServerAttemptInventoryDrop: Pick-Up failed to spawn.");
			return;
		}

		Inventory::RemoveItem(PlayerController, ReplicatedEntry->ItemGuid, Count);
	}

	void hkServerRemoveInventoryItem(AFortPlayerControllerAthena* PlayerController, FGuid ItemGuid, int32 Count, bool bForceRemoveFromQuickBars, bool bForceRemoval)
	{
		if (!PlayerController)
			return;

		FFortItemEntry* ItemEntry = Inventory::FindItem(PlayerController, ItemGuid);
		if (!ItemEntry)
			return;

		Inventory::RemoveItem(PlayerController, ItemGuid, Count);
	}

	void (*oEnterAircraft)(AFortPlayerControllerAthena* PlayerController, unsigned __int64 a2);
	void hkEnterAircraft(AFortPlayerControllerAthena* PlayerController, unsigned __int64 a2)
	{
		if (!PlayerController)
			return;

		Globals::bStartedAircraft = true;
		TArray<FFortItemEntry> ReplicatedEntries = PlayerController->WorldInventory->Inventory.ReplicatedEntries;
		for (int i = 0; i < ReplicatedEntries.Num(); i++)
		{
			FFortItemEntry Entry = ReplicatedEntries[i];
			if (reinterpret_cast<UFortWorldItemDefinition*>(Entry.ItemDefinition)->bCanBeDropped)
				Inventory::RemoveItem(PlayerController, Entry.ItemGuid);
		}

		return oEnterAircraft(PlayerController, a2);
	}

	void hkServerPlayEmoteItem(AFortPlayerController* PlayerController, UFortMontageItemDefinitionBase* EmoteAsset)
	{
		if (!PlayerController)
			return;

		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
		auto Pawn = reinterpret_cast<APlayerPawn_Athena_C*>(PlayerController->Pawn);

		if (!EmoteAsset || !PlayerState || !Pawn)
			return;


		UFortAbilitySystemComponent* AbilitySystemComponent = PlayerState->AbilitySystemComponent;

		UObject* AbilityToUse = nullptr;
		bool bShouldBeAbilityToUse = false;

		if (!AbilityToUse)
			AbilityToUse = UGAB_Emote_Generic_C::StaticClass()->DefaultObject;

		FGameplayAbilitySpec Spec{};
		Abilities::SpecConstructor(&Spec, AbilityToUse, 1, -1, EmoteAsset);
		Abilities::oGiveAbilityAndActivateOnce(AbilitySystemComponent, &Spec.Handle, Spec);
	}

	void (*oServerAttemptInteract)(AFortPlayerController* PlayerController, AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, ETInteractionType InteractType, UObject* OptionalObjectData);
	void hkServerAttemptInteract(AFortPlayerControllerAthena* PlayerController, AActor* ReceivingActor, UPrimitiveComponent* InteractComponent, ETInteractionType InteractType, UObject* OptionalObjectData)
	{
		if (!PlayerController || !ReceivingActor)
		{
			LogError("PlayerController::ServerAttemptInteract: Arg(s) is NULL.");
			return oServerAttemptInteract(PlayerController, ReceivingActor, InteractComponent, InteractType, OptionalObjectData);
		}

		auto Container = reinterpret_cast<ABuildingContainer*>(ReceivingActor);
		if (!Container)
		{
			LogError("PlayerController::ServerAttemptInteract: Container is NULL.");
			return oServerAttemptInteract(PlayerController, ReceivingActor, InteractComponent, InteractType, OptionalObjectData);
		}


		static UClass* PawnClass = APlayerPawn_Athena_C::StaticClass();
		static UClass* ChestClass = GameHelper::FindObject<UClass>("/Game/Building/ActorBlueprints/Containers/Tiered_Chest_6_Parent.Tiered_Chest_6_Parent_C");
		static UClass* AmmoBoxClass = GameHelper::FindObject<UClass>("/Game/Building/ActorBlueprints/Containers/Tiered_Short_Ammo_3_Parent.Tiered_Short_Ammo_3_Parent_C");
		static UClass* QuestInteracableClass = GameHelper::FindObject<UClass>("/Game/Athena/Items/QuestInteractables/Generic/Prop_QuestObject_Interactable_Parent.Prop_QuestObject_Interactable_Parent_C");

		FVector SpawnLoc = ReceivingActor->K2_GetActorLocation() + ReceivingActor->GetActorRightVector() * 70.f + FVector{ 0, 0, 50 };
		;
		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);

		if (ReceivingActor->IsA(QuestInteracableClass))
		{
			static UObjectProperty* QuestItemProperty = GameHelper::FindObject<UObjectProperty>("/Game/Athena/Items/QuestInteractables/Generic/Prop_QuestInteractable_Parent.Prop_QuestInteractable_Parent_C.QuestItem");

			static UNameProperty* QuestBackendObjectiveNameProperty = GameHelper::FindObject<UNameProperty>("/Game/Athena/Items/QuestInteractables/Generic/Prop_QuestInteractable_Parent.Prop_QuestInteractable_Parent_C.QuestBackendObjectiveName");

			if (QuestBackendObjectiveNameProperty && QuestItemProperty)
			{
				uintptr_t QuestBackendObjectiveNameOffset = QuestBackendObjectiveNameProperty->Offset;
				LogInfo("PlayerController::ServerAttemptInteract: QuestBackendObjectiveName Offset: 0x{:x}", QuestBackendObjectiveNameOffset);

				uintptr_t QuestItemOffset = QuestItemProperty->Offset;
				LogInfo("PlayerController::ServerAttemptInteract: QuestItem Offset: 0x{:x}", QuestItemOffset);

				FName QuestBackendObjectiveName = *reinterpret_cast<FName*>(__int64(ReceivingActor) + QuestBackendObjectiveNameOffset);
				UFortQuestItemDefinition* QuestItem = *reinterpret_cast<UFortQuestItemDefinition**>(__int64(ReceivingActor) + QuestItemOffset);

				LogInfo("PlayerController::ServerAttemptInteract: QuestBackendObjectiveName: {}", QuestBackendObjectiveName.ToString());
				LogInfo("PlayerController::ServerAttemptInteract: QuestItem: {}", QuestItem->GetFullName());

				UFortQuestManager* QuestManager = PlayerController->GetQuestManager(ESubGame::Athena);
				UFortQuestItem* Quest = QuestManager->GetQuestWithDefinition(QuestItem);

				if (!Quest->HasCompletedObjectiveWithName(QuestBackendObjectiveName))
				{
					LogInfo("PlayerController::ServerAttemptInteract: Objective with name '{}' has not been completed.", QuestBackendObjectiveName.ToString());
					Quests::ProgressQuest(PlayerController, QuestBackendObjectiveName, QuestItem);

					static UFunction* ParentQuestUpdatedFunction = GameHelper::FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/Generic/Prop_QuestInteractable_Parent.Prop_QuestInteractable_Parent_C.ParentQuestUpdated");

					static UFunction* PlaySuccessFXandSoundFunction = GameHelper::FindObject<UFunction>("/Game/Athena/Items/QuestInteractables/Generic/Prop_QuestInteractable_Parent.Prop_QuestInteractable_Parent_C.PlaySuccessFXandSound");

					ReceivingActor->ProcessEvent(ParentQuestUpdatedFunction, nullptr);
					ReceivingActor->ProcessEvent(PlaySuccessFXandSoundFunction, nullptr);
				}
				else LogInfo("PlayerController::ServerAttemptInteract: Quest Objective ({}) already completed.", QuestBackendObjectiveName.ToString());
			}
		}
		else if (ReceivingActor->IsA(PawnClass))
		{
			auto DBNOPawn = reinterpret_cast<APlayerPawn_Athena_C*>(ReceivingActor);
			DBNOPawn->ServerReviveFromDBNO(PlayerController);
		}
		else if (ReceivingActor->IsA(ChestClass))
		{
			string DisplayName = Container->DisplayName.ToString();
			LogInfo("PlayerController::ServerAttemptInteract: DestructionLootTierGroup: {}", Container->DestructionLootTierGroup.ToString());
			LogInfo("PlayerController::ServerAttemptInteract: SearchLootTierGroup: {}", Container->SearchLootTierGroup.ToString());
			vector<LootManager::LootDrop> LootDrops = LootManager::PickLootDrops(LootManager::RedirectLootTierGroup(Container->SearchLootTierGroup), Globals::GetGameState()->WorldLevel);
			for (auto LootDrop : LootDrops)
			{
				GameHelper::SpawnPickup(LootDrop.ItemEntry, SpawnLoc, true);
			}

			Container->bAlreadySearched = true;
			Container->OnRep_bAlreadySearched();

			if (PlayerController->MatchReport)
			{
				PlayerController->MatchReport->Stats.Kills = PlayerState->KillScore;
				FAthenaRewardResult EndOfMatchResults = PlayerController->MatchReport->EndOfMatchResults;
				FAthenaAwardGroup AwardGroup{};
				AwardGroup.SeasonXp = 100;
				AwardGroup.BookXp = 100;
				AwardGroup.Score = 100;
				AwardGroup.RewardSource = ERewardSource::Medals;
				EndOfMatchResults.Rewards.Add(AwardGroup);
			}
		}
		else if (ReceivingActor->IsA(AmmoBoxClass))
		{
			vector<LootManager::LootDrop> LootDrops = LootManager::PickLootDrops(LootManager::RedirectLootTierGroup(Container->SearchLootTierGroup), Globals::GetGameState()->WorldLevel);
			for (auto LootDrop : LootDrops)
			{
				GameHelper::SpawnPickup(LootDrop.ItemEntry, SpawnLoc, true);
			}

			Container->bAlreadySearched = true;
			Container->OnRep_bAlreadySearched();

			if (PlayerController->MatchReport)
			{
				PlayerController->MatchReport->Stats.Kills = PlayerState->KillScore;
				FAthenaRewardResult EndOfMatchResults = PlayerController->MatchReport->EndOfMatchResults;
				FAthenaAwardGroup AwardGroup{};
				AwardGroup.SeasonXp = 25;
				AwardGroup.BookXp = 25;
				AwardGroup.Score = 25;
				AwardGroup.RewardSource = ERewardSource::Invalid;
				EndOfMatchResults.Rewards.Add(AwardGroup);
			}
		}
		else if (ReceivingActor->IsA(AFortAthenaSupplyDrop::StaticClass()))
		{
			static FName LootTierGroup = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaSupplyDrop");

			auto LootDrops = LootManager::PickLootDrops(LootTierGroup, Globals::GetGameState()->WorldLevel);

			for (auto& LootDrop : LootDrops)
			{
				GameHelper::SpawnPickup(LootDrop.ItemEntry, SpawnLoc, true);
			}
		}


		return oServerAttemptInteract(PlayerController, ReceivingActor, InteractComponent, InteractType, OptionalObjectData);
	}

	FRotator* (*oGetViewRotation)(void* a1, FRotator* ViewRotation);
	FRotator* hkGetViewRotation(void* a1, FRotator* ViewRotation)
	{
		auto Rotation = oGetViewRotation(a1, ViewRotation);
		Rotation->Roll = 0;

		return Rotation;
	}

	void (*oClientNotifyWon)(AFortPlayerControllerAthena* PlayerController);
	void hkClientNotifyWon(AFortPlayerControllerAthena* PlayerController)
	{
		if (!PlayerController)
			return;

		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);

		if (!PlayerState)
			return oClientNotifyWon(PlayerController);

		oClientNotifyWon(PlayerController);

		auto& TeamMembers = PlayerController->TeamMembers;
		int AliveTeammates = 1;

		if (TeamMembers.IsValid())
			AliveTeammates = TeamMembers.Num();


		int place = PlayerState->Place;

		PlayerController->MatchReport->Stats.Kills = PlayerState->KillScore;
		FAthenaRewardResult EndOfMatchResults = PlayerController->MatchReport->EndOfMatchResults;

		FAthenaAwardGroup AwardGroup{};
		AwardGroup.SeasonXp = 1000;
		AwardGroup.BookXp = 1000;
		AwardGroup.Score = 1000;
		AwardGroup.RewardSource = ERewardSource::Placement;
		EndOfMatchResults.Rewards.Add(AwardGroup);


		PlayerController->ClientSendEndBattleRoyaleMatchForPlayer(true, EndOfMatchResults);

		FAthenaMatchStats KStats = PlayerController->MatchReport->Stats;
		FAthenaMatchTeamStats KTeamStats = PlayerController->MatchReport->TeamStats;

		PlayerController->MatchReport->bHasStats = true;
		PlayerController->ClientSendMatchStatsForPlayer(KStats);

		KTeamStats.Place = PlayerState->Place;
		KTeamStats.TotalPlayers = Globals::GetGameMode()->NumPlayers;
		PlayerController->MatchReport->bHasTeamStats = true;
		PlayerController->ClientSendTeamStatsForPlayer(KTeamStats);
	}

	void SendMessageToConsole(AFortPlayerController* PlayerController, FString Msg)
	{
		static FName TypeName = UKismetStringLibrary::Conv_StringToName(L"Event");
		PlayerController->ClientMessage(Msg, TypeName, 1);
	}

	void hkServerCheat(AFortPlayerControllerAthena* PlayerController, FString Msg)
	{
		if (!PlayerController)
			return;
		LogInfo("ServerCheat: Msg: {}", Msg.ToString());

		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
		if (!PlayerState)
			return;
		auto Pawn = reinterpret_cast<APlayerPawn_Athena_C*>(PlayerController->AcknowledgedPawn);

		string PlayerName = PlayerState->GetPlayerName().ToString();
		LogInfo("ServerCheat: Player: {}", PlayerName);

		bool bCanContinue = true; //false;

		if (!bCanContinue)
			return;

		if (!Msg.Data || Msg.Num() <= 0)
			return;

		std::vector<std::string> Arguments;
		auto Message = Msg.ToString();

		size_t start = Message.find('\\');

		int zz = 0;

		while (Message.find(" ") != std::string::npos)
		{
			auto arg = Message.substr(0, Message.find(' '));
			Arguments.push_back(arg);
			Message.erase(0, Message.find(' ') + 1);
			zz++;
		}

		Arguments.push_back(Message);
		zz++;

		auto NumArgs = Arguments.size() == 0 ? 0 : Arguments.size() - 1;

		if (Arguments.size() >= 1)
		{
			string& Command = Arguments[0];
			std::transform(Command.begin(), Command.end(), Command.begin(), ::tolower);
			if (Command == "players")
			{
				TArray<UNetConnection*> ClientConnections = ServerManager::NetDriver->ClientConnections;
				if (ClientConnections.IsValid())
				{
					for (int i = 0; i < ClientConnections.Num(); i++)
					{
						UNetConnection* ClientConnection = ClientConnections[i];
						if (!ClientConnection)
							continue;

						auto PlayerPC = reinterpret_cast<AFortPlayerControllerAthena*>(ClientConnection->PlayerController);
						if (!PlayerPC)
							continue;

						auto PlayerPS = reinterpret_cast<AFortPlayerStateAthena*>(PlayerPC->PlayerState);
						if (!PlayerPS)
							continue;

						SendMessageToConsole(PlayerController, PlayerPS->GetPlayerName());
					}
				}
			}
			else if (Command == "aliveplayers")
			{
				AFortGameModeAthena* GameMode = Globals::GetGameMode();
				TArray<AFortPlayerControllerAthena*> AlivePlayers = GameMode->AlivePlayers;

				if (AlivePlayers.IsValid())
				{
					for (int i = 0; i < AlivePlayers.Num(); i++)
					{
						AFortPlayerControllerAthena* AlivePlayer = AlivePlayers[i];
						if (!AlivePlayer)
							continue;

						auto AlivePlayerState = reinterpret_cast<AFortPlayerStateAthena*>(AlivePlayer->PlayerState);
						if (!AlivePlayerState)
							continue;

						SendMessageToConsole(PlayerController, AlivePlayerState->GetPlayerName());
					}
				}
			}
			else if (Command == "giveallmats")
			{
				static auto WoodDefinition = GameHelper::FindObject<UFortResourceItemDefinition>("/Game/Items/ResourcePickups/WoodItemData.WoodItemData");
				static auto StoneDefinition = GameHelper::FindObject<UFortResourceItemDefinition>("/Game/Items/ResourcePickups/StoneItemData.StoneItemData");
				static auto MetalDefinition = GameHelper::FindObject<UFortResourceItemDefinition>("/Game/Items/ResourcePickups/MetalItemData.MetalItemData");

				Inventory::AddItem(PlayerController, WoodDefinition, 999);
				Inventory::AddItem(PlayerController, StoneDefinition, 999);
				Inventory::AddItem(PlayerController, MetalDefinition, 999);
			}
			else if (Command == "godloadout")
			{
				TArray<FFortItemEntry> ReplicatedEntries = PlayerController->WorldInventory->Inventory.ReplicatedEntries;
				for (int i = 0; i < ReplicatedEntries.Num(); i++)
				{
					FFortItemEntry Entry = ReplicatedEntries[i];
					if (!Entry.ItemDefinition)
						continue;

					if (reinterpret_cast<UFortWorldItemDefinition*>(Entry.ItemDefinition)->bCanBeDropped && Inventory::GetQuickBars(Entry.ItemDefinition) == EFortQuickBars::Primary)
						Inventory::RemoveItem(PlayerController, Entry.ItemGuid);
				}

				static auto ScarDefinition = GameHelper::FindObject<UFortItemDefinition>("/Game/Athena/Items/Weapons/WID_Assault_AutoHigh_Athena_SR_Ore_T03.WID_Assault_AutoHigh_Athena_SR_Ore_T03");
				static auto PumpDefinition = GameHelper::FindObject<UFortItemDefinition>("/Game/Athena/Items/Weapons/WID_Shotgun_Standard_Athena_UC_Ore_T03.WID_Shotgun_Standard_Athena_UC_Ore_T03");
				static auto MiniShieldDefinition = GameHelper::FindObject<UFortItemDefinition>("/Game/Athena/Items/Consumables/ShieldSmall/Athena_ShieldSmall.Athena_ShieldSmall");
				static auto BigPotDefinition = GameHelper::FindObject<UFortItemDefinition>("/Game/Athena/Items/Consumables/Shields/Athena_Shields.Athena_Shields");

				Inventory::AddItem(PlayerController, ScarDefinition, 1, 30);
				Inventory::AddItem(PlayerController, PumpDefinition, 1, 5);
				Inventory::AddItem(PlayerController, PumpDefinition, 1, 5);
				Inventory::AddItem(PlayerController, MiniShieldDefinition, 10);
				Inventory::AddItem(PlayerController, BigPotDefinition, 2);
			}
			else if (Command == "ban")
			{
				if (NumArgs < 1)
				{
					SendMessageToConsole(PlayerController, L"Please provide a Display Name!");
					return;
				}

				string& DisplayName = Arguments[1];

				LogInfo("OP:{}: Banning {}...", PlayerName, DisplayName);

				SendMessageToConsole(PlayerController, L"Banning is currently not implemented.");
			}
			else if (Command == "spawnitem")
			{
				if (NumArgs < 1)
				{
					SendMessageToConsole(PlayerController, L"Please provide a Weapon ID, e.g. WID_Assault_AutoHigh_Athena_VR_Ore_T03");
					return;
				}

				string& WeaponID = Arguments[1];
				int Count = 1;
				int LoadedAmmo = 0;

				try
				{
					if (NumArgs >= 2)
						Count = std::stoi(Arguments[2]);

					if (NumArgs >= 3)
						LoadedAmmo = std::stoi(Arguments[3]);
				}
				catch (...)
				{
				}


				auto WID = UObject::FindObject<UFortWeaponItemDefinition>(WeaponID + "." + WeaponID);

				if (WID && Pawn)
				{
					FFortItemEntry* ItemEntry = new FFortItemEntry();
					ItemEntry->Count = Count;
					ItemEntry->ItemDefinition = WID;
					ItemEntry->LoadedAmmo = LoadedAmmo;
					GameHelper::SpawnPickup(ItemEntry, Pawn->K2_GetActorLocation());
				}
				else
					SendMessageToConsole(PlayerController, L"Weapon ID is invalid.");
			}
			else if (Command == "giveitem")
			{
				if (NumArgs < 1)
				{
					SendMessageToConsole(PlayerController, L"Please provide a Weapon ID, e.g. WID_Assault_AutoHigh_Athena_VR_Ore_T03");
					return;
				}

				string& WeaponID = Arguments[1];
				int Count = 1;
				int LoadedAmmo = 0;

				try
				{
					if (NumArgs >= 2)
						Count = std::stoi(Arguments[2]);

					if (NumArgs >= 3)
						LoadedAmmo = std::stoi(Arguments[3]);
				}
				catch (...)
				{
				}


				auto WID = UObject::FindObject<UFortWeaponItemDefinition>(WeaponID + "." + WeaponID);

				if (WID && Pawn)
				{
					if (!Inventory::IsFull(PlayerController))
					{
						Inventory::AddItem(PlayerController, WID, Count, LoadedAmmo);
					}
					else
					{
						FFortItemEntry* ItemEntry = new FFortItemEntry();
						ItemEntry->Count = Count;
						ItemEntry->ItemDefinition = WID;
						ItemEntry->LoadedAmmo = LoadedAmmo;
						GameHelper::SpawnPickup(ItemEntry, Pawn->K2_GetActorLocation());
					}
				}
				else
					SendMessageToConsole(PlayerController, L"Weapon ID is invalid.");
			}
			else if (Command == "buildfree")
			{
				PlayerController->bBuildFree = ~PlayerController->bBuildFree;
				SendMessageToConsole(PlayerController, std::wstring(L"Build Free set to " + std::to_wstring((bool)PlayerController->bBuildFree)).c_str());
			}
			else if (Command == "infiniteammo")
			{
				PlayerController->bInfiniteAmmo = ~PlayerController->bInfiniteAmmo;
				SendMessageToConsole(PlayerController, std::wstring(L"Infinite Ammo set to " + std::to_wstring((bool)PlayerController->bInfiniteAmmo)).c_str());
			}
			else if (Command == "god")
			{
				Pawn->bCanBeDamaged = ~Pawn->bCanBeDamaged;
				SendMessageToConsole(PlayerController, std::wstring(L"God set to " + std::to_wstring((bool)!Pawn->bCanBeDamaged)).c_str());
			}
			else if (Command == "sethealth")
			{
				if (!Pawn)
				{
					SendMessageToConsole(PlayerController, L"Pawn is not valid.");
					return;
				}

				float Health = 100.f;

				try { Health = std::stof(Arguments[1]); }
				catch (...) {}

				Pawn->SetHealth(Health);
				SendMessageToConsole(PlayerController, L"Set health!");
			}
			else if (Command == "setshield")
			{
				if (!Pawn)
				{
					SendMessageToConsole(PlayerController, L"Pawn is not valid.");
					return;
				}

				float Shield = 100.f;

				try { Shield = std::stof(Arguments[1]); }
				catch (...) {}

				Shield = Shield > 100.f ? 100.f : Shield;

				auto& HealthSet = Pawn->HealthSet;
				HealthSet->CurrentShield.CurrentValue = Shield;
				HealthSet->OnRep_CurrentShield();

				SendMessageToConsole(PlayerController, L"Set Shield!");
			}
			else if (Command == "invisible")
			{
				if (!Pawn)
				{
					SendMessageToConsole(PlayerController, L"Pawn is not valid.");
					return;
				}

				Pawn->bHidden = ~Pawn->bHidden;
				SendMessageToConsole(PlayerController, std::wstring(L"Visibility set to " + std::to_wstring((bool)!Pawn->bHidden)).c_str());
			}
			else if (Command == "help")
			{
				wstring HelpMessage = LR"(
---------------------------------- MAIN ----------------------------------

cheat players - List all player connections
cheat aliveplayers - Lists all Alive Players
cheat giveallmats - Gives all materials to player
cheat godloadout - Gives player a god loadout (Scar, 2 Pumps, Minis and Shields)
cheat spawnitem {WID} {Count} {LoadedAmmo} - Spawns a pickup at player
cheat giveitem {WID} {Count} {LoadedAmmo} - Gives the weapon to players inventory
cheat buildfree - Toggle Build Free
cheat infiniteammo - Toggle Infinite Ammo
cheat god - Toggle Infinite Health
cheat sethealth {health} - Set players health
cheat setshield {shield} - Set players shield
cheat invisible - Toggle Visibility
)";

				SendMessageToConsole(PlayerController, HelpMessage.c_str());
			}
			else
				SendMessageToConsole(PlayerController, L"Could not find Command.");
		}
	}

	void (*oServerCheatAll)(AFortPlayerController* PlayerController, __int64* a2);
	void hkServerCheatAll(AFortPlayerController* PlayerController, __int64* a2)
	{
		return;
	}

	void hkServerPlaySquadQuickChatMessage(AFortPlayerControllerAthena* PlayerController, FAthenaQuickChatActiveEntry ChatEntry, FUniqueNetIdRepl SenderID)
	{
		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);

		if (!PlayerState)
			return;

		ETeamMemberState NewTeamMemberState = ETeamMemberState::None;

		switch (ChatEntry.Index)
		{
		case 0:
			NewTeamMemberState = ETeamMemberState::EnemySpotted;
			break;
		case 1:
			NewTeamMemberState = ETeamMemberState::NeedBandages;
			break;
		case 2:
			NewTeamMemberState = ETeamMemberState::NeedShields;
			break;
		case 3:
			NewTeamMemberState = ETeamMemberState::NeedMaterials;
			break;
		case 4:
			NewTeamMemberState = ETeamMemberState::NeedWeapon;
			break;
		case 5:
			NewTeamMemberState = ETeamMemberState::NeedAmmoLight;
			break;
		case 6:
			NewTeamMemberState = ETeamMemberState::NeedAmmoMedium;
			break;
		case 7:
			NewTeamMemberState = ETeamMemberState::NeedAmmoHeavy;
			break;
		case 8:
			NewTeamMemberState = ETeamMemberState::NeedAmmoShells;
			break;
		case 9:
			NewTeamMemberState = ETeamMemberState::NeedAmmoRocket;
			break;
		default:
			break;
		}

		PlayerState->ReplicatedTeamMemberState = NewTeamMemberState;
		PlayerState->TeamMemberState = NewTeamMemberState;

		static auto EmojiComm = GameHelper::FindObject<UAthenaEmojiItemDefinition>("/Game/Athena/Items/Cosmetics/Dances/Emoji/Emoji_Comm.Emoji_Comm");
		PlayerController->ServerPlayEmoteItem(EmojiComm);

		PlayerState->OnRep_ReplicatedTeamMemberState();
	}

	void hkServerItemWillBeDestroyed(AFortPlayerController* PlayerController, FGuid DestroyedItemGuid, int32 Count)
	{
		if (!PlayerController)
			return;

		FFortItemEntry* ItemEntry = Inventory::FindItem(PlayerController, DestroyedItemGuid);
		if (!ItemEntry)
			return;

		LogInfo("ItemDef: {}", ItemEntry->ItemDefinition->GetFullName());
	}


	void Initialize()
	{
		auto DefaultObj = SDK::AAthena_PlayerController_C::GetDefaultObj();
		HookingManager::VirtualHook(DefaultObj, 0x241, hkServerReadyToStartMatch, (void**)&oServerReadyToStartMatch);
		HookingManager::VirtualHook(DefaultObj, 0x243, hkServerLoadingScreenDropped, (void**)&oServerLoadingScreenDropped);
		HookingManager::VirtualHook(DefaultObj, 0x104, hkServerAcknowledgePossession);
		HookingManager::VirtualHook(DefaultObj, 0x1E5, hkServerExecuteInventoryItem);
		HookingManager::VirtualHook(DefaultObj, 0x201, hkServerCreateBuildingActor);
		HookingManager::VirtualHook(DefaultObj, 0x207, hkServerBeginEditingBuildingActor);
		HookingManager::VirtualHook(DefaultObj, 0x203, hkServerEditBuildingActor, (void**)&oServerEditBuildingActor);
		HookingManager::VirtualHook(DefaultObj, 0x205, hkServerEndEditingBuildingActor);
		HookingManager::VirtualHook(DefaultObj, 0x1FD, hkServerRepairBuildingActor);
		HookingManager::VirtualHook(DefaultObj, 0x23D, hkServerReturnToMainMenu);
		HookingManager::VirtualHook(DefaultObj, 0x1F7, hkServerAttemptInventoryDrop);
		HookingManager::VirtualHook(DefaultObj, 0x1E1, hkServerRemoveInventoryItem);
		//HookingManager::VirtualHook(DefaultObj, 0x1F2, hkServerItemWillBeDestroyed);
		HookingManager::VirtualHook(DefaultObj, 0x1B3, hkServerPlayEmoteItem);
		HookingManager::VirtualHook(DefaultObj, 0x232, hkServerAttemptInteract, (void**)&oServerAttemptInteract);
		HookingManager::VirtualHook(DefaultObj, 0x1AF, hkServerCheat);
		HookingManager::VirtualHook(DefaultObj, 0x1AD, hkServerCheatAll, (void**)&oServerCheatAll);
		HookingManager::VirtualHook(DefaultObj, 0x365, hkServerPlaySquadQuickChatMessage);


		HookingManager::CreateHook(Memory::GetAddress(LOffsets::ClientOnPawnDied), hkClientOnPawnDied, (void**)&oClientOnPawnDied);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::GetPlayerViewpoint), hkGetPlayerViewPoint, (void**)&oGetPlayerViewPoint);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::EnterAircraft), hkEnterAircraft, (void**)&oEnterAircraft);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::GetViewRotation), hkGetViewRotation, (void**)&oGetViewRotation);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::ClientNotifyWon), hkClientNotifyWon, (void**)&oClientNotifyWon);
		LogInfo("PlayerController: Initialized.");
	}
}
