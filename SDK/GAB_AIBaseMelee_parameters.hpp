#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_AIBaseMelee

#include "Basic.hpp"

#include "GameplayAbilities_structs.hpp"
#include "GameplayTags_structs.hpp"


namespace SDK::Params
{

// Function GAB_AIBaseMelee.GAB_AIBaseMelee_C.ExecuteUbergraph_GAB_AIBaseMelee
// 0x0108 (0x0108 - 0x0000)
struct GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag)> K2Node_CreateDelegate_OutputDelegate;              // 0x0008(0x0010)(ZeroConstructor, NoDestructor)
	struct FGameplayAbilityTargetDataHandle       K2Node_CustomEvent_TargetData12;                   // 0x0018(0x0020)(ConstParm)
	struct FGameplayTag                           K2Node_CustomEvent_ApplicationTag12;               // 0x0038(0x0008)(NoDestructor, HasGetValueTypeHash)
	struct FGameplayAbilityTargetDataHandle       K2Node_CustomEvent_TargetData1;                    // 0x0040(0x0020)(ConstParm)
	struct FGameplayTag                           K2Node_CustomEvent_ApplicationTag1;                // 0x0060(0x0008)(NoDestructor, HasGetValueTypeHash)
	TDelegate<void(struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag)> K2Node_CreateDelegate_OutputDelegate1;             // 0x0068(0x0010)(ZeroConstructor, NoDestructor)
	struct FGameplayAbilityTargetDataHandle       K2Node_CustomEvent_TargetData;                     // 0x0078(0x0020)(ConstParm)
	struct FGameplayTag                           K2Node_CustomEvent_ApplicationTag;                 // 0x0098(0x0008)(NoDestructor, HasGetValueTypeHash)
	TDelegate<void(struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag)> K2Node_CreateDelegate_OutputDelegate12;            // 0x00A0(0x0010)(ZeroConstructor, NoDestructor)
	struct FGameplayTag                           Temp_struct_Variable;                              // 0x00B0(0x0008)(NoDestructor, HasGetValueTypeHash)
	struct FGameplayAbilityTargetDataHandle       Temp_struct_Variable1;                             // 0x00B8(0x0020)()
	bool                                          CallFunc_TargetDataHasActor_ReturnValue;           // 0x00D8(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_D9[0x7];                                       // 0x00D9(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TArray<struct FActiveGameplayEffectHandle>    CallFunc_ApplyGameplayEffectContainer_ReturnValue; // 0x00E0(0x0010)(ConstParm, ZeroConstructor, ReferenceParm)
	bool                                          CallFunc_K2_CommitAbility_ReturnValue;             // 0x00F0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_F1[0x7];                                       // 0x00F1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class UFortAbilityTask_PlayMontageWaitTarget* CallFunc_PlayMontageInfoAndWaitForTrigger_ReturnValue; // 0x00F8(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0100(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee) == 0x000008, "Wrong alignment on GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee");
static_assert(sizeof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee) == 0x000108, "Wrong size on GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, EntryPoint) == 0x000000, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::EntryPoint' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, K2Node_CreateDelegate_OutputDelegate) == 0x000008, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, K2Node_CustomEvent_TargetData12) == 0x000018, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::K2Node_CustomEvent_TargetData12' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, K2Node_CustomEvent_ApplicationTag12) == 0x000038, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::K2Node_CustomEvent_ApplicationTag12' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, K2Node_CustomEvent_TargetData1) == 0x000040, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::K2Node_CustomEvent_TargetData1' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, K2Node_CustomEvent_ApplicationTag1) == 0x000060, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::K2Node_CustomEvent_ApplicationTag1' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, K2Node_CreateDelegate_OutputDelegate1) == 0x000068, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::K2Node_CreateDelegate_OutputDelegate1' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, K2Node_CustomEvent_TargetData) == 0x000078, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::K2Node_CustomEvent_TargetData' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, K2Node_CustomEvent_ApplicationTag) == 0x000098, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::K2Node_CustomEvent_ApplicationTag' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, K2Node_CreateDelegate_OutputDelegate12) == 0x0000A0, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::K2Node_CreateDelegate_OutputDelegate12' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, Temp_struct_Variable) == 0x0000B0, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::Temp_struct_Variable' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, Temp_struct_Variable1) == 0x0000B8, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::Temp_struct_Variable1' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, CallFunc_TargetDataHasActor_ReturnValue) == 0x0000D8, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::CallFunc_TargetDataHasActor_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, CallFunc_ApplyGameplayEffectContainer_ReturnValue) == 0x0000E0, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::CallFunc_ApplyGameplayEffectContainer_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, CallFunc_K2_CommitAbility_ReturnValue) == 0x0000F0, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::CallFunc_K2_CommitAbility_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, CallFunc_PlayMontageInfoAndWaitForTrigger_ReturnValue) == 0x0000F8, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::CallFunc_PlayMontageInfoAndWaitForTrigger_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee, CallFunc_IsValid_ReturnValue) == 0x000100, "Member 'GAB_AIBaseMelee_C_ExecuteUbergraph_GAB_AIBaseMelee::CallFunc_IsValid_ReturnValue' has a wrong offset!");

// Function GAB_AIBaseMelee.GAB_AIBaseMelee_C.Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC
// 0x0028 (0x0028 - 0x0000)
struct GAB_AIBaseMelee_C_Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC final
{
public:
	struct FGameplayAbilityTargetDataHandle       TargetData;                                        // 0x0000(0x0020)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	struct FGameplayTag                           ApplicationTag;                                    // 0x0020(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(GAB_AIBaseMelee_C_Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC) == 0x000008, "Wrong alignment on GAB_AIBaseMelee_C_Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC");
static_assert(sizeof(GAB_AIBaseMelee_C_Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC) == 0x000028, "Wrong size on GAB_AIBaseMelee_C_Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC");
static_assert(offsetof(GAB_AIBaseMelee_C_Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC, TargetData) == 0x000000, "Member 'GAB_AIBaseMelee_C_Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC::TargetData' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC, ApplicationTag) == 0x000020, "Member 'GAB_AIBaseMelee_C_Cancelled_8CCC8A6B41B7B728038BDE887BD23BCC::ApplicationTag' has a wrong offset!");

// Function GAB_AIBaseMelee.GAB_AIBaseMelee_C.Completed_8CCC8A6B41B7B728038BDE887BD23BCC
// 0x0028 (0x0028 - 0x0000)
struct GAB_AIBaseMelee_C_Completed_8CCC8A6B41B7B728038BDE887BD23BCC final
{
public:
	struct FGameplayAbilityTargetDataHandle       TargetData;                                        // 0x0000(0x0020)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	struct FGameplayTag                           ApplicationTag;                                    // 0x0020(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(GAB_AIBaseMelee_C_Completed_8CCC8A6B41B7B728038BDE887BD23BCC) == 0x000008, "Wrong alignment on GAB_AIBaseMelee_C_Completed_8CCC8A6B41B7B728038BDE887BD23BCC");
static_assert(sizeof(GAB_AIBaseMelee_C_Completed_8CCC8A6B41B7B728038BDE887BD23BCC) == 0x000028, "Wrong size on GAB_AIBaseMelee_C_Completed_8CCC8A6B41B7B728038BDE887BD23BCC");
static_assert(offsetof(GAB_AIBaseMelee_C_Completed_8CCC8A6B41B7B728038BDE887BD23BCC, TargetData) == 0x000000, "Member 'GAB_AIBaseMelee_C_Completed_8CCC8A6B41B7B728038BDE887BD23BCC::TargetData' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_Completed_8CCC8A6B41B7B728038BDE887BD23BCC, ApplicationTag) == 0x000020, "Member 'GAB_AIBaseMelee_C_Completed_8CCC8A6B41B7B728038BDE887BD23BCC::ApplicationTag' has a wrong offset!");

// Function GAB_AIBaseMelee.GAB_AIBaseMelee_C.Triggered_8CCC8A6B41B7B728038BDE887BD23BCC
// 0x0028 (0x0028 - 0x0000)
struct GAB_AIBaseMelee_C_Triggered_8CCC8A6B41B7B728038BDE887BD23BCC final
{
public:
	struct FGameplayAbilityTargetDataHandle       TargetData;                                        // 0x0000(0x0020)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
	struct FGameplayTag                           ApplicationTag;                                    // 0x0020(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(GAB_AIBaseMelee_C_Triggered_8CCC8A6B41B7B728038BDE887BD23BCC) == 0x000008, "Wrong alignment on GAB_AIBaseMelee_C_Triggered_8CCC8A6B41B7B728038BDE887BD23BCC");
static_assert(sizeof(GAB_AIBaseMelee_C_Triggered_8CCC8A6B41B7B728038BDE887BD23BCC) == 0x000028, "Wrong size on GAB_AIBaseMelee_C_Triggered_8CCC8A6B41B7B728038BDE887BD23BCC");
static_assert(offsetof(GAB_AIBaseMelee_C_Triggered_8CCC8A6B41B7B728038BDE887BD23BCC, TargetData) == 0x000000, "Member 'GAB_AIBaseMelee_C_Triggered_8CCC8A6B41B7B728038BDE887BD23BCC::TargetData' has a wrong offset!");
static_assert(offsetof(GAB_AIBaseMelee_C_Triggered_8CCC8A6B41B7B728038BDE887BD23BCC, ApplicationTag) == 0x000020, "Member 'GAB_AIBaseMelee_C_Triggered_8CCC8A6B41B7B728038BDE887BD23BCC::ApplicationTag' has a wrong offset!");

}

