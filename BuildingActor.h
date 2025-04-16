#pragma once
#include "framework.h"

namespace BuildingActor
{
    void (*oOnDamageServer)(ABuildingActor*, float, FGameplayTagContainer, FVector, FHitResult, AActor*, AActor*, FGameplayEffectContextHandle);
    void hkOnDamageServer(ABuildingActor* Actor, float Damage, FGameplayTagContainer DamageTags, FVector Momentum, FHitResult HitInfo, AActor* InstigatedBy, AActor* DamageCauser, FGameplayEffectContextHandle EffectContext)
    {
        auto BuildingActor = reinterpret_cast<ABuildingSMActor*>(Actor);
        if (!BuildingActor)
            return oOnDamageServer(Actor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

        if (!DamageCauser->IsA(AFortWeapon::StaticClass()))
            return oOnDamageServer(Actor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

        auto Weapon = reinterpret_cast<AFortWeapon*>(DamageCauser);
        if (!Weapon)
            return oOnDamageServer(Actor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

        if (!Weapon->WeaponData->IsA(UFortWeaponMeleeItemDefinition::StaticClass()))
            return oOnDamageServer(Actor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

        auto PlayerController = reinterpret_cast<AFortPlayerControllerAthena*>(InstigatedBy);
        if (!PlayerController)
            return oOnDamageServer(Actor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

        auto PlayerPawn = reinterpret_cast<AFortPlayerPawn*>(PlayerController->Pawn);
        if (!PlayerPawn)
            return oOnDamageServer(Actor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

        if (BuildingActor->bDestroyed || BuildingActor->bPlayerPlaced)
            return oOnDamageServer(Actor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

        bool bWeakSpotHit = (Damage == 100.f);


        auto ResourceDefinition = UFortKismetLibrary::K2_GetResourceItemDefinition(BuildingActor->ResourceType);
        if (!ResourceDefinition)
            return oOnDamageServer(Actor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);

        FCurveTableRowHandle BuildingResourceAmountOverride = BuildingActor->BuildingResourceAmountOverride;

        int ResourceAmount = 0;

        if (BuildingResourceAmountOverride.RowName.ComparisonIndex)
        {
            UCurveTable* ResourceRates = PlaylistManager::GetCurrentPlaylist()->ResourceRates.Get();

            if (!ResourceRates)
                ResourceRates = GameHelper::FindObject<UCurveTable>("/Game/Athena/Balance/DataTables/AthenaResourceRates.AthenaResourceRates");

            float AmountOut = 0;

            UDataTableFunctionLibrary::EvaluateCurveTableRow(ResourceRates, BuildingResourceAmountOverride.RowName, 0.f, nullptr, &AmountOut, L"");

            float Amount = AmountOut / (BuildingActor->GetMaxHealth() / Damage);
            ResourceAmount = round(Amount);
        }

        if (BuildingActor->ResourceType == EFortResourceType::Wood)
            PlayerController->MatchReport->Stats.GatheredWood += ResourceAmount;
        else if (BuildingActor->ResourceType == EFortResourceType::Stone)
            PlayerController->MatchReport->Stats.GatheredStone += ResourceAmount;
        else if (BuildingActor->ResourceType == EFortResourceType::Metal)
            PlayerController->MatchReport->Stats.GatheredMetal += ResourceAmount;

        PlayerController->MatchReport->Stats.MaterialsGathered += ResourceAmount;

        PlayerController->ClientReportDamagedResourceBuilding(BuildingActor, BuildingActor->ResourceType, ResourceAmount, Actor->bDestroyed, bWeakSpotHit);

        Inventory::AddItem(PlayerController, ResourceDefinition, ResourceAmount);

        oOnDamageServer(Actor, Damage, DamageTags, Momentum, HitInfo, InstigatedBy, DamageCauser, EffectContext);
    }
    void Initialize()
    {
        HookingManager::CreateHook(Memory::GetAddress(LOffsets::OnDamageServer), hkOnDamageServer, (void**)&oOnDamageServer);
        LogInfo("BuildingActor: Initialized.");
    }
}