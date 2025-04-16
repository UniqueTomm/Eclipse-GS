#pragma once
#include "framework.h"

namespace FortPickup
{
	char (*oCompletePickupAnimation)(AFortPickup* Pickup);
	char hkCompletePickupAnimation(AFortPickup* Pickup)
	{
		auto Pawn = reinterpret_cast<APlayerPawn_Athena_C*>(Pickup->PickupLocationData.PickupTarget);

		if (!Pawn)
			return oCompletePickupAnimation(Pickup);

		auto PlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(Pawn->GetController());

		if (!PlayerController)
			return oCompletePickupAnimation(Pickup);

		auto WorldInventory = PlayerController->WorldInventory;

		if (!WorldInventory)
			return oCompletePickupAnimation(Pickup);

		FGuid Swap = FGuid(-1, -1, -1, -1);

		FFortItemEntry* PickupEntry = &Pickup->PrimaryPickupItemEntry;
		FFortItemEntry* InvItemEntry = Inventory::FindItem(PlayerController, Pickup->PickupLocationData.PickupGuid);

		if (!PickupEntry || !InvItemEntry)
		{
			FFortItemEntry DropEntry{};
			DropEntry.Count = PickupEntry->Count;
			DropEntry.ItemDefinition = PickupEntry->ItemDefinition;
			DropEntry.LoadedAmmo = PickupEntry->LoadedAmmo;

			GameHelper::SpawnPickup(&DropEntry, Pawn->K2_GetActorLocation(), false, Pawn);

			return oCompletePickupAnimation(Pickup);
		}

		auto PickupItemDefinition = reinterpret_cast<UFortWorldItemDefinition*>(PickupEntry->ItemDefinition);
		int IncomingCount = PickupEntry->Count;
		FGuid ItemGuid = PickupEntry->ItemGuid;

		if (!PickupItemDefinition)
			return oCompletePickupAnimation(Pickup);

		if (Inventory::GetQuickBars(PickupItemDefinition) == EFortQuickBars::Primary)
		{
			int NewCount = 0;
			int OverStack = 0;

			bool bSuccess = false;
			bool bDrop = false;

			for (int i = 0; i < PlayerController->WorldInventory->Inventory.ReplicatedEntries.Num(); i++)
			{
				FFortItemEntry* CurrentEntry = &PlayerController->WorldInventory->Inventory.ReplicatedEntries[i];
				if (CurrentEntry->ItemDefinition == PickupItemDefinition)
				{
					NewCount = CurrentEntry->Count + IncomingCount;
					OverStack = NewCount - PickupItemDefinition->MaxStackSize;

					CurrentEntry->Count = OverStack > 0 ? NewCount - OverStack : NewCount;

					PlayerController->WorldInventory->Inventory.MarkItemDirty(*CurrentEntry);
					PlayerController->WorldInventory->Inventory.MarkArrayDirty();

					if (OverStack <= 0)
					{
						bSuccess = true;
						break;
					}
				}
			}

			bDrop = !bSuccess;

			if (Inventory::IsFull(PlayerController) && bDrop)
			{
				int DropCount = OverStack > 0 ? OverStack : IncomingCount;

				if (reinterpret_cast<UFortWorldItemDefinition*>(InvItemEntry->ItemDefinition)->bCanBeDropped && InvItemEntry->ItemDefinition->bAllowMultipleStacks)
				{
					PlayerController->ServerAttemptInventoryDrop(InvItemEntry->ItemGuid, InvItemEntry->Count);

					Swap = Inventory::AddItem(PlayerController, PickupItemDefinition, DropCount, PickupEntry->LoadedAmmo);
					//LogInfo("Swap: {}, {}, {}, {}", Swap.A, Swap.B, Swap.C, Swap.D);
				}
				else
				{
					FFortItemEntry DropEntry{};
					DropEntry.Count = DropCount;
					DropEntry.ItemDefinition = PickupItemDefinition;
					DropEntry.LoadedAmmo = PickupEntry->LoadedAmmo;

					GameHelper::SpawnPickup(&DropEntry, Pawn->K2_GetActorLocation(), false, Pawn);
				}
			}
			else if (!Inventory::IsFull(PlayerController) && bDrop)
			{
				int DropCount = OverStack > 0 ? OverStack : IncomingCount;

				Inventory::AddItem(PlayerController, PickupItemDefinition, DropCount, PickupEntry->LoadedAmmo);
			}
		}
		else
			Inventory::AddItem(PlayerController, PickupItemDefinition, IncomingCount, PickupEntry->LoadedAmmo);

		//LogInfo("Swap: {}, {}, {}, {}", Swap.A, Swap.B, Swap.C, Swap.D);


		FGuid CurrentGuid = FGuid(-1, -1, -1, -1);
		if (Pawn->CurrentWeapon)
			CurrentGuid = Pawn->CurrentWeapon->ItemEntryGuid;

		if (Swap != FGuid(-1,-1,-1,-1) && CurrentGuid == Pickup->PickupLocationData.PickupGuid)
			PlayerController->ClientEquipItem(Swap);

		return oCompletePickupAnimation(Pickup);
	}

	void Initialize()
	{
		HookingManager::CreateHook(Memory::GetAddress(0xd01680), hkCompletePickupAnimation, (void**)&oCompletePickupAnimation);

		LogInfo("FortPickup: Initialized.");
	}
}