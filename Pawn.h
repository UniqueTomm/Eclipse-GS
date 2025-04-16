#pragma once
#include "framework.h"

namespace Pawn
{
	void (*oServerHandlePickup)(APlayerPawn_Athena_C* Pawn, AFortPickup* Pickup, float InFlyTime, FVector InStartDirection, bool bPlayPickupSound);
	void hkServerHandlePickup(APlayerPawn_Athena_C* Pawn, AFortPickup* Pickup, float InFlyTime, FVector InStartDirection, bool bPlayPickupSound)
	{
		if (!Pawn)
		{
			LogError("Pawn::ServerHandlePickup: Pawn is NULL.");
			return;
		}	

		if (!Pickup)
		{
			LogError("Pawn::ServerHandlePickup: Pickup is NULL.");
			return;
		}

		if (Pickup->bPickedUp)
			return;

		auto PlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(Pawn->Controller);
		if (!PlayerController)
		{
			LogError("Pawn::ServerHandlePickup: PlayerController is NULL.");
			return;
		}

		Pawn->IncomingPickups.Add(Pickup);
		auto& LocData = Pickup->PickupLocationData;
		LocData.StartDirection = reinterpret_cast<FVector_NetQuantizeNormal&>(InStartDirection);
		LocData.FlyTime = 0.40f;
		LocData.PickupTarget = Pawn;
		LocData.ItemOwner = Pawn;
		LocData.bPlayPickupSound = bPlayPickupSound;
		LocData.PickupGuid = Pawn->CurrentWeapon ? Pawn->CurrentWeapon->ItemEntryGuid : FGuid();
		Pickup->OnRep_PickupLocationData();

		Pickup->bPickedUp = true;
		Pickup->OnRep_bPickedUp();
	}

	void (*oServerHandlePickupWithSwap)(AFortPlayerPawnAthena* Pawn, AFortPickup* Pickup, FGuid Swap, float InFlyTime, FVector InStartDirection, bool bPlayPickupSound);
	void hkServerHandlePickupWithSwap(AFortPlayerPawnAthena* Pawn, AFortPickup* Pickup, FGuid Swap, float InFlyTime, FVector InStartDirection, bool bPlayPickupSound)
	{
		auto Controller = reinterpret_cast<AFortPlayerControllerAthena*>(Pawn->GetController());

		if (!Controller)
			return oServerHandlePickupWithSwap(Pawn, Pickup, Swap, InFlyTime, InStartDirection, bPlayPickupSound);

		if (!Pickup)
			return oServerHandlePickupWithSwap(Pawn, Pickup, Swap, InFlyTime, InStartDirection, bPlayPickupSound);

		if (Pickup->bPickedUp)
			return oServerHandlePickupWithSwap(Pawn, Pickup, Swap, InFlyTime, InStartDirection, bPlayPickupSound);

		Pawn->IncomingPickups.Add(Pickup);

		auto PickupLocationData = Pickup->PickupLocationData;

		PickupLocationData.PickupTarget = Pawn;
		PickupLocationData.FlyTime = 0.40f;
		PickupLocationData.ItemOwner = Pawn;
		PickupLocationData.PickupGuid = Swap;
		Pickup->OnRep_PickupLocationData();

		Pickup->bPickedUp = true;
		Pickup->OnRep_bPickedUp();

		return oServerHandlePickupWithSwap(Pawn, Pickup, Swap, InFlyTime, InStartDirection, bPlayPickupSound);
	}

	void (*oServerChoosePart)(AFortPlayerPawn* Pawn, EFortCustomPartType Part, UCustomCharacterPart* ChosenCharacterPart);
	void hkServerChoosePart(AFortPlayerPawn* Pawn, EFortCustomPartType Part, UCustomCharacterPart* ChosenCharacterPart)
	{
		LogInfo("Pawn::ServerChoosePart: Patched - Sorry Zach! ");
		return;
	}

	void hkServerReviveFromDBNO(AFortPlayerPawn* Pawn, AController* EventInstigator)
	{
		if (!Pawn->IsDBNO())
			return;

		auto PlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(Pawn->GetController());

		if (!PlayerController)
			return;

		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);

		if (!PlayerState)
			return;

		auto DBNOPawn = reinterpret_cast<APlayerPawn_Athena_C*>(Pawn);
		auto DBNOPlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(DBNOPawn->Controller);

		if (!DBNOPawn || !DBNOPlayerController)
			return;

		auto DBNOController = reinterpret_cast<AFortPlayerControllerAthena*>(DBNOPawn->Controller);
		auto DBNOPlayerState = reinterpret_cast<AFortPlayerStateAthena*>(DBNOPawn->PlayerState);
		auto DBNOPawnASC = DBNOPawn->AbilitySystemComponent;

		auto InstigatorController = PlayerController;
		auto InstigatorPlayerState = PlayerState;
		auto InstigatorPawn = reinterpret_cast<AFortPlayerPawnAthena*>(InstigatorController->Pawn);

		if (!DBNOController || !DBNOPlayerState || !DBNOPawnASC || !InstigatorPlayerState || !InstigatorPawn || DBNOPlayerState->TeamIndex != InstigatorPlayerState->TeamIndex)
			return;

		Abilities::RemoveGameplayAbility(DBNOPlayerState, UGAB_AthenaDBNO_C::GetDefaultObj());

		PlayerController->ClientOnPawnRevived(EventInstigator);

		DBNOPawn->SetHealth(30.0f);

		DBNOPawn->bPlayedDying = false;

		DBNOPawn->bIsDBNO = false;
		DBNOPawn->OnRep_IsDBNO();
		DBNOPawn->DBNORevivalStacking = 0;

		FAthenaMatchStats KStats = InstigatorController->MatchReport->Stats;
		KStats.Revives++;
	}

	void (*oNetMulticast_Athena_BatchedDamageCues)(AFortPlayerPawn* Pawn, FAthenaBatchedDamageGameplayCues BatchData);
	void hkNetMulticast_Athena_BatchedDamageCues(AFortPlayerPawnAthena* Pawn, FAthenaBatchedDamageGameplayCues BatchData)
	{
		if (!Pawn)
			return oNetMulticast_Athena_BatchedDamageCues(Pawn, BatchData);

		auto PlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(Pawn->Controller);
		if(!PlayerController)
			return oNetMulticast_Athena_BatchedDamageCues(Pawn, BatchData);

		if (BatchData.HitActor && BatchData.HitActor->IsA(APlayerPawn_Athena_C::StaticClass()))
		{
			if (BatchData.bIsValid)
			{
				if (PlayerController->MatchReport)
				{
					if (BatchData.bIsCritical)
						PlayerController->MatchReport->Stats.CriticalHitsToHostiles++;
					else
						PlayerController->MatchReport->Stats.NormalHitsToHostiles++;
				}
			}
		}

		auto CurrentWeapon = Pawn->CurrentWeapon;
		if (!CurrentWeapon)
			return oNetMulticast_Athena_BatchedDamageCues(Pawn, BatchData);

		FFortItemEntry* CurrentItemEntry = Inventory::FindItem(PlayerController, CurrentWeapon->ItemEntryGuid);
		if (!CurrentItemEntry)
			return oNetMulticast_Athena_BatchedDamageCues(Pawn, BatchData);

		CurrentItemEntry->LoadedAmmo = CurrentWeapon->AmmoCount;
		PlayerController->WorldInventory->Inventory.MarkItemDirty(*CurrentItemEntry);
		PlayerController->WorldInventory->Inventory.MarkArrayDirty();

		return oNetMulticast_Athena_BatchedDamageCues(Pawn, BatchData);
	}
	 
	void (*oOnCapsuleBeginOverlap)(AFortPlayerPawnAthena* Pawn, UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, FHitResult SweepResult);
	void hkOnCapsuleBeginOverlap(AFortPlayerPawnAthena* Pawn, UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, FHitResult SweepResult)
	{
		if (!Pawn || !OtherActor)
			return oOnCapsuleBeginOverlap(Pawn, OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

		if (Pawn->IsDBNO())
			return oOnCapsuleBeginOverlap(Pawn, OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

		if (OtherActor->IsA(AFortPickupAthena::StaticClass()))
		{
			auto Pickup = reinterpret_cast<AFortPickup*>(OtherActor);
			if (Pickup->PawnWhoDroppedPickup != Pawn)
			{
				UFortItemDefinition* ItemDefinition = Pickup->PrimaryPickupItemEntry.ItemDefinition;

				if (!ItemDefinition)
					return;

				if (Inventory::GetQuickBars(ItemDefinition) != EFortQuickBars::Primary)
					Pawn->ServerHandlePickup(Pickup, 0.4f, FVector(), true);
			}
		}

		return oOnCapsuleBeginOverlap(Pawn, OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	}

	void Initialize()
	{
		auto DefaultObject = APlayerPawn_Athena_C::GetDefaultObj();

		HookingManager::CreateHook(Memory::GetAddress(LOffsets::NetMulticast_Athena_BatchedDamageCues), hkNetMulticast_Athena_BatchedDamageCues, (void**)&oNetMulticast_Athena_BatchedDamageCues);
		HookingManager::CreateHook(Memory::GetAddress(0xA34F40), hkOnCapsuleBeginOverlap, (void**)&oOnCapsuleBeginOverlap);

		HookingManager::VirtualHook(DefaultObject, 0x18F, hkServerHandlePickup);
		HookingManager::VirtualHook(DefaultObject, 0x18D, hkServerHandlePickupWithSwap);
		HookingManager::VirtualHook(DefaultObject, 0x17D, hkServerReviveFromDBNO);
		HookingManager::VirtualHook(DefaultObject, 0x17F, hkServerChoosePart, (void**)&oServerChoosePart);

		LogInfo("Pawn: Initialized.");
	}
}