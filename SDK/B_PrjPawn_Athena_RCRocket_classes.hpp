#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_PrjPawn_Athena_RCRocket

#include "Basic.hpp"

#include "FortniteGame_classes.hpp"
#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_PrjPawn_Athena_RCRocket.B_PrjPawn_Athena_RCRocket_C
// 0x0160 (0x2280 - 0x2120)
class AB_PrjPawn_Athena_RCRocket_C final : public AFortRemoteControlledPawnAthena
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x2120(0x0008)(Transient, DuplicateTransient)
	class UParticleSystemComponent*               Jet_Launch;                                        // 0x2128(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          RideBox;                                           // 0x2130(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UBoxComponent*                          HitBox;                                            // 0x2138(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UPoseableMeshComponent*                 PoseableMissileMesh;                               // 0x2140(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               BlinkingLight;                                     // 0x2148(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UStaticMeshComponent*                   LoadMissile;                                       // 0x2150(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               Jet;                                               // 0x2158(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        MissileInAirBankingAudio;                          // 0x2160(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        MissileInAirAudio;                                 // 0x2168(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	struct FVector                                ScaleUpRocket_ScaleRocket_AE4726BD4835EF8E9D886681DC468461; // 0x2170(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            ScaleUpRocket__Direction_AE4726BD4835EF8E9D886681DC468461; // 0x217C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_217D[0x3];                                     // 0x217D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     ScaleUpRocket;                                     // 0x2180(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bDetached;                                         // 0x2188(0x0001)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, RepNotify, NoDestructor)
	bool                                          bTransformed;                                      // 0x2189(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_218A[0x6];                                     // 0x218A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class USoundBase*                             ExplosionSound;                                    // 0x2190(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        ExplosionPS;                                       // 0x2198(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystem*                        TransformationPS;                                  // 0x21A0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             TransformationSound;                               // 0x21A8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Tick_Delta;                                        // 0x21B0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CurrentVector;                                     // 0x21B4(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                PreviousVector;                                    // 0x21C0(0x000C)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         LevelOutRotation;                                  // 0x21CC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Turn_Rate;                                         // 0x21D0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         BankingAudioVolume;                                // 0x21D4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         BankingAudioPitch;                                 // 0x21D8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TurnAudioModulator;                                // 0x21DC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         TurnAudioModulatorMax;                             // 0x21E0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_21E4[0x4];                                     // 0x21E4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   LeftWing;                                          // 0x21E8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   RightWing;                                         // 0x21F0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   TopWing;                                           // 0x21F8(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class FName                                   BottomWing;                                        // 0x2200(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class AB_RCRocket_Launcher_Athena_C*          MissileLauncher;                                   // 0x2208(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnTemplate, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           SwapToIdleAnim;                                    // 0x2210(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAnimMontage*                           ControllerAnim;                                    // 0x2218(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         FadeOutTime;                                       // 0x2220(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DelayBeforeMeshSwap;                               // 0x2224(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         MaxFuelAmount;                                     // 0x2228(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_222C[0x4];                                     // 0x222C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           FuelTimer;                                         // 0x2230(0x0008)(Edit, BlueprintVisible, DisableEditOnInstance, NoDestructor)
	class USoundBase*                             MissileInAirSound;                                 // 0x2238(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             MissileLowFuelSound;                               // 0x2240(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        Missile_LowFuelWarning;                            // 0x2248(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               ControllerRocketFX;                                // 0x2250(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAudioComponent*                        ScreenSoundComponent;                              // 0x2258(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         DelayToggleRC_Vis;                                 // 0x2260(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_2264[0x4];                                     // 0x2264(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UParticleSystem*                        HologramRocket;                                    // 0x2268(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bHasPlayedFuelWarningSound;                        // 0x2270(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_B_PrjPawn_Athena_RCRocket(int32 EntryPoint);
	void OnClientSetupRemoteControlPawn();
	void StartFuelTimer();
	void ResetWeapon();
	void Handle_Movement_Audio();
	void LevelOutMissile();
	void SetPreviousVector();
	void Multicast_HandleOnKill();
	void OnDoKill();
	void ReceiveTick(float DeltaSeconds);
	void OnTriggeredHealthThreshold(float PreviousTriggeredHealthThreshold, float CurrentTriggeredHealthThreshold);
	void ReceiveUnpossessed(class AController* OldController);
	void ReceiveBeginPlay();
	void OnCompleted_FCA2D54B4941303C809ADFA4DDC7D622(class FName NotifyName);
	void OnBlendOut_FCA2D54B4941303C809ADFA4DDC7D622(class FName NotifyName);
	void OnInterrupted_FCA2D54B4941303C809ADFA4DDC7D622(class FName NotifyName);
	void OnNotifyBegin_FCA2D54B4941303C809ADFA4DDC7D622(class FName NotifyName);
	void OnNotifyEnd_FCA2D54B4941303C809ADFA4DDC7D622(class FName NotifyName);
	void OnCompleted_1C6565004725732561E54185F8C600B6(class FName NotifyName);
	void OnBlendOut_1C6565004725732561E54185F8C600B6(class FName NotifyName);
	void OnInterrupted_1C6565004725732561E54185F8C600B6(class FName NotifyName);
	void OnNotifyBegin_1C6565004725732561E54185F8C600B6(class FName NotifyName);
	void OnNotifyEnd_1C6565004725732561E54185F8C600B6(class FName NotifyName);
	void ScaleUpRocket__UpdateFunc();
	void ScaleUpRocket__FinishedFunc();
	void UserConstructionScript();
	void OnRep_bDetached();
	void FuelLevelVisuals();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_PrjPawn_Athena_RCRocket_C">();
	}
	static class AB_PrjPawn_Athena_RCRocket_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_PrjPawn_Athena_RCRocket_C>();
	}
};
static_assert(alignof(AB_PrjPawn_Athena_RCRocket_C) == 0x000010, "Wrong alignment on AB_PrjPawn_Athena_RCRocket_C");
static_assert(sizeof(AB_PrjPawn_Athena_RCRocket_C) == 0x002280, "Wrong size on AB_PrjPawn_Athena_RCRocket_C");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, UberGraphFrame) == 0x002120, "Member 'AB_PrjPawn_Athena_RCRocket_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, Jet_Launch) == 0x002128, "Member 'AB_PrjPawn_Athena_RCRocket_C::Jet_Launch' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, RideBox) == 0x002130, "Member 'AB_PrjPawn_Athena_RCRocket_C::RideBox' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, HitBox) == 0x002138, "Member 'AB_PrjPawn_Athena_RCRocket_C::HitBox' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, PoseableMissileMesh) == 0x002140, "Member 'AB_PrjPawn_Athena_RCRocket_C::PoseableMissileMesh' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, BlinkingLight) == 0x002148, "Member 'AB_PrjPawn_Athena_RCRocket_C::BlinkingLight' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, LoadMissile) == 0x002150, "Member 'AB_PrjPawn_Athena_RCRocket_C::LoadMissile' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, Jet) == 0x002158, "Member 'AB_PrjPawn_Athena_RCRocket_C::Jet' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, MissileInAirBankingAudio) == 0x002160, "Member 'AB_PrjPawn_Athena_RCRocket_C::MissileInAirBankingAudio' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, MissileInAirAudio) == 0x002168, "Member 'AB_PrjPawn_Athena_RCRocket_C::MissileInAirAudio' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, ScaleUpRocket_ScaleRocket_AE4726BD4835EF8E9D886681DC468461) == 0x002170, "Member 'AB_PrjPawn_Athena_RCRocket_C::ScaleUpRocket_ScaleRocket_AE4726BD4835EF8E9D886681DC468461' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, ScaleUpRocket__Direction_AE4726BD4835EF8E9D886681DC468461) == 0x00217C, "Member 'AB_PrjPawn_Athena_RCRocket_C::ScaleUpRocket__Direction_AE4726BD4835EF8E9D886681DC468461' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, ScaleUpRocket) == 0x002180, "Member 'AB_PrjPawn_Athena_RCRocket_C::ScaleUpRocket' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, bDetached) == 0x002188, "Member 'AB_PrjPawn_Athena_RCRocket_C::bDetached' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, bTransformed) == 0x002189, "Member 'AB_PrjPawn_Athena_RCRocket_C::bTransformed' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, ExplosionSound) == 0x002190, "Member 'AB_PrjPawn_Athena_RCRocket_C::ExplosionSound' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, ExplosionPS) == 0x002198, "Member 'AB_PrjPawn_Athena_RCRocket_C::ExplosionPS' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, TransformationPS) == 0x0021A0, "Member 'AB_PrjPawn_Athena_RCRocket_C::TransformationPS' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, TransformationSound) == 0x0021A8, "Member 'AB_PrjPawn_Athena_RCRocket_C::TransformationSound' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, Tick_Delta) == 0x0021B0, "Member 'AB_PrjPawn_Athena_RCRocket_C::Tick_Delta' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, CurrentVector) == 0x0021B4, "Member 'AB_PrjPawn_Athena_RCRocket_C::CurrentVector' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, PreviousVector) == 0x0021C0, "Member 'AB_PrjPawn_Athena_RCRocket_C::PreviousVector' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, LevelOutRotation) == 0x0021CC, "Member 'AB_PrjPawn_Athena_RCRocket_C::LevelOutRotation' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, Turn_Rate) == 0x0021D0, "Member 'AB_PrjPawn_Athena_RCRocket_C::Turn_Rate' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, BankingAudioVolume) == 0x0021D4, "Member 'AB_PrjPawn_Athena_RCRocket_C::BankingAudioVolume' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, BankingAudioPitch) == 0x0021D8, "Member 'AB_PrjPawn_Athena_RCRocket_C::BankingAudioPitch' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, TurnAudioModulator) == 0x0021DC, "Member 'AB_PrjPawn_Athena_RCRocket_C::TurnAudioModulator' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, TurnAudioModulatorMax) == 0x0021E0, "Member 'AB_PrjPawn_Athena_RCRocket_C::TurnAudioModulatorMax' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, LeftWing) == 0x0021E8, "Member 'AB_PrjPawn_Athena_RCRocket_C::LeftWing' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, RightWing) == 0x0021F0, "Member 'AB_PrjPawn_Athena_RCRocket_C::RightWing' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, TopWing) == 0x0021F8, "Member 'AB_PrjPawn_Athena_RCRocket_C::TopWing' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, BottomWing) == 0x002200, "Member 'AB_PrjPawn_Athena_RCRocket_C::BottomWing' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, MissileLauncher) == 0x002208, "Member 'AB_PrjPawn_Athena_RCRocket_C::MissileLauncher' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, SwapToIdleAnim) == 0x002210, "Member 'AB_PrjPawn_Athena_RCRocket_C::SwapToIdleAnim' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, ControllerAnim) == 0x002218, "Member 'AB_PrjPawn_Athena_RCRocket_C::ControllerAnim' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, FadeOutTime) == 0x002220, "Member 'AB_PrjPawn_Athena_RCRocket_C::FadeOutTime' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, DelayBeforeMeshSwap) == 0x002224, "Member 'AB_PrjPawn_Athena_RCRocket_C::DelayBeforeMeshSwap' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, MaxFuelAmount) == 0x002228, "Member 'AB_PrjPawn_Athena_RCRocket_C::MaxFuelAmount' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, FuelTimer) == 0x002230, "Member 'AB_PrjPawn_Athena_RCRocket_C::FuelTimer' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, MissileInAirSound) == 0x002238, "Member 'AB_PrjPawn_Athena_RCRocket_C::MissileInAirSound' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, MissileLowFuelSound) == 0x002240, "Member 'AB_PrjPawn_Athena_RCRocket_C::MissileLowFuelSound' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, Missile_LowFuelWarning) == 0x002248, "Member 'AB_PrjPawn_Athena_RCRocket_C::Missile_LowFuelWarning' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, ControllerRocketFX) == 0x002250, "Member 'AB_PrjPawn_Athena_RCRocket_C::ControllerRocketFX' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, ScreenSoundComponent) == 0x002258, "Member 'AB_PrjPawn_Athena_RCRocket_C::ScreenSoundComponent' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, DelayToggleRC_Vis) == 0x002260, "Member 'AB_PrjPawn_Athena_RCRocket_C::DelayToggleRC_Vis' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, HologramRocket) == 0x002268, "Member 'AB_PrjPawn_Athena_RCRocket_C::HologramRocket' has a wrong offset!");
static_assert(offsetof(AB_PrjPawn_Athena_RCRocket_C, bHasPlayedFuelWarningSound) == 0x002270, "Member 'AB_PrjPawn_Athena_RCRocket_C::bHasPlayedFuelWarningSound' has a wrong offset!");

}

