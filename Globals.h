#pragma once
#include "framework.h"

namespace Globals
{
	string CurrentPlaylistName = "Solo";

	bool bIsPlaylistSetup = false;
	bool bStartedAircraft = false;
	bool bAlreadySpawned = false;
	bool bPlayerJoined = false;

	AFortGameModeAthena* GetGameMode()
	{
		return static_cast<AFortGameModeAthena*>(UWorld::GetWorld()->AuthorityGameMode);
	}

	AFortGameStateAthena* GetGameState()
	{
		return static_cast<AFortGameStateAthena*>(UWorld::GetWorld()->GameState);
	}
}