#pragma once
#include "framework.h"

namespace SpectatingManager
{
	AFortPlayerStateAthena* GetPlayerToSpectate(AFortPlayerControllerAthena* PlayerController)
	{
		if (!PlayerController)
		{
			LogError("SpectatingManager::GetPlayerToSpectate: PlayerController is NULL.");
			return nullptr;
		}

		TArray<AFortPlayerStateAthena*> TeamMembers = PlayerController->TeamMembers;
		if (TeamMembers.IsValid())
		{
			for (int i = 0; i < TeamMembers.Num(); i++)
			{
				AFortPlayerStateAthena* TeammateState = TeamMembers[i];
				if (TeammateState)
				{
					auto TeammateController = reinterpret_cast<AFortPlayerControllerAthena*>(TeammateState->Owner);
					if (GameHelper::IsValidLowLevel(TeammateController) && TeammateController->bMarkedAlive)
					{
						return TeammateState;
					}
				}
			}
		}
		else
			LogWarning("SpectatingManager::GetPlayerToSpectate: TeamMembers is not valid.");

		auto PlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerController->PlayerState);
		if (!PlayerState)
		{
			LogError("SpectatingManager::GetPlayerToSpectate: PlayerState is NULL.");
			return nullptr;
		}

		if (PlayerState->DeathInfo.FinisherOrDowner)
			return PlayerState->DeathInfo.FinisherOrDowner;

		auto& PlayerArray = Globals::GetGameState()->PlayerArray;
		for (int i = 0; i < PlayerArray.Num(); i++)
		{
			auto CurrentPlayerState = reinterpret_cast<AFortPlayerStateAthena*>(PlayerArray[i]);
			if (!CurrentPlayerState)
				continue;

			auto CurrentPlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(CurrentPlayerState->Owner);
			if (!CurrentPlayerController)
				continue;

			if (CurrentPlayerController->bMarkedAlive)
			{
				return CurrentPlayerState;
			}
		}

		LogError("SpectatingManager::GetPlayerToSpectate: Returning NULL PlayerState.");
		return nullptr;
	}
}