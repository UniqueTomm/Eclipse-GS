#include "framework.h"

#include "TestHooks.h"
#include "CheatChecker.h"
#include "BuildingActor.h"
#include "FortPickup.h"
#include "GameMode.h"
#include "PlayerController.h"
#include "Pawn.h"
#include "FortWeapon.h"

DWORD Initialize(LPVOID lpReserved)
{
    AllocConsole();
    FILE* File;
    freopen_s(&File, "CONOUT$", "w+", stdout);
    SetConsoleTitleA("Eclipse");

    MH_Initialize();

    *(uint8_t*)(Memory::GetAddress(0x255BB17) + 7) = 0x74;
    LogInfo("Matchmaking should now be supported.");


    UKismetSystemLibrary::ExecuteConsoleCommand(UWorld::GetWorld(), L"open Athena_Terrain", nullptr);
    UWorld::GetWorld()->OwningGameInstance->LocalPlayers.Remove(0);

   for (uintptr_t FuncToNull : vector<uintptr_t> {0xa767b0, 0xc22e90, 0xf1c000})
    {
        uintptr_t func = Memory::GetAddress(FuncToNull);
        DWORD dwProtection;
        VirtualProtect((PVOID)func, 1, PAGE_EXECUTE_READWRITE, &dwProtection);
        *(uint8_t*)func = 0xC3;
        DWORD dwTemp;
        VirtualProtect((PVOID)func, 1, dwProtection, &dwTemp);
    }

    auto ByteToPatch = (uint8_t*)(uint8_t*)(Memory::GetAddress(0x9eb786));
    DWORD dwProtection;
    VirtualProtect((PVOID)ByteToPatch, 1, PAGE_EXECUTE_READWRITE, &dwProtection);
    *ByteToPatch = 0x85;
    DWORD dwTemp;
    VirtualProtect((PVOID)ByteToPatch, 1, dwProtection, &dwTemp);
    
    *(bool*)Memory::GetAddress(LOffsets::GIsClient) = false;

    GameMode::Initialize();
    PlayerController::Initialize();
    Pawn::Initialize();
    FortWeapon::Initialize();
    Abilities::Initialize();
    CheatChecker::Initialize();
    FortPickup::Initialize();
    TestHooks::Initialize();
    Quests::Initialize();

    MH_EnableHook(MH_ALL_HOOKS);

    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ulReason, LPVOID lpReserved)
{
    switch (ulReason)
    {
    case DLL_PROCESS_ATTACH:
        CreateThread(nullptr, 0, Initialize, 0, 0, nullptr);
        break;
        break;
    }
    return TRUE;
}

