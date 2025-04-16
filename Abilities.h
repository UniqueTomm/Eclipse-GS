#pragma once
#include "framework.h"

namespace Abilities
{
    FGameplayAbilitySpecHandle* (*GiveAbility)(UAbilitySystemComponent* _this, FGameplayAbilitySpecHandle* outHandle, FGameplayAbilitySpec inSpec) = decltype(GiveAbility)(Memory::GetAddress(LOffsets::GiveAbility));
    __int64 (*oGiveAbilityAndActivateOnce)(void*, FGameplayAbilitySpecHandle*, FGameplayAbilitySpec) = decltype(oGiveAbilityAndActivateOnce)(Memory::GetAddress(LOffsets::GiveAbilityAndActivateOnce));
    bool (*InternalTryActivateAbility)(UAbilitySystemComponent* _this, FGameplayAbilitySpecHandle Handle, FPredictionKey InPredictionKey, UGameplayAbility** OutInstancedAbility, void* OnGameplayAbilityEndedDelegate, FGameplayEventData* TriggerEventData) = decltype(InternalTryActivateAbility)(Memory::GetAddress(LOffsets::InternalTryActivateAbility));
    __int64 (*SpecConstructor)(FGameplayAbilitySpec* spec, UObject* Ability, int Level, int InputID, UObject* SourceObject) = decltype(SpecConstructor)(Memory::GetAddress(LOffsets::SpecConstructor));

    FGameplayAbilitySpec* FindAbilitySpecFromHandle(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAbilitySpecHandle Handle)
    {
        for (int i = 0; i < AbilitySystemComponent->ActivatableAbilities.Items.Num(); i++)
        {
            if (AbilitySystemComponent->ActivatableAbilities.Items[i].Handle.Handle == Handle.Handle)
            {
                return &AbilitySystemComponent->ActivatableAbilities.Items[i];
            }
        }

        return nullptr;
    }

    void hkInternalServerTryActivateAbility(UAbilitySystemComponent* ASc, FGameplayAbilitySpecHandle Handle, bool InputPressed, const FPredictionKey& PredictionKey, FGameplayEventData* TriggerEventData)
    {
        FGameplayAbilitySpec* Spec = FindAbilitySpecFromHandle(ASc, Handle);
        if (!Spec)
        {
            ASc->ClientActivateAbilityFailed(Handle, PredictionKey.Current);
            return;
        }

        const UGameplayAbility* AbilityToActivate = Spec->Ability;

        UGameplayAbility* InstancedAbility = nullptr;
        Spec->InputPressed = true;

        if (InternalTryActivateAbility(ASc, Handle, PredictionKey, &InstancedAbility, nullptr, TriggerEventData))
        {
        }
        else
        {
            ASc->ClientActivateAbilityFailed(Handle, PredictionKey.Current);
            Spec->InputPressed = false;
            ASc->ActivatableAbilities.MarkItemDirty(*Spec);
        }
    }

    FGameplayAbilitySpec* FindGameplayAbility(AFortPlayerStateAthena* PlayerState, UGameplayAbility* GameplayAbility)
    {
        auto AbilitySystemComponent = PlayerState->AbilitySystemComponent;
        if (!AbilitySystemComponent)
        {
            LogWarning("AbilitySystemComponent is null for PlayerState");
            return nullptr;
        }

        for (int i = 0; i < AbilitySystemComponent->ActivatableAbilities.Items.Num(); i++)
        {
            auto& Spec = AbilitySystemComponent->ActivatableAbilities.Items[i];
            if (!Spec.Ability)
            {
                LogWarning("Null Ability found at index {}", i);
                continue;
            }

            LogInfo("Ability [{}]: {}", i, Spec.Ability->GetName());

            if (Spec.Ability == GameplayAbility)
            {
                LogInfo("Found Spec for {}", GameplayAbility->GetName());
                return &Spec;
            }
        }

        LogWarning("Couldn't find spec for {}", GameplayAbility->GetName());
        return nullptr;
    }
    void RemoveGameplayAbility(AFortPlayerStateAthena* PlayerState, UGameplayAbility* GameplayAbility)
    {
        if (!GameplayAbility)
            return;

        LogInfo("GameplayAbility Class: {}", GameplayAbility->GetName());

        auto AbilitySystemComponent = PlayerState->AbilitySystemComponent;
        if (!AbilitySystemComponent)
            return;

        FGameplayAbilitySpec* AbilitySpec = FindGameplayAbility(PlayerState, GameplayAbility);

        if (!AbilitySpec)
        {
            LogWarning("Couldn't find spec for {}", GameplayAbility->GetFullName());
            return;
        }

        AbilitySystemComponent->ClientCancelAbility(AbilitySpec->Handle, AbilitySpec->ActivationInfo);
        AbilitySystemComponent->ClientEndAbility(AbilitySpec->Handle, AbilitySpec->ActivationInfo);
        AbilitySystemComponent->ServerEndAbility(AbilitySpec->Handle, AbilitySpec->ActivationInfo, {}); // ClearAbility ???
    }

    void GrantGameplayAbility(AFortPlayerStateAthena* PlayerState, UClass* GameplayAbilityClass)
    {
        auto AbilitySystemComponent = PlayerState->AbilitySystemComponent;

        if (!AbilitySystemComponent)
            return;

        FGameplayAbilitySpec NewSpec{};

        SpecConstructor(&NewSpec, GameplayAbilityClass->DefaultObject, 1, -1, nullptr);
        GiveAbility(AbilitySystemComponent, &NewSpec.Handle, NewSpec);
        return;
    }

    void ApplyAbilities(AFortPlayerStateAthena* PlayerState)
    {
        static auto AbilitySet = GameHelper::FindObject<UFortAbilitySet>("/Game/Abilities/Player/Generic/Traits/DefaultPlayer/GAS_DefaultPlayer.GAS_DefaultPlayer");
        TArray<TSubclassOf<UFortGameplayAbility>> GameplayAbilities = AbilitySet->GameplayAbilities;
        for (int i = 0; i < GameplayAbilities.Num(); i++)
        {
            GrantGameplayAbility(PlayerState, GameplayAbilities[i].Get());
        }

       /* 
        static auto Jump = UObject::FindObjectFast<UGameplayAbility>("Default__FortGameplayAbility_Jump");
        static auto Sprint = UObject::FindObjectFast<UGameplayAbility>("Default__FortGameplayAbility_Sprint");
        static auto Reload = UObject::FindObjectFast<UGameplayAbility>("Default__FortGameplayAbility_Reload");
        static auto RangedWeapon = UObject::FindObjectFast<UGameplayAbility>("Default__FortGameplayAbility_RangedWeapon");
        static auto Consumable = UObject::FindObjectFast<UGameplayAbility>("Default__GA_DefaultPlayer_Consumable_C");
        static auto Use = UObject::FindObjectFast<UGameplayAbility>("Default__GA_DefaultPlayer_InteractUse_C");
        static auto Search = UObject::FindObjectFast<UGameplayAbility>("Default__GA_DefaultPlayer_InteractSearch_C");
        static auto Death = UObject::FindObjectFast<UGameplayAbility>("Default__GA_DefaultPlayer_Death_C");
        static auto Boogie = UObject::FindObjectFast<UGameplayAbility>("Default__GA_DanceGrenade_Stun_C");
        static auto Trap = UObject::FindObjectFast<UGameplayAbility>("Default__GA_TrapBuildGeneric_C");
        static auto DBNO = UObject::FindObjectFast<UGameplayAbility>("Default__GAB_PlayerDBNO_C");
        static auto AthenaDBNO = UObject::FindObjectFast<UGameplayAbility>("Default__GAB_AthenaDBNO_C");
        static auto DBNORevive = UObject::FindObjectFast<UGameplayAbility>("Default__GAB_AthenaDBNORevive_C");
        static auto DBNOResurrect = UObject::FindObjectFast<UGameplayAbility>("Default__GAB_PlayerDBNOResurrect_C");

        GrantGameplayAbility(PlayerState, Jump->Class);
        GrantGameplayAbility(PlayerState, Sprint->Class);
        GrantGameplayAbility(PlayerState, Reload->Class);
        GrantGameplayAbility(PlayerState, RangedWeapon->Class);
        GrantGameplayAbility(PlayerState, Consumable->Class);
        GrantGameplayAbility(PlayerState, Use->Class);
        GrantGameplayAbility(PlayerState, Search->Class);
        GrantGameplayAbility(PlayerState, Death->Class);
        GrantGameplayAbility(PlayerState, Boogie->Class);
        GrantGameplayAbility(PlayerState, Trap->Class);
        GrantGameplayAbility(PlayerState, DBNO->Class);
        GrantGameplayAbility(PlayerState, AthenaDBNO->Class);
        GrantGameplayAbility(PlayerState, DBNORevive->Class);
        GrantGameplayAbility(PlayerState, DBNOResurrect->Class);
        */
    }

    void Initialize()
    {
        auto DefaultObject = UFortAbilitySystemComponentAthena::StaticClass()->DefaultObject;

        HookingManager::VirtualHook(DefaultObject, 0xCB, hkInternalServerTryActivateAbility);

        LogInfo("Abilities: Initialized.");
    }
}