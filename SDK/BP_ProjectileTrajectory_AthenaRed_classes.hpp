#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ProjectileTrajectory_AthenaRed

#include "Basic.hpp"

#include "BP_ProjectileTrajectory_classes.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass BP_ProjectileTrajectory_AthenaRed.BP_ProjectileTrajectory_AthenaRed_C
// 0x0008 (0x0368 - 0x0360)
class ABP_ProjectileTrajectory_AthenaRed_C final : public ABP_ProjectileTrajectory_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame_BP_ProjectileTrajectory_AthenaRed_C; // 0x0360(0x0008)(Transient, DuplicateTransient)

public:
	void ExecuteUbergraph_BP_ProjectileTrajectory_AthenaRed(int32 EntryPoint);
	void ReceiveBeginPlay();
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"BP_ProjectileTrajectory_AthenaRed_C">();
	}
	static class ABP_ProjectileTrajectory_AthenaRed_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<ABP_ProjectileTrajectory_AthenaRed_C>();
	}
};
static_assert(alignof(ABP_ProjectileTrajectory_AthenaRed_C) == 0x000008, "Wrong alignment on ABP_ProjectileTrajectory_AthenaRed_C");
static_assert(sizeof(ABP_ProjectileTrajectory_AthenaRed_C) == 0x000368, "Wrong size on ABP_ProjectileTrajectory_AthenaRed_C");
static_assert(offsetof(ABP_ProjectileTrajectory_AthenaRed_C, UberGraphFrame_BP_ProjectileTrajectory_AthenaRed_C) == 0x000360, "Member 'ABP_ProjectileTrajectory_AthenaRed_C::UberGraphFrame_BP_ProjectileTrajectory_AthenaRed_C' has a wrong offset!");

}

