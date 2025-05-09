#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Pistol_Zapper_Athena

#include "Basic.hpp"

#include "FortniteGame_structs.hpp"
#include "B_Pistol_Generic_classes.hpp"
#include "Engine_structs.hpp"
#include "CoreUObject_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_Pistol_Zapper_Athena.B_Pistol_Zapper_Athena_C
// 0x0078 (0x0ED0 - 0x0E58)
class AB_Pistol_Zapper_Athena_C final : public AB_Pistol_Generic_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_B_Pistol_Zapper_Athena_C;           // 0x0E58(0x0008)(Transient, DuplicateTransient)
	class UParticleSystemComponent*               P_ZapZap_CoreReloadArcs_01;                        // 0x0E60(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               P_ZapZap_CoreReload_01;                            // 0x0E68(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	class UParticleSystemComponent*               P_ZapZap_Core_01;                                  // 0x0E70(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)
	struct FVector                                Scale_Glow_Up_Size_296E288E48C0EAEDC7AF2EB049AA2ED0; // 0x0E78(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Scale_Glow_Up_LERP_Particle_296E288E48C0EAEDC7AF2EB049AA2ED0; // 0x0E84(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Scale_Glow_Up_LERP_Color_296E288E48C0EAEDC7AF2EB049AA2ED0; // 0x0E88(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ETimelineDirection                            Scale_Glow_Up__Direction_296E288E48C0EAEDC7AF2EB049AA2ED0; // 0x0E8C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_E8D[0x3];                                      // 0x0E8D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	class UTimelineComponent*                     Scale_Glow_Up;                                     // 0x0E90(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UMaterialInstanceDynamic*               WeaponMesh_MID;                                    // 0x0E98(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FLinearColor                           GlowColor_Charged;                                 // 0x0EA0(0x0010)(Edit, BlueprintVisible, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          AmmoCountChangedBeUsed_;                           // 0x0EB0(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_EB1[0x3];                                      // 0x0EB1(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         GetTimeToNextFire;                                 // 0x0EB4(0x0004)(Edit, BlueprintVisible, Net, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         bAmmoCountDelay;                                   // 0x0EB8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Core_Reload_Start_Speed;                           // 0x0EBC(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Core_Reload_End_Speed;                             // 0x0EC0(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Core_Reload_Start_Spawn_Rate;                      // 0x0EC4(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Core_Reload_End_Spawn_Rate;                        // 0x0EC8(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_B_Pistol_Zapper_Athena(int32 EntryPoint);
	void OnAmmoCountChanged();
	void Muzzle_Play_Reload_FX(EFortReloadFXState Selection);
	void ReceiveBeginPlay();
	void OnPlayWeaponFireFX(bool bPersistentFire, bool bSecondaryFire);
	void Scale_Glow_Up__Event__EventFunc();
	void Scale_Glow_Up__UpdateFunc();
	void Scale_Glow_Up__FinishedFunc();
	void UserConstructionScript();
	void UpdateVisuals(bool Ammo_Check);
	void DisableAllVisuals();
	void StopAndResetTimeline();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_Pistol_Zapper_Athena_C">();
	}
	static class AB_Pistol_Zapper_Athena_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_Pistol_Zapper_Athena_C>();
	}
};
static_assert(alignof(AB_Pistol_Zapper_Athena_C) == 0x000008, "Wrong alignment on AB_Pistol_Zapper_Athena_C");
static_assert(sizeof(AB_Pistol_Zapper_Athena_C) == 0x000ED0, "Wrong size on AB_Pistol_Zapper_Athena_C");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, UberGraphFrame_B_Pistol_Zapper_Athena_C) == 0x000E58, "Member 'AB_Pistol_Zapper_Athena_C::UberGraphFrame_B_Pistol_Zapper_Athena_C' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, P_ZapZap_CoreReloadArcs_01) == 0x000E60, "Member 'AB_Pistol_Zapper_Athena_C::P_ZapZap_CoreReloadArcs_01' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, P_ZapZap_CoreReload_01) == 0x000E68, "Member 'AB_Pistol_Zapper_Athena_C::P_ZapZap_CoreReload_01' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, P_ZapZap_Core_01) == 0x000E70, "Member 'AB_Pistol_Zapper_Athena_C::P_ZapZap_Core_01' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, Scale_Glow_Up_Size_296E288E48C0EAEDC7AF2EB049AA2ED0) == 0x000E78, "Member 'AB_Pistol_Zapper_Athena_C::Scale_Glow_Up_Size_296E288E48C0EAEDC7AF2EB049AA2ED0' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, Scale_Glow_Up_LERP_Particle_296E288E48C0EAEDC7AF2EB049AA2ED0) == 0x000E84, "Member 'AB_Pistol_Zapper_Athena_C::Scale_Glow_Up_LERP_Particle_296E288E48C0EAEDC7AF2EB049AA2ED0' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, Scale_Glow_Up_LERP_Color_296E288E48C0EAEDC7AF2EB049AA2ED0) == 0x000E88, "Member 'AB_Pistol_Zapper_Athena_C::Scale_Glow_Up_LERP_Color_296E288E48C0EAEDC7AF2EB049AA2ED0' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, Scale_Glow_Up__Direction_296E288E48C0EAEDC7AF2EB049AA2ED0) == 0x000E8C, "Member 'AB_Pistol_Zapper_Athena_C::Scale_Glow_Up__Direction_296E288E48C0EAEDC7AF2EB049AA2ED0' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, Scale_Glow_Up) == 0x000E90, "Member 'AB_Pistol_Zapper_Athena_C::Scale_Glow_Up' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, WeaponMesh_MID) == 0x000E98, "Member 'AB_Pistol_Zapper_Athena_C::WeaponMesh_MID' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, GlowColor_Charged) == 0x000EA0, "Member 'AB_Pistol_Zapper_Athena_C::GlowColor_Charged' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, AmmoCountChangedBeUsed_) == 0x000EB0, "Member 'AB_Pistol_Zapper_Athena_C::AmmoCountChangedBeUsed_' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, GetTimeToNextFire) == 0x000EB4, "Member 'AB_Pistol_Zapper_Athena_C::GetTimeToNextFire' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, bAmmoCountDelay) == 0x000EB8, "Member 'AB_Pistol_Zapper_Athena_C::bAmmoCountDelay' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, Core_Reload_Start_Speed) == 0x000EBC, "Member 'AB_Pistol_Zapper_Athena_C::Core_Reload_Start_Speed' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, Core_Reload_End_Speed) == 0x000EC0, "Member 'AB_Pistol_Zapper_Athena_C::Core_Reload_End_Speed' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, Core_Reload_Start_Spawn_Rate) == 0x000EC4, "Member 'AB_Pistol_Zapper_Athena_C::Core_Reload_Start_Spawn_Rate' has a wrong offset!");
static_assert(offsetof(AB_Pistol_Zapper_Athena_C, Core_Reload_End_Spawn_Rate) == 0x000EC8, "Member 'AB_Pistol_Zapper_Athena_C::Core_Reload_End_Spawn_Rate' has a wrong offset!");

}

