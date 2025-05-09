#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_SmasherTurnTransition

#include "Basic.hpp"

#include "GameplayAbilities_structs.hpp"


namespace SDK::Params
{

// Function GAB_SmasherTurnTransition.GAB_SmasherTurnTransition_C.ExecuteUbergraph_GAB_SmasherTurnTransition
// 0x00A8 (0x00A8 - 0x0000)
struct GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FActiveGameplayEffectHandle            CallFunc_BP_ApplyGameplayEffectToOwner_ReturnValue; // 0x0004(0x0008)(NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_C[0x4];                                        // 0x000C(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0010(0x0010)(ZeroConstructor, NoDestructor)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate1;             // 0x0020(0x0010)(ZeroConstructor, NoDestructor)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate12;            // 0x0030(0x0010)(ZeroConstructor, NoDestructor)
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate123;           // 0x0040(0x0010)(ZeroConstructor, NoDestructor)
	bool                                          CallFunc_K2_CommitAbility_ReturnValue;             // 0x0050(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_51[0x7];                                       // 0x0051(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FName                                   CallFunc_GetTurnTransitionMontageSectionNameAndYawRotationRate_MontageSectionName; // 0x0058(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetTurnTransitionMontageSectionNameAndYawRotationRate_TurnYawRotationRate; // 0x0060(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_64[0x4];                                       // 0x0064(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPawn*                              CallFunc_GetActivatingPawn_ReturnValue;            // 0x0068(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UAbilityTask_PlayMontageAndWait*        CallFunc_CreatePlayMontageAndWaitProxy_ReturnValue; // 0x0070(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UPawnMovementComponent*                 CallFunc_GetMovementComponent_ReturnValue;         // 0x0078(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCharacterMovementComponent*            K2Node_DynamicCast_AsCharacter_Movement_Component; // 0x0080(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0088(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_IsValid_ReturnValue;                      // 0x0089(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_8A[0x6];                                       // 0x008A(0x0006)(Fixing Size After Last Property [ Dumper-7 ])
	class AFortPawn*                              CallFunc_GetActivatingPawn_ReturnValue1;           // 0x0090(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class ASmasherPawn_C*                         K2Node_DynamicCast_AsSmasher_Pawn;                 // 0x0098(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess1;                      // 0x00A0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition) == 0x000008, "Wrong alignment on GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition");
static_assert(sizeof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition) == 0x0000A8, "Wrong size on GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, EntryPoint) == 0x000000, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::EntryPoint' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, CallFunc_BP_ApplyGameplayEffectToOwner_ReturnValue) == 0x000004, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::CallFunc_BP_ApplyGameplayEffectToOwner_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, K2Node_CreateDelegate_OutputDelegate) == 0x000010, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, K2Node_CreateDelegate_OutputDelegate1) == 0x000020, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::K2Node_CreateDelegate_OutputDelegate1' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, K2Node_CreateDelegate_OutputDelegate12) == 0x000030, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::K2Node_CreateDelegate_OutputDelegate12' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, K2Node_CreateDelegate_OutputDelegate123) == 0x000040, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::K2Node_CreateDelegate_OutputDelegate123' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, CallFunc_K2_CommitAbility_ReturnValue) == 0x000050, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::CallFunc_K2_CommitAbility_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, CallFunc_GetTurnTransitionMontageSectionNameAndYawRotationRate_MontageSectionName) == 0x000058, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::CallFunc_GetTurnTransitionMontageSectionNameAndYawRotationRate_MontageSectionName' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, CallFunc_GetTurnTransitionMontageSectionNameAndYawRotationRate_TurnYawRotationRate) == 0x000060, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::CallFunc_GetTurnTransitionMontageSectionNameAndYawRotationRate_TurnYawRotationRate' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, CallFunc_GetActivatingPawn_ReturnValue) == 0x000068, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::CallFunc_GetActivatingPawn_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, CallFunc_CreatePlayMontageAndWaitProxy_ReturnValue) == 0x000070, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::CallFunc_CreatePlayMontageAndWaitProxy_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, CallFunc_GetMovementComponent_ReturnValue) == 0x000078, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::CallFunc_GetMovementComponent_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, K2Node_DynamicCast_AsCharacter_Movement_Component) == 0x000080, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::K2Node_DynamicCast_AsCharacter_Movement_Component' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, K2Node_DynamicCast_bSuccess) == 0x000088, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, CallFunc_IsValid_ReturnValue) == 0x000089, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::CallFunc_IsValid_ReturnValue' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, CallFunc_GetActivatingPawn_ReturnValue1) == 0x000090, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::CallFunc_GetActivatingPawn_ReturnValue1' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, K2Node_DynamicCast_AsSmasher_Pawn) == 0x000098, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::K2Node_DynamicCast_AsSmasher_Pawn' has a wrong offset!");
static_assert(offsetof(GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition, K2Node_DynamicCast_bSuccess1) == 0x0000A0, "Member 'GAB_SmasherTurnTransition_C_ExecuteUbergraph_GAB_SmasherTurnTransition::K2Node_DynamicCast_bSuccess1' has a wrong offset!");

}

