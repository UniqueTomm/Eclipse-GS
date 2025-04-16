#pragma once
#include "framework.h"

namespace CheatChecker
{
	void hkServerChangeName(AFortPlayerController* PlayerController, FString S)
	{
		LogInfo("ServerChangeName: {} tried to change his name to {}", reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState)->GetPlayerName().ToString(), S.ToString());
		GameHelper::KickPlayer(PlayerController, L"Attempted to change name, action will be taken.");
	}

	void (*oServerShortTimeout)(APlayerController* PlayerController);
	void hkServerShortTimeout(APlayerController* PlayerController)
	{
		return;
	}

	void Initialize()
	{
		HookingManager::VirtualHook(APlayerController::GetDefaultObj(), 0x100, hkServerChangeName);
		HookingManager::VirtualHook(APlayerController::GetDefaultObj(), 0xF4, hkServerShortTimeout, (void**)&oServerShortTimeout);

		LogInfo("CheatChecker: Initialized.");
	}
}