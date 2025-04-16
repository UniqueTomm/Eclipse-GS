#pragma once
#include "framework.h"

namespace FortWeapon
{
	void (*oHandleReloadCost)(AFortWeapon* Weapon, int AmountToTake);
	void hkHandleReloadCost(AFortWeapon* Weapon, int AmountToTake)
	{
		if (!Weapon || !Weapon->WeaponData)
		{
			LogError("FortWeapon::HandleReloadCost: Weapon or WeaponData is NULL.");
			return;
		}

		auto Pawn = reinterpret_cast<AFortPawn*>(Weapon->GetOwner());
		if (!Pawn)
		{
			LogError("FortWeapon::HandleReloadCost: Pawn is NULL.");
			return;
		}

		auto PlayerController = reinterpret_cast<AFortPlayerController*>(Pawn->Controller);
		if (!PlayerController)
		{
			LogError("FortWeapon::HandleReloadCost: PlayerController is NULL.");
			return;
		}

		FFortItemEntry* FoundItemEntry = Inventory::FindItem(PlayerController, Weapon->ItemEntryGuid);
		FFortItemEntry* FoundAmmoItemEntry = nullptr;

		UFortWorldItemDefinition* AmmoData = Weapon->WeaponData->GetAmmoWorldItemDefinition_BP();

		if (AmmoData == Weapon->WeaponData)
			FoundAmmoItemEntry = FoundItemEntry;
		else
			FoundAmmoItemEntry = Inventory::FindItem(PlayerController, AmmoData);

		if (!FoundAmmoItemEntry || !FoundItemEntry)
			return;

		int ClipSize = LootManager::GetClipSize(reinterpret_cast<UFortWeaponItemDefinition*>(FoundItemEntry->ItemDefinition));

		if (ClipSize > 0)
		{
			FoundItemEntry->LoadedAmmo = Weapon->AmmoCount;
			PlayerController->WorldInventory->Inventory.MarkItemDirty(*FoundItemEntry);

			Inventory::RemoveItem(PlayerController, FoundAmmoItemEntry->ItemGuid, AmountToTake);
		}
		else
			Inventory::RemoveItem(PlayerController, FoundAmmoItemEntry->ItemGuid, AmountToTake);
	}

	void Initialize()
	{
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::HandleReloadCost), hkHandleReloadCost);

		LogInfo("FortWeapon: Initialized.");
	}
}