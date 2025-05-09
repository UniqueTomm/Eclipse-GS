#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SmasherPawn

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "Engine_structs.hpp"
#include "GameplayTags_structs.hpp"
#include "CoreUObject_structs.hpp"
#include "EnemyPawn_Parent_classes.hpp"
#include "GameplayAbilities_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass SmasherPawn.SmasherPawn_C
// 0x0190 (0x2170 - 0x1FE0)
class ASmasherPawn_C final : public AEnemyPawn_Parent_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_SmasherPawn_C;                      // 0x1FE0(0x0008)(Transient, DuplicateTransient)
	class UBoxComponent*                          KeepChargingBox;                                   // 0x1FE8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          ChargeMeleeSwingBox;                               // 0x1FF0(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          CrushBox;                                          // 0x1FF8(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        SFX_Club_Drag;                                     // 0x2000(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               Effect_Club_Drag;                                  // 0x2008(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UCapsuleComponent*                      PushCapsule;                                       // 0x2010(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	float                                         Timeline_3_ColorFadeOutTrack_676F16694C256D56DC409C8D204D89A8; // 0x2018(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Timeline_3_FadeInTrack_676F16694C256D56DC409C8D204D89A8; // 0x201C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Timeline_3__Direction_676F16694C256D56DC409C8D204D89A8; // 0x2020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2021[0x7];                                     // 0x2021(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Timeline_3;                                        // 0x2028(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         RippleTime;                                        // 0x2030(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CanRippleAgain;                                    // 0x2034(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2035[0x3];                                     // 0x2035(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CurrentJiggleAnimation;                            // 0x2038(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         RippleDamageAmount;                                // 0x203C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Dying;                                             // 0x2040(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2041[0x3];                                     // 0x2041(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         PushRadius;                                        // 0x2044(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               OriginalRotationRate;                              // 0x2048(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          CustomizeEyeColor;                                 // 0x2054(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2055[0x3];                                     // 0x2055(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	struct FLinearColor                           EyeColor_PlayerNotBeingTracked;                    // 0x2058(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           EyeColor_PlayerBeingTracked;                       // 0x2068(0x0010)(Edit, BlueprintVisible, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   Impact_MeleeSocket;                                // 0x2078(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ImpactParticles_Default;                           // 0x2080(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ImpactParticles_Wood;                              // 0x2088(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ImpactParticles_Stone;                             // 0x2090(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ImpactParticles_Metal;                             // 0x2098(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ImpactParticles_HumanFlesh;                        // 0x20A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          MeleeImpact_UseSocketTransforms;                   // 0x20A8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_20A9[0x7];                                     // 0x20A9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class AActor*                                 ActorOverlappingCrushBox;                          // 0x20B0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTag                           CrushTag;                                          // 0x20B8(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	struct FGameplayTagContainer                  SpawnRoarTag;                                      // 0x20C0(0x0020)(Edit, BlueprintVisible, DisableEditOnInstance)
	struct FGameplayTag                           ProhibitBumpDamageTag;                             // 0x20E0(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor, HasGetValueTypeHash)
	float                                         SmasherMaxCrushVolumeMult;                         // 0x20E8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DebugSmasherCrushing;                              // 0x20EC(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_20ED[0x3];                                     // 0x20ED(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UParticleSystemComponent*               Death_Effects_SmasherPawn_C;                       // 0x20F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCurveFloat*                            Curve_Smasher_EyeClose;                            // 0x20F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCurveFloat*                            Curve_Smasher_LerpToNewEyeColorToIndicatePlayerTracking; // 0x2100(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCurveLinearColor*                      Smasher_RedEyeColorCurve;                          // 0x2108(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Play_Smasher_Eye_Effects_In_Reverse;               // 0x2110(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_2111[0x3];                                     // 0x2111(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         Smasher_Eye_Close_Animation_Length;                // 0x2114(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FriendlyPawnPushDuration;                          // 0x2118(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FriendlyPawnPushVelocity;                          // 0x211C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FriendlyPawnPushYawAngle;                          // 0x2120(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         EnemyPawnKnockbackVelocity;                        // 0x2124(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         EnemyPawnKnockbackZAngle;                          // 0x2128(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         EnemyPawnKnockbackYawAngle;                        // 0x212C(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AFortPawn*                              PawnBumpedBySmasher;                               // 0x2130(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	TArray<class AActor*>                         ActorsDamagedByCharge;                             // 0x2138(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate)
	class USkeletalMeshComponent*                 ShieldSkeletalMesh;                                // 0x2148(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AShielderSpringArm_C*                   ShieldArm;                                         // 0x2150(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Smasher_ImpactSound;                               // 0x2158(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             Smasher;                                           // 0x2160(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_SmasherPawn(int32 EntryPoint);
	void OnPushCapsuleBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void GameplayCue_Damage_Shielded(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void GameplayCue_Shield_Destroyed(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void GameplayCue_Shield_Reapplied(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void GameplayCue_NPC_Smasher_Charge(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void OnDamagePlayEffects(float Damage, const struct FGameplayTagContainer& DamageTags, const struct FVector& Momentum, const struct FHitResult& HitInfo, class AFortPawn* InstigatedBy, class AActor* DamageCauser, const struct FGameplayEffectContextHandle& EffectContext);
	void GameplayCue_Impact_Physical_Creature(EGameplayCueEvent EventType, const struct FGameplayCueParameters& Parameters);
	void Trigger_Death_Effect();
	void HitSoundVocalTimeout();
	void HitSoundTimeout();
	void OnCrushBoxBeginOverlap(class UPrimitiveComponent* OverlappedComponent, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const struct FHitResult& SweepResult);
	void InitializeCrushing();
	void Timeline_3__Spawn__EventFunc();
	void Timeline_3__UpdateFunc();
	void Timeline_3__FinishedFunc();
	void CalculateBumpMomentum(float Velocity, float YawAngle, class AFortPawn* BumpedPawn, struct FVector* BumpMomentum);
	void OnFinishedEncounterSpawn();
	void OnStartedEncounterSpawn();
	void OnDeathPlayEffects(float Damage, const struct FGameplayTagContainer& DamageTags, const struct FVector& Momentum, const struct FHitResult& HitInfo, class AFortPawn* InstigatedBy, class AActor* DamageCauser, const struct FGameplayEffectContextHandle& EffectContext);
	void ReceiveBeginPlay();
	void PaceHitSoundsAndVocalizations(EFortDamageZone Damage_Zone);
	void HandleHitEffects(float Damage, struct FHitResult& HitInfo);
	void ResetSmasherRotationRateToDefault();
	void SetSmasherRotationRate(float YawRate);
	void GetCollisionPredictionComponent(class UShapeComponent** Collision_Prediction_Shape_Component);
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SmasherPawn_C">();
	}
	static class ASmasherPawn_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ASmasherPawn_C>();
	}
};
static_assert(alignof(ASmasherPawn_C) == 0x000010, "Wrong alignment on ASmasherPawn_C");
static_assert(sizeof(ASmasherPawn_C) == 0x002170, "Wrong size on ASmasherPawn_C");
static_assert(offsetof(ASmasherPawn_C, UberGraphFrame_SmasherPawn_C) == 0x001FE0, "Member 'ASmasherPawn_C::UberGraphFrame_SmasherPawn_C' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, KeepChargingBox) == 0x001FE8, "Member 'ASmasherPawn_C::KeepChargingBox' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ChargeMeleeSwingBox) == 0x001FF0, "Member 'ASmasherPawn_C::ChargeMeleeSwingBox' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, CrushBox) == 0x001FF8, "Member 'ASmasherPawn_C::CrushBox' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, SFX_Club_Drag) == 0x002000, "Member 'ASmasherPawn_C::SFX_Club_Drag' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Effect_Club_Drag) == 0x002008, "Member 'ASmasherPawn_C::Effect_Club_Drag' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, PushCapsule) == 0x002010, "Member 'ASmasherPawn_C::PushCapsule' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Timeline_3_ColorFadeOutTrack_676F16694C256D56DC409C8D204D89A8) == 0x002018, "Member 'ASmasherPawn_C::Timeline_3_ColorFadeOutTrack_676F16694C256D56DC409C8D204D89A8' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Timeline_3_FadeInTrack_676F16694C256D56DC409C8D204D89A8) == 0x00201C, "Member 'ASmasherPawn_C::Timeline_3_FadeInTrack_676F16694C256D56DC409C8D204D89A8' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Timeline_3__Direction_676F16694C256D56DC409C8D204D89A8) == 0x002020, "Member 'ASmasherPawn_C::Timeline_3__Direction_676F16694C256D56DC409C8D204D89A8' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Timeline_3) == 0x002028, "Member 'ASmasherPawn_C::Timeline_3' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, RippleTime) == 0x002030, "Member 'ASmasherPawn_C::RippleTime' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, CanRippleAgain) == 0x002034, "Member 'ASmasherPawn_C::CanRippleAgain' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, CurrentJiggleAnimation) == 0x002038, "Member 'ASmasherPawn_C::CurrentJiggleAnimation' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, RippleDamageAmount) == 0x00203C, "Member 'ASmasherPawn_C::RippleDamageAmount' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Dying) == 0x002040, "Member 'ASmasherPawn_C::Dying' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, PushRadius) == 0x002044, "Member 'ASmasherPawn_C::PushRadius' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, OriginalRotationRate) == 0x002048, "Member 'ASmasherPawn_C::OriginalRotationRate' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, CustomizeEyeColor) == 0x002054, "Member 'ASmasherPawn_C::CustomizeEyeColor' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, EyeColor_PlayerNotBeingTracked) == 0x002058, "Member 'ASmasherPawn_C::EyeColor_PlayerNotBeingTracked' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, EyeColor_PlayerBeingTracked) == 0x002068, "Member 'ASmasherPawn_C::EyeColor_PlayerBeingTracked' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Impact_MeleeSocket) == 0x002078, "Member 'ASmasherPawn_C::Impact_MeleeSocket' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ImpactParticles_Default) == 0x002080, "Member 'ASmasherPawn_C::ImpactParticles_Default' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ImpactParticles_Wood) == 0x002088, "Member 'ASmasherPawn_C::ImpactParticles_Wood' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ImpactParticles_Stone) == 0x002090, "Member 'ASmasherPawn_C::ImpactParticles_Stone' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ImpactParticles_Metal) == 0x002098, "Member 'ASmasherPawn_C::ImpactParticles_Metal' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ImpactParticles_HumanFlesh) == 0x0020A0, "Member 'ASmasherPawn_C::ImpactParticles_HumanFlesh' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, MeleeImpact_UseSocketTransforms) == 0x0020A8, "Member 'ASmasherPawn_C::MeleeImpact_UseSocketTransforms' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ActorOverlappingCrushBox) == 0x0020B0, "Member 'ASmasherPawn_C::ActorOverlappingCrushBox' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, CrushTag) == 0x0020B8, "Member 'ASmasherPawn_C::CrushTag' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, SpawnRoarTag) == 0x0020C0, "Member 'ASmasherPawn_C::SpawnRoarTag' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ProhibitBumpDamageTag) == 0x0020E0, "Member 'ASmasherPawn_C::ProhibitBumpDamageTag' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, SmasherMaxCrushVolumeMult) == 0x0020E8, "Member 'ASmasherPawn_C::SmasherMaxCrushVolumeMult' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, DebugSmasherCrushing) == 0x0020EC, "Member 'ASmasherPawn_C::DebugSmasherCrushing' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Death_Effects_SmasherPawn_C) == 0x0020F0, "Member 'ASmasherPawn_C::Death_Effects_SmasherPawn_C' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Curve_Smasher_EyeClose) == 0x0020F8, "Member 'ASmasherPawn_C::Curve_Smasher_EyeClose' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Curve_Smasher_LerpToNewEyeColorToIndicatePlayerTracking) == 0x002100, "Member 'ASmasherPawn_C::Curve_Smasher_LerpToNewEyeColorToIndicatePlayerTracking' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Smasher_RedEyeColorCurve) == 0x002108, "Member 'ASmasherPawn_C::Smasher_RedEyeColorCurve' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Play_Smasher_Eye_Effects_In_Reverse) == 0x002110, "Member 'ASmasherPawn_C::Play_Smasher_Eye_Effects_In_Reverse' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Smasher_Eye_Close_Animation_Length) == 0x002114, "Member 'ASmasherPawn_C::Smasher_Eye_Close_Animation_Length' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, FriendlyPawnPushDuration) == 0x002118, "Member 'ASmasherPawn_C::FriendlyPawnPushDuration' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, FriendlyPawnPushVelocity) == 0x00211C, "Member 'ASmasherPawn_C::FriendlyPawnPushVelocity' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, FriendlyPawnPushYawAngle) == 0x002120, "Member 'ASmasherPawn_C::FriendlyPawnPushYawAngle' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, EnemyPawnKnockbackVelocity) == 0x002124, "Member 'ASmasherPawn_C::EnemyPawnKnockbackVelocity' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, EnemyPawnKnockbackZAngle) == 0x002128, "Member 'ASmasherPawn_C::EnemyPawnKnockbackZAngle' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, EnemyPawnKnockbackYawAngle) == 0x00212C, "Member 'ASmasherPawn_C::EnemyPawnKnockbackYawAngle' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, PawnBumpedBySmasher) == 0x002130, "Member 'ASmasherPawn_C::PawnBumpedBySmasher' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ActorsDamagedByCharge) == 0x002138, "Member 'ASmasherPawn_C::ActorsDamagedByCharge' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ShieldSkeletalMesh) == 0x002148, "Member 'ASmasherPawn_C::ShieldSkeletalMesh' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, ShieldArm) == 0x002150, "Member 'ASmasherPawn_C::ShieldArm' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Smasher_ImpactSound) == 0x002158, "Member 'ASmasherPawn_C::Smasher_ImpactSound' has a wrong offset!");
static_assert(offsetof(ASmasherPawn_C, Smasher) == 0x002160, "Member 'ASmasherPawn_C::Smasher' has a wrong offset!");

}

