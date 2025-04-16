#pragma once
#include "framework.h"

namespace PlaylistManager
{
	struct FPlaylistInfo
	{
		FPlaylistInfo(string displayName, string assetPath, bool binfiniteAmmo = false, bool bbuildFree = false)
		{
			DisplayName = displayName;
			AssetPath = assetPath;

			bInfiniteAmmo = binfiniteAmmo;
			bBuildFree = bbuildFree;
		}

	public:
		string DisplayName;
		string AssetPath;

		bool bInfiniteAmmo;
		bool bBuildFree;

		FPlaylistInfo() = default;
	};

	static vector<FPlaylistInfo> Playlists {
		FPlaylistInfo("Solo", "/Game/Athena/Playlists/Playlist_DefaultSolo.Playlist_DefaultSolo"),
		FPlaylistInfo("Duos", "/Game/Athena/Playlists/Playlist_DefaultDuo.Playlist_DefaultDuo"),
		FPlaylistInfo("Squads", "/Game/Athena/Playlists/Playlist_DefaultSquad.Playlist_DefaultSquad"),
		FPlaylistInfo("Playground", "/Game/Athena/Playlists/Playground/Playlist_Playground.Playlist_Playground"),
		FPlaylistInfo("50v50", "/Game/Athena/Playlists/50v50/Playlist_50v50.Playlist_50v50"),
		FPlaylistInfo("Teams-of-20", "/Game/Athena/Playlists/5x20/Playlist_5x20.Playlist_5x20"),
		FPlaylistInfo("Blitz-Solo", "/Game/Athena/Playlists/Blitz/Playlist_Blitz_Solo.Playlist_Blitz_Solo"),
		FPlaylistInfo("Blitz-Duos", "/Game/Athena/Playlists/Blitz/Playlist_Blitz_Duos.Playlist_Blitz_Duos"),
		FPlaylistInfo("Blitz-Squads", "/Game/Athena/Playlists/Blitz/Playlist_Blitz_Squads.Playlist_Blitz_Squads"),
		FPlaylistInfo("High-Explosives-v2-Solo", "/Game/Athena/Playlists/HighExplosives/Playlist_HighExplosives_Solo.Playlist_HighExplosives_Solo"),
		FPlaylistInfo("High-Explosives-v2-Squads", "/Game/Athena/Playlists/HighExplosives/Playlist_HighExplosives_Squads.Playlist_HighExplosives_Squads"),
		FPlaylistInfo("Solid-Gold-Solo", "/Game/Athena/Playlists/SolidGold/Playlist_SolidGold_Solo.Playlist_SolidGold_Solo"),
		FPlaylistInfo("Solid-Gold-Squads", "/Game/Athena/Playlists/SolidGold/Playlist_SolidGold_Squads.Playlist_SolidGold_Squads"),
		FPlaylistInfo("Sky-Supply-Solo", "/Game/Athena/Playlists/SkySupply/Playlist_SkySupply.Playlist_SkySupply"),
		FPlaylistInfo("Snipers-Solo", "/Game/Athena/Playlists/Snipers/Playlist_Snipers_Solo.Playlist_Snipers_Solo"),
	};

	FPlaylistInfo* GetCurrentPlaylistInfo()
	{
		static FPlaylistInfo* CurrentPlaylistInfo = nullptr;

		if (!CurrentPlaylistInfo)
		{
			for (int i = 0; i < Playlists.size(); i++)
			{
				if (Playlists[i].DisplayName == Globals::CurrentPlaylistName)
					CurrentPlaylistInfo = &Playlists[i];
			}
		}

		if (!CurrentPlaylistInfo)
		{
			LogWarning("PlaylistManager::GetCurrentPlaylistInfo: Could not find Playlist, setting to Solo by default.");
			CurrentPlaylistInfo = &Playlists[0];
		}

		return CurrentPlaylistInfo;
	}

	UFortPlaylistAthena* GetCurrentPlaylist()
	{
		auto Playlist = GameHelper::FindObject<UFortPlaylistAthena>(GetCurrentPlaylistInfo()->AssetPath);
		return Playlist;
	}
}