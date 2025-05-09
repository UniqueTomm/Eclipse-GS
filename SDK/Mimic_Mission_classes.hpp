#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Mimic_Mission

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "FortniteGame_structs.hpp"
#include "FortniteGame_classes.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass Mimic_Mission.Mimic_Mission_C
// 0x0158 (0x07E8 - 0x0690)
class AMimic_Mission_C final : public AFortMission
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0690(0x0008)(Transient, DuplicateTransient)
	class USceneComponent*                        DefaultSceneRoot;                                  // 0x0698(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class AHuskPawn_Mimic_C*                      MimicPawn;                                         // 0x06A0(0x0008)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         SavedMimicHealth;                                  // 0x06A8(0x0004)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_6AC[0x4];                                      // 0x06AC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FGameplayTagContainer                  KillMimicObjectiveHandle;                          // 0x06B0(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   DefeatMimicText;                                   // 0x06D0(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTagContainer                  ChestInteractObjectiveHandle;                      // 0x06E8(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	class AMimic_Chest_C*                         MimicChest;                                        // 0x0708(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FText                                   FindMimicText;                                     // 0x0710(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FFortMissionWeightedReward             ChosenReward;                                      // 0x0728(0x0098)(Edit, BlueprintVisible, DisableEditOnInstance)
	class FText                                   MimicHealthBarText;                                // 0x07C0(0x0018)(Edit, BlueprintVisible, DisableEditOnInstance)
	class UFortAIEncounterInfo*                   Encounter;                                         // 0x07D8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	EFortObjectiveStatus                          ObjectiveStatus;                                   // 0x07E0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_Mimic_Mission(int32 EntryPoint);
	void Event_OnMimicDestroyed(class AActor* DestroyedActor);
	void BlueprintOnActivated();
	void OnMimicChestDamaged(class AActor* DamagedActor, float Damage, class AController* InstigatedBy, class AActor* DamageCauser, const struct FVector& HitLocation, class UPrimitiveComponent* FHitComponent, class FName BoneName, const struct FVector& Momentum);
	void OnInteractingPlayerDied_Event(class AActor* DamagedActor, float Damage, class AController* InstigatedBy, class AActor* DamageCauser, const struct FVector& HitLocation, class UPrimitiveComponent* FHitComponent, class FName BoneName, const struct FVector& Momentum);
	void OnEncounterEnemySpawned(class UFortAIEncounterInfo* Param_Encounter, class AFortAIPawn* SpawnedEnemy);
	void OnMimicDied_Event(class AActor* DamagedActor, float Damage, class AController* InstigatedBy, class AActor* DamageCauser, const struct FVector& HitLocation, class UPrimitiveComponent* FHitComponent, class FName BoneName, const struct FVector& Momentum);
	void HandleMissionEvent_LocateSecondary(const struct FGuid& InMissionGuid, const struct FGameplayTagContainer& ObjectiveHandle, class UFortMissionEventParams* Params_0, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, class UObject* EventFocus, const class UDataAsset* EventContent, class AActor* EventInstigator, int32 GenericInt, float GenericFloat, const class FText& GenericText, const struct FGameplayTagContainer& GameplayTags, const struct FFortMissionEvent& MissionEvent);
	void HandleMissionEvent_ObjectiveSucceeded(const struct FGuid& InMissionGuid, const struct FGameplayTagContainer& ObjectiveHandle, class UFortMissionEventParams* Params_0, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, class UObject* EventFocus, const class UDataAsset* EventContent, class AActor* EventInstigator, int32 GenericInt, float GenericFloat, const class FText& GenericText, const struct FGameplayTagContainer& GameplayTags, const struct FFortMissionEvent& MissionEvent);
	void HandleMissionEvent_MissionSucceeded(const struct FGuid& InMissionGuid, const struct FGameplayTagContainer& ObjectiveHandle, class UFortMissionEventParams* Params_0, bool DO_NOT_USE_THIS_OR_VARIABLES_BELOW, class UObject* EventFocus, const class UDataAsset* EventContent, class AActor* EventInstigator, int32 GenericInt, float GenericFloat, const class FText& GenericText, const struct FGameplayTagContainer& GameplayTags, const struct FFortMissionEvent& MissionEvent);
	void UserConstructionScript();
	void InitMission();
	void RestartDormantChest();
	void TryGiveRewards();
	void InitializeMimicChest(class AMimic_Chest_C* Param_MimicChest, bool bWakeOnDamage);
	void HideFoundMimicText();
	void OnChestInteract();
	void OnMimicSpawned(class AHuskPawn_Mimic_C* Param_MimicPawn);

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Mimic_Mission_C">();
	}
	static class AMimic_Mission_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AMimic_Mission_C>();
	}
};
static_assert(alignof(AMimic_Mission_C) == 0x000008, "Wrong alignment on AMimic_Mission_C");
static_assert(sizeof(AMimic_Mission_C) == 0x0007E8, "Wrong size on AMimic_Mission_C");
static_assert(offsetof(AMimic_Mission_C, UberGraphFrame) == 0x000690, "Member 'AMimic_Mission_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, DefaultSceneRoot) == 0x000698, "Member 'AMimic_Mission_C::DefaultSceneRoot' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, MimicPawn) == 0x0006A0, "Member 'AMimic_Mission_C::MimicPawn' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, SavedMimicHealth) == 0x0006A8, "Member 'AMimic_Mission_C::SavedMimicHealth' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, KillMimicObjectiveHandle) == 0x0006B0, "Member 'AMimic_Mission_C::KillMimicObjectiveHandle' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, DefeatMimicText) == 0x0006D0, "Member 'AMimic_Mission_C::DefeatMimicText' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, ChestInteractObjectiveHandle) == 0x0006E8, "Member 'AMimic_Mission_C::ChestInteractObjectiveHandle' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, MimicChest) == 0x000708, "Member 'AMimic_Mission_C::MimicChest' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, FindMimicText) == 0x000710, "Member 'AMimic_Mission_C::FindMimicText' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, ChosenReward) == 0x000728, "Member 'AMimic_Mission_C::ChosenReward' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, MimicHealthBarText) == 0x0007C0, "Member 'AMimic_Mission_C::MimicHealthBarText' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, Encounter) == 0x0007D8, "Member 'AMimic_Mission_C::Encounter' has a wrong offset!");
static_assert(offsetof(AMimic_Mission_C, ObjectiveStatus) == 0x0007E0, "Member 'AMimic_Mission_C::ObjectiveStatus' has a wrong offset!");

}

