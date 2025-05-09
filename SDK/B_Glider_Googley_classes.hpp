#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: B_Glider_Googley

#include "Basic.hpp"

#include "B_EmptyBaseGlider_classes.hpp"
#include "Engine_structs.hpp"


namespace SDK
{

// BlueprintGeneratedClass B_Glider_Googley.B_Glider_Googley_C
// 0x0010 (0x0378 - 0x0368)
class AB_Glider_Googley_C final : public AB_EmptyBaseGlider_C
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0368(0x0008)(Transient, DuplicateTransient)
	class USkeletalMeshComponent*                 Bits;                                              // 0x0370(0x0008)(BlueprintVisible, ZeroConstructor, InstancedReference, IsPlainOldData, NonTransactional, NoDestructor, HasGetValueTypeHash)

public:
	void ExecuteUbergraph_B_Glider_Googley(int32 EntryPoint);
	void FireDynamics();
	void ReceiveBeginPlay();
	void UserConstructionScript();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"B_Glider_Googley_C">();
	}
	static class AB_Glider_Googley_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<AB_Glider_Googley_C>();
	}
};
static_assert(alignof(AB_Glider_Googley_C) == 0x000008, "Wrong alignment on AB_Glider_Googley_C");
static_assert(sizeof(AB_Glider_Googley_C) == 0x000378, "Wrong size on AB_Glider_Googley_C");
static_assert(offsetof(AB_Glider_Googley_C, UberGraphFrame) == 0x000368, "Member 'AB_Glider_Googley_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(AB_Glider_Googley_C, Bits) == 0x000370, "Member 'AB_Glider_Googley_C::Bits' has a wrong offset!");

}

