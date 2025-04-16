#pragma once
#include "framework.h"

namespace LootManager
{
    struct LootDrop
    {
        FFortItemEntry* ItemEntry;

        FFortItemEntry* operator->() {
            return ItemEntry;
        }

        ~LootDrop()
        {

        }
    };

    static vector<string> Consumables{
    "Athena_Grenade",
    "Athena_DanceGrenade",
    "Athena_Bandage",
    "Athena_Medkit",
    "Athena_Shields",
    "Athena_Bush",
    "Athena_KnockGrenade",
    "Athena_StickyGrenade",
    "Athena_ShieldSmall",
    "Athena_PurpleStuff"
    };

    bool IsConsumable(UFortItemDefinition* ItemDefinition)
    {
        string ItemName = ItemDefinition->GetName();
        for (string Consumable : Consumables)
        {
            if (ItemName == Consumable)
                return true;
        }

        return false;
    }

    int GetClipSize(UFortWeaponItemDefinition* ItemDefinition)
    {
        if (ItemDefinition->GetName().contains("AGID_") || ItemDefinition->GetName().contains("ItemData") || ItemDefinition->GetName().contains("Consumables"))
            return -1;

        auto& WeaponStatHandle = ItemDefinition->WeaponStatHandle;

        auto Table = WeaponStatHandle.DataTable;

        if (!Table)
            return -1;

        auto& RowMap = Table->RowMap;

        for (int i = 0; i < RowMap.Num(); ++i)
        {
            auto& Pair = RowMap[i];

            if (Pair.Key() == WeaponStatHandle.RowName)
            {
                return reinterpret_cast<FFortRangedWeaponStats*>(Pair.Second)->ClipSize;
            }
        }

       return -1;
    }

    float RandomFloatForLoot(float AllWeightsSum)
    {
        return (rand() * 0.000030518509f) * AllWeightsSum;
    }

    template <typename KeyType, typename ValueType>
    ValueType PickWeightedElement(const std::map<KeyType, ValueType>& Elements,
        std::function<float(ValueType)> GetWeightFn,
        std::function<float(float)> RandomFloatGenerator = RandomFloatForLoot,
        float TotalWeightParam = -1, bool bCheckIfWeightIsZero = false, int RandMultiplier = 1, KeyType* OutName = nullptr, bool bPrint = false, bool bKeepGoingUntilWeGetValue = false)
    {
        float TotalWeight = TotalWeightParam;

        if (TotalWeight == -1)
        {
            TotalWeight = std::accumulate(Elements.begin(), Elements.end(), 0.0f, [&](float acc, const std::pair<KeyType, ValueType>& p) {
                auto Weight = GetWeightFn(p.second);
                return acc + Weight;
                });
        }

        float RandomNumber = RandMultiplier * RandomFloatGenerator(TotalWeight);

        for (auto& Element : Elements)
        {
            float Weight = GetWeightFn(Element.second);

            if (bCheckIfWeightIsZero && Weight == 0)
                continue;

            if (RandomNumber <= Weight)
            {
                if (OutName)
                    *OutName = Element.first;

                return Element.second;
            }

            RandomNumber -= Weight;
        }

        if (bKeepGoingUntilWeGetValue)
            return PickWeightedElement<KeyType, ValueType>(Elements, GetWeightFn, RandomFloatGenerator, TotalWeightParam, bCheckIfWeightIsZero, RandMultiplier, OutName, bPrint, bKeepGoingUntilWeGetValue);

        return ValueType();
    }

    FName RedirectLootTierGroup(FName LootTierGroup)
    {
        static FName Loot_TreasureFName = UKismetStringLibrary::Conv_StringToName(L"Loot_Treasure");
        static FName Loot_AmmoFName = UKismetStringLibrary::Conv_StringToName(L"Loot_Ammo");

        if (LootTierGroup == Loot_TreasureFName)
            return UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaTreasure");

        if (LootTierGroup == Loot_AmmoFName)
            return UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaAmmoLarge");
    }

    template <typename RowStructType = uint8>
    void CollectDataTablesRows(const std::vector<UDataTable*>& DataTables, map<FName, RowStructType*>* OutMap, std::function<bool(FName, RowStructType*)> Check = []() { return true; })
    {
        std::vector<UDataTable*> DataTablesToIterate;

        for (UDataTable* DataTable : DataTables)
        {
            if (!GameHelper::IsValidLowLevel(DataTable))
            {
                continue;
            }

            DataTablesToIterate.push_back(DataTable);
        }

        for (auto CurrentDataTable : DataTablesToIterate)
        {
            for (TPair<FName, uint8_t*>& CurrentPair : CurrentDataTable->RowMap)
            {
                if (Check(CurrentPair.Key(), (RowStructType*)CurrentPair.Value()))
                {
                    (*OutMap)[CurrentPair.Key()] = (RowStructType*)CurrentPair.Value();
                }
            }
        }
    }

    FFortLootTierData* PickLootTierData(const std::vector<UDataTable*>& LTDTables, FName LootTierGroup, int ForcedLootTier = -1, FName* OutRowName = nullptr)
    {
        float LootTier = ForcedLootTier;

        map<FName, FFortLootTierData*> TierGroupLTDs;

        CollectDataTablesRows<FFortLootTierData>(LTDTables, &TierGroupLTDs, [&](FName RowName, FFortLootTierData* TierData) -> bool {
            if (LootTierGroup == TierData->TierGroup)
            {
                if ((LootTier == -1 ? true : LootTier == TierData->LootTier))
                {
                    return true;
                }
            }

            return false;
            });

        int Multiplier = LootTier == -1 ? 1 : LootTier;

        FFortLootTierData* ChosenRowLootTierData = PickWeightedElement<FName, FFortLootTierData*>(TierGroupLTDs,
            [](FFortLootTierData* LootTierData) -> float { return LootTierData->Weight; }, RandomFloatForLoot, -1,
            true, Multiplier, OutRowName);

        return ChosenRowLootTierData;
    }

    int PickLevel(UFortWorldItemDefinition* ItemDefinition, int PreferredLevel) 
    {
        const int MinLevel = ItemDefinition->MinLevel;
        const int MaxLevel = ItemDefinition->MaxLevel;

        int PickedLevel = 0;

        if (PreferredLevel >= MinLevel)
            PickedLevel = PreferredLevel;

        if (MaxLevel >= 0)
        {
            if (PickedLevel <= MaxLevel)
                return PickedLevel;
            return MaxLevel;
        }

        return PickedLevel;
    }

    void PickLootDropsFromLootPackage(const std::vector<UDataTable*>& LPTables, const FName& LootPackageName, std::vector<LootDrop>* OutEntries, int LootPackageCategory = -1, int WorldLevel = 0, bool bPrint = false, bool bCombineDrops = true)
    {
        if (!OutEntries)
            return;

        map<FName, FFortLootPackageData*> LootPackageIDMap;

        CollectDataTablesRows<FFortLootPackageData>(LPTables, &LootPackageIDMap, [&](FName RowName, FFortLootPackageData* LootPackage) -> bool {
            if (LootPackage->LootPackageID != LootPackageName)
            {
                return false;
            }

            if (LootPackageCategory != -1 && LootPackage->LootPackageCategory != LootPackageCategory) // idk if proper
            {
                return false;
            }

            if (WorldLevel >= 0)
            {
                if (LootPackage->MaxWorldLevel >= 0 && WorldLevel > LootPackage->MaxWorldLevel)
                    return 0;

                if (LootPackage->MinWorldLevel >= 0 && WorldLevel < LootPackage->MinWorldLevel)
                    return 0;
            }

            return true;
            });

        if (LootPackageIDMap.size() == 0)
        {
            return;
        }

        FName PickedPackageRowName;
        FFortLootPackageData* PickedPackage = PickWeightedElement<FName, FFortLootPackageData*>(LootPackageIDMap,
            [](FFortLootPackageData* LootPackageData) -> float { return LootPackageData->Weight; }, RandomFloatForLoot,
            -1, true, 1, &PickedPackageRowName, bPrint);

        if (!PickedPackage)
            return;

        if (PickedPackage->LootPackageCall.Num() > 1)
        {
            if (PickedPackage->Count > 0)
            {
                int v9 = 0;

                while (v9 < PickedPackage->Count)
                {
                    int LootPackageCategoryToUseForLPCall = 0; // hmm

                    PickLootDropsFromLootPackage(LPTables,
                        PickedPackage->LootPackageCall.IsValid() ? UKismetStringLibrary::Conv_StringToName(PickedPackage->LootPackageCall) : FName(0),
                        OutEntries, LootPackageCategoryToUseForLPCall, WorldLevel, bPrint
                    );

                    v9++;
                }
            }

            return;
        }

        auto ItemDefinition = PickedPackage->ItemDefinition.Get();

        if (!ItemDefinition)
        {
            LogInfo("Loot Package {} does not contain a LootPackageCall or ItemDefinition.", PickedPackage->LootPackageID.ToString());
            return;
        }

        auto WeaponItemDefinition = static_cast<UFortWeaponItemDefinition*>(ItemDefinition);
        int LoadedAmmo = WeaponItemDefinition ? GetClipSize(WeaponItemDefinition) : 0;

        auto WorldItemDefinition = static_cast<UFortWorldItemDefinition*>(ItemDefinition);

        if (!WorldItemDefinition)
            return;

        int CountMultiplier = 1;
        int FinalCount = CountMultiplier * PickedPackage->Count;

        if (FinalCount > 0)
        {
            int FinalItemLevel = 0;

            while (FinalCount > 0)
            {
                int MaxStackSize = ItemDefinition->MaxStackSize;

                int CurrentCountForEntry = MaxStackSize;

                if (FinalCount <= MaxStackSize)
                    CurrentCountForEntry = FinalCount;

                if (CurrentCountForEntry <= 0)
                    CurrentCountForEntry = 0;

                auto ActualItemLevel = PickLevel(WorldItemDefinition, FinalItemLevel);

                bool bHasCombined = false;

                if (bCombineDrops)
                {
                    for (auto& CurrentLootDrop : *OutEntries)
                    {
                        if (CurrentLootDrop->ItemDefinition == ItemDefinition)
                        {
                            int NewCount = CurrentLootDrop->Count + CurrentCountForEntry;

                            if (NewCount <= ItemDefinition->MaxStackSize)
                            {
                                bHasCombined = true;
                                CurrentLootDrop->Count = NewCount;
                            }
                        }
                    }
                }

                if (!bHasCombined)
                {
                    FFortItemEntry* NewItemEntry = new FFortItemEntry();
                    NewItemEntry->ItemDefinition = ItemDefinition;
                    NewItemEntry->Count = CurrentCountForEntry;
                    NewItemEntry->LoadedAmmo = LoadedAmmo;
                    NewItemEntry->Durability = 0x3F800000;
                    NewItemEntry->Level = ActualItemLevel;

                    OutEntries->push_back(LootDrop(NewItemEntry));
                }

                FinalCount -= CurrentCountForEntry;
            }
        }
    }

    float GetAmountOfLootPackagesToDrop(FFortLootTierData* LootTierData, int OriginalNumberLootDrops)
    {
        if (LootTierData->LootPackageCategoryMinArray.Num() != LootTierData->LootPackageCategoryWeightArray.Num()
            || LootTierData->LootPackageCategoryMinArray.Num() != LootTierData->LootPackageCategoryMaxArray.Num())
            return 0;


        float MinimumLootDrops = 0;

        if (LootTierData->LootPackageCategoryMinArray.Num() > 0)
        {
            for (int i = 0; i < LootTierData->LootPackageCategoryMinArray.Num(); ++i)
            {
                MinimumLootDrops += LootTierData->LootPackageCategoryMinArray[i];
            }
        }

        if (MinimumLootDrops > OriginalNumberLootDrops)
        {
            LogInfo("Requested {} loot drops but minimum drops is {} for loot package {}", OriginalNumberLootDrops, MinimumLootDrops, LootTierData->LootPackage.ToString());
        }

        int SumLootPackageCategoryWeightArray = 0;

        if (LootTierData->LootPackageCategoryWeightArray.Num() > 0)
        {
            for (int i = 0; i < LootTierData->LootPackageCategoryWeightArray.Num(); ++i)
            {
                if (LootTierData->LootPackageCategoryWeightArray[i] > 0)
                {
                    auto LootPackageCategoryMaxArrayIt = LootTierData->LootPackageCategoryWeightArray[i];

                    if (LootPackageCategoryMaxArrayIt < 0 || 0 < LootPackageCategoryMaxArrayIt)
                    {
                        SumLootPackageCategoryWeightArray += LootTierData->LootPackageCategoryWeightArray[i];
                    }
                }
            }
        }

            while (SumLootPackageCategoryWeightArray > 0)
            {
                float v29 = (float)rand() * 0.000030518509f;

                float v35 = (int)(float)((float)((float)((float)SumLootPackageCategoryWeightArray * v29)
                    + (float)((float)SumLootPackageCategoryWeightArray * v29))
                    + 0.5f) >> 1;

                MinimumLootDrops++;

                if (MinimumLootDrops >= OriginalNumberLootDrops)
                    return MinimumLootDrops;

                SumLootPackageCategoryWeightArray--;
            }

        return MinimumLootDrops;
    }

    std::vector<LootDrop> PickLootDrops(FName TierGroupName, int WorldLevel, int ForcedLootTier = -1, bool bPrint = false, int recursive = 0, bool bCombineDrops = true)
    {
        std::vector<LootDrop> LootDrops;

        if (recursive > 6)
            return LootDrops;

        AFortGameStateAthena* GameState = Globals::GetGameState();

        static std::vector<UDataTable*> LTDTables;
        static std::vector<UDataTable*> LPTables;

        static int LastNum1 = 14915;

        UFortPlaylistAthena* CurrentPlaylist = PlaylistManager::GetCurrentPlaylist();

        LTDTables.clear();
        LPTables.clear();

        bool bFoundPlaylistTable = false;

        if (CurrentPlaylist)
        {
            auto& LootTierDataSoft = CurrentPlaylist->LootTierData;
            auto& LootPackagesSoft = CurrentPlaylist->LootPackages;

            if (LootTierDataSoft.ObjectID.AssetPathName.ComparisonIndex && LootPackagesSoft.ObjectID.AssetPathName.ComparisonIndex)
            {
                auto LootTierDataStr = LootTierDataSoft.ObjectID.AssetPathName.ToString();
                auto LootPackagesStr = LootPackagesSoft.ObjectID.AssetPathName.ToString();
                auto LootTierDataTableIsComposite = LootTierDataStr.contains("Composite");
                auto LootPackageTableIsComposite = LootPackagesStr.contains("Composite");

                UDataTable* StrongLootTierData = nullptr;
                UDataTable* StrongLootPackage = nullptr;

                StrongLootTierData = LootTierDataSoft.Get();
                StrongLootPackage = LootPackagesSoft.Get();

                if (StrongLootTierData && StrongLootPackage)
                {
                    LTDTables.push_back(StrongLootTierData);
                    LPTables.push_back(StrongLootPackage);

                    bFoundPlaylistTable = true;
                }
            }
        }

        if (!bFoundPlaylistTable)
        {
            LTDTables.push_back(GameHelper::FindObject<UDataTable>("/Game/Items/Datatables/AthenaLootTierData_Client.AthenaLootTierData_Client"));
            LPTables.push_back(GameHelper::FindObject<UDataTable>("/Game/Items/Datatables/AthenaLootPackages_Client.AthenaLootPackages_Client"));
        }


        for (int i = 0; i < LTDTables.size(); ++i)
        {
            auto& Table = LTDTables.at(i);

            if (!GameHelper::IsValidLowLevel(Table))
            {
                continue;
            }
        }

        for (int i = 0; i < LPTables.size(); ++i)
        {
            auto& Table = LPTables.at(i);

            if (!GameHelper::IsValidLowLevel(Table))
            {
                continue;
            }
        }

        if (LTDTables.size() <= 0 || LPTables.size() <= 0)
        {
            LogWarning("Empty tables! ({} {})", LTDTables.size(), LPTables.size());
            return LootDrops;
        }

        FName LootTierRowName;
        auto ChosenRowLootTierData = PickLootTierData(LTDTables, TierGroupName, ForcedLootTier, &LootTierRowName);

        if (!ChosenRowLootTierData)
        {
            LogInfo("Failed to find LootTierData row for {} with loot tier {}", TierGroupName.ToString(), ForcedLootTier);
            return LootDrops;
        }

        float NumLootPackageDrops = ChosenRowLootTierData->NumLootPackageDrops;

        float NumberLootDrops = 0;

        if (NumLootPackageDrops > 0)
        {
            if (NumLootPackageDrops < 1)
            {
                NumberLootDrops = 1;
            }
            else
            {
                NumberLootDrops = (int)(float)((float)(NumLootPackageDrops + NumLootPackageDrops) - 0.5f) >> 1;
                float v20 = NumLootPackageDrops - NumberLootDrops;
                if (v20 > 0.0000099999997f)
                {
                    NumberLootDrops += v20 >= (rand() * 0.000030518509f);
                }
            }
        }

        float AmountOfLootPackageDrops = GetAmountOfLootPackagesToDrop(ChosenRowLootTierData, NumberLootDrops);

        LootDrops.reserve(AmountOfLootPackageDrops);

        if (AmountOfLootPackageDrops > 0)
        {
            for (int i = 0; i < AmountOfLootPackageDrops; ++i)
            {
                if (i >= ChosenRowLootTierData->LootPackageCategoryMinArray.Num())
                    break;

                for (int j = 0; j < ChosenRowLootTierData->LootPackageCategoryMinArray[i]; ++j)
                {
                    if (ChosenRowLootTierData->LootPackageCategoryMinArray[i] < 1)
                        break;

                    int LootPackageCategory = i;

                    PickLootDropsFromLootPackage(LPTables, ChosenRowLootTierData->LootPackage, &LootDrops, LootPackageCategory, WorldLevel, bPrint);
                }
            }
        }

        return LootDrops;
    }

    void SpawnFloorLoot()
    {
        auto SpawnIsland_FloorLoot = GameHelper::FindObject<UClass>("/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_Warmup.Tiered_Athena_FloorLoot_Warmup_C");
        auto BRIsland_FloorLoot = GameHelper::FindObject<UClass>("/Game/Athena/Environments/Blueprints/Tiered_Athena_FloorLoot_01.Tiered_Athena_FloorLoot_01_C");

        TArray<AActor*> SpawnIsland_FloorLoot_Actors;
        UGameplayStatics::GetAllActorsOfClass(UWorld::GetWorld(), SpawnIsland_FloorLoot, &SpawnIsland_FloorLoot_Actors);
        TArray<AActor*> BRIsland_FloorLoot_Actors;
        UGameplayStatics::GetAllActorsOfClass(UWorld::GetWorld(), BRIsland_FloorLoot, &BRIsland_FloorLoot_Actors);

        auto SpawnIslandTierGroup = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaFloorLoot_Warmup");
        auto BRIslandTierGroup = UKismetStringLibrary::Conv_StringToName(L"Loot_AthenaFloorLoot");

        for (int i = 0; i < SpawnIsland_FloorLoot_Actors.Num(); i++)
        {
            ABuildingContainer* CurrentActor = (ABuildingContainer*)SpawnIsland_FloorLoot_Actors[i];
            auto Location = CurrentActor->K2_GetActorLocation() + CurrentActor->GetActorForwardVector() * CurrentActor->LootSpawnLocation_Athena.X + CurrentActor->GetActorRightVector() * CurrentActor->LootSpawnLocation_Athena.Y + CurrentActor->GetActorUpVector() * CurrentActor->LootSpawnLocation_Athena.Z;

            std::vector<LootDrop> LootDrops = PickLootDrops(SpawnIslandTierGroup, Globals::GetGameState()->WorldLevel);

            for (auto& LootDrop : LootDrops)
            {
                    GameHelper::SpawnPickup(LootDrop.ItemEntry, Location);
            }

            CurrentActor->K2_DestroyActor();
        }

        int spawned = 0;

        for (int i = 0; i < BRIsland_FloorLoot_Actors.Num(); i++)
        {
            ABuildingContainer* CurrentActor = (ABuildingContainer*)BRIsland_FloorLoot_Actors[i];
            spawned++;

            auto Location = CurrentActor->K2_GetActorLocation() + CurrentActor->GetActorForwardVector() * CurrentActor->LootSpawnLocation_Athena.X + CurrentActor->GetActorRightVector() * CurrentActor->LootSpawnLocation_Athena.Y + CurrentActor->GetActorUpVector() * CurrentActor->LootSpawnLocation_Athena.Z;

            std::vector<LootDrop> LootDrops = PickLootDrops(BRIslandTierGroup, Globals::GetGameState()->WorldLevel);

            for (auto& LootDrop : LootDrops)
            {
                    GameHelper::SpawnPickup(LootDrop.ItemEntry, Location);
            }

            CurrentActor->K2_DestroyActor();
        }

        SpawnIsland_FloorLoot_Actors.Free();
        BRIsland_FloorLoot_Actors.Free();

    }
}