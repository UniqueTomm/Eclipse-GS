#pragma once
#include "framework.h"

namespace GameMode
{
	static bool (*oReadyToStartMatch)(void*);
	bool hkReadyToStartMatch(AFortGameModeAthena* GameMode)
	{
		auto GameState = reinterpret_cast<AFortGameStateAthena*>(GameMode->GameState);

		if (!Globals::bIsPlaylistSetup)
		{
			Globals::bIsPlaylistSetup = true;

			UFortPlaylistAthena* Playlist = PlaylistManager::GetCurrentPlaylist();
			if (Playlist)
			{
				LogInfo("Playlist: {}", Playlist->UIDisplayName.ToString());

				GameState->CurrentPlaylistId = Playlist->PlaylistId;
				GameState->CurrentPlaylistData = Playlist;
				GameState->OnRep_CurrentPlaylistId();
				GameState->OnRep_CurrentPlaylistData();
				GameState->WinConditionTimeRemaining = Playlist->TimedWinConditionTime;
				GameState->OnRep_WinConditionTimeRemaining();

				GameMode->CurrentPlaylistId = Playlist->PlaylistId;
				GameMode->CurrentPlaylistName = Playlist->PlaylistName;

				GameMode->FriendlyFireType = Playlist->FriendlyFireType;
				GameMode->FortGameSession->MaxPlayers = Playlist->MaxPlayers;
				GameMode->FortGameSession->MaxPartySize = Playlist->MaxSocialPartySize;
			}
			else
				LogError("ReadyToStartMatch: Playlist is null.");


		}

		if (!GameState->MapInfo)
			return false;

		if (!ServerManager::bIsListening)
		{
			GameMode->WarmupRequiredPlayerCount = 1;
			Server::Listen();
			Server::Initialize();
		}
		GameMode->bWorldIsReady = true;

		return oReadyToStartMatch(GameMode);
	}

	APawn* (*oSpawnDefaultPawnFor)(void* GameMode, AController* NewPlayer, AActor* StartSpot);
	APawn* hkSpawnDefaultPawnFor(AFortGameModeAthena* GameMode, AController* NewPlayer, AActor* StartSpot)
	{
		if (NewPlayer && StartSpot)
		{
			FTransform Transform = StartSpot->GetTransform();
			return GameMode->SpawnDefaultPawnAtTransform(NewPlayer, Transform);		
		}
		LogError("GameMode::SpawnDefaultPawnFor: Failed to spawn pawn.");

		return nullptr;
	}


	int hkPickTeam(AFortGameModeAthena* GameMode, uint8 preferredTeam, AFortPlayerControllerAthena* PlayerController)
	{
		static UFortPlaylistAthena* Playlist = PlaylistManager::GetCurrentPlaylist();

		static int DefaultFirstTeam = 3;
		bool bShouldSpreadTeams = false;

		static int CurrentTeamMembers = 0;
		static int Current = DefaultFirstTeam;
		static int NextTeamIndex = DefaultFirstTeam;

		int MaxSquadSize = Playlist->MaxSquadSize;

		if (CurrentTeamMembers >= MaxSquadSize)
		{
			NextTeamIndex++;
			CurrentTeamMembers = 0;
		}

		CurrentTeamMembers++;

		return NextTeamIndex;
	}

	TSubclassOf<AGameSession> hkGetGameSessionClass(AGameModeBase* GameMode)
	{
		return AFortGameSessionDedicated::StaticClass();
	}

	void Initialize()
	{
		HookingManager::CreateHook(Memory::GetAddress(0x25BAC60), hkReadyToStartMatch, (void**)&oReadyToStartMatch);
		HookingManager::CreateHook(Memory::GetAddress(0xA083A0), hkSpawnDefaultPawnFor);
		HookingManager::CreateHook(Memory::GetAddress(LOffsets::PickTeam), hkPickTeam);

		//0xC9 || 0xCD
	//	HookingManager::VirtualHook(AGameModeBase::GetDefaultObj(), 0xC9, hkGetGameSessionClass);

		LogInfo("GameMode: Initialized.");
	}
}

