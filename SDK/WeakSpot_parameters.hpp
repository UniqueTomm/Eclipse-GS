#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: WeakSpot

#include "Basic.hpp"

#include "CoreUObject_structs.hpp"
#include "Engine_structs.hpp"


namespace SDK::Params
{

// Function WeakSpot.WeakSpot_C.ExecuteUbergraph_WeakSpot
// 0x01A0 (0x01A0 - 0x0000)
struct WeakSpot_C_ExecuteUbergraph_WeakSpot final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void()>                             K2Node_CreateDelegate_OutputDelegate;              // 0x0008(0x0010)(ZeroConstructor, NoDestructor)
	struct FVector                                CallFunc_Conv_FloatToVector_ReturnValue;           // 0x0018(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue;          // 0x0024(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_Greater_IntInt_ReturnValue;               // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_IntInt_ReturnValue;            // 0x0031(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_32[0x2];                                       // 0x0032(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_BreakVector_X;                            // 0x0034(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Y;                            // 0x0038(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_BreakVector_Z;                            // 0x003C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_MakeVector_ReturnValue;                   // 0x0040(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         Temp_float_Variable;                               // 0x004C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_Subtract_VectorVector_ReturnValue;        // 0x0050(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FRotator                               CallFunc_Conv_VectorToRotator_ReturnValue;         // 0x005C(0x000C)(IsPlainOldData, NoDestructor)
	float                                         CallFunc_VSize_ReturnValue;                        // 0x0068(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_LessEqual_FloatFloat_ReturnValue;         // 0x006C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_GreaterEqual_FloatFloat_ReturnValue;      // 0x006D(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_6E[0x2];                                       // 0x006E(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Multiply_FloatFloat_ReturnValue;          // 0x0070(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x0074(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_75[0x3];                                       // 0x0075(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	int32                                         CallFunc_FFloor_ReturnValue;                       // 0x0078(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_BooleanAND_ReturnValue1;                  // 0x007C(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_7D[0x3];                                       // 0x007D(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Conv_IntToFloat_ReturnValue;              // 0x0080(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          CallFunc_GreaterEqual_FloatFloat_ReturnValue1;     // 0x0084(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_85[0x3];                                       // 0x0085(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         CallFunc_Multiply_FloatFloat_ReturnValue1;         // 0x0088(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_FClamp_ReturnValue;                       // 0x008C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	float                                         CallFunc_GetGameTimeInSeconds_ReturnValue;         // 0x0090(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_94[0x4];                                       // 0x0094(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTimerHandle                           CallFunc_K2_SetTimerDelegate_ReturnValue;          // 0x0098(0x0008)(NoDestructor)
	struct FVector                                CallFunc_MakeVector_ReturnValue1;                  // 0x00A0(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_AC[0x4];                                       // 0x00AC(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	struct FTransform                             CallFunc_MakeTransform_ReturnValue;                // 0x00B0(0x0030)(IsPlainOldData, NoDestructor)
	struct FHitResult                             CallFunc_K2_SetWorldTransform_SweepHitResult;      // 0x00E0(0x0088)(IsPlainOldData, NoDestructor, ContainsInstancedReference)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue1;         // 0x0168(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Temp_bool_Variable;                                // 0x0174(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_175[0x3];                                      // 0x0175(0x0003)(Fixing Size After Last Property [ Dumper-7 ])
	float                                         K2Node_Select_Default;                             // 0x0178(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Array_LastIndex_ReturnValue;              // 0x017C(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	int32                                         CallFunc_Clamp_ReturnValue;                        // 0x0180(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	struct FVector                                CallFunc_K2_GetActorLocation_ReturnValue12;        // 0x0184(0x000C)(IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class USoundBase*                             CallFunc_Array_Get_Item;                           // 0x0190(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WeakSpot_C_ExecuteUbergraph_WeakSpot) == 0x000010, "Wrong alignment on WeakSpot_C_ExecuteUbergraph_WeakSpot");
static_assert(sizeof(WeakSpot_C_ExecuteUbergraph_WeakSpot) == 0x0001A0, "Wrong size on WeakSpot_C_ExecuteUbergraph_WeakSpot");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, EntryPoint) == 0x000000, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::EntryPoint' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, K2Node_CreateDelegate_OutputDelegate) == 0x000008, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::K2Node_CreateDelegate_OutputDelegate' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Conv_FloatToVector_ReturnValue) == 0x000018, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Conv_FloatToVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_K2_GetActorLocation_ReturnValue) == 0x000024, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_K2_GetActorLocation_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Greater_IntInt_ReturnValue) == 0x000030, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Greater_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_EqualEqual_IntInt_ReturnValue) == 0x000031, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_EqualEqual_IntInt_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_BreakVector_X) == 0x000034, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_BreakVector_X' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_BreakVector_Y) == 0x000038, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_BreakVector_Y' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_BreakVector_Z) == 0x00003C, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_BreakVector_Z' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_MakeVector_ReturnValue) == 0x000040, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_MakeVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, Temp_float_Variable) == 0x00004C, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::Temp_float_Variable' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Subtract_VectorVector_ReturnValue) == 0x000050, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Subtract_VectorVector_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Conv_VectorToRotator_ReturnValue) == 0x00005C, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Conv_VectorToRotator_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_VSize_ReturnValue) == 0x000068, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_VSize_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_LessEqual_FloatFloat_ReturnValue) == 0x00006C, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_LessEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_GreaterEqual_FloatFloat_ReturnValue) == 0x00006D, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_GreaterEqual_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Multiply_FloatFloat_ReturnValue) == 0x000070, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Multiply_FloatFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_BooleanAND_ReturnValue) == 0x000074, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_BooleanAND_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_FFloor_ReturnValue) == 0x000078, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_FFloor_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_BooleanAND_ReturnValue1) == 0x00007C, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_BooleanAND_ReturnValue1' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Conv_IntToFloat_ReturnValue) == 0x000080, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Conv_IntToFloat_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_GreaterEqual_FloatFloat_ReturnValue1) == 0x000084, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_GreaterEqual_FloatFloat_ReturnValue1' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Multiply_FloatFloat_ReturnValue1) == 0x000088, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Multiply_FloatFloat_ReturnValue1' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_FClamp_ReturnValue) == 0x00008C, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_FClamp_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_GetGameTimeInSeconds_ReturnValue) == 0x000090, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_GetGameTimeInSeconds_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_K2_SetTimerDelegate_ReturnValue) == 0x000098, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_K2_SetTimerDelegate_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_MakeVector_ReturnValue1) == 0x0000A0, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_MakeVector_ReturnValue1' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_MakeTransform_ReturnValue) == 0x0000B0, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_MakeTransform_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_K2_SetWorldTransform_SweepHitResult) == 0x0000E0, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_K2_SetWorldTransform_SweepHitResult' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_K2_GetActorLocation_ReturnValue1) == 0x000168, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_K2_GetActorLocation_ReturnValue1' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, Temp_bool_Variable) == 0x000174, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, K2Node_Select_Default) == 0x000178, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::K2Node_Select_Default' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Array_LastIndex_ReturnValue) == 0x00017C, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Array_LastIndex_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Clamp_ReturnValue) == 0x000180, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Clamp_ReturnValue' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_K2_GetActorLocation_ReturnValue12) == 0x000184, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_K2_GetActorLocation_ReturnValue12' has a wrong offset!");
static_assert(offsetof(WeakSpot_C_ExecuteUbergraph_WeakSpot, CallFunc_Array_Get_Item) == 0x000190, "Member 'WeakSpot_C_ExecuteUbergraph_WeakSpot::CallFunc_Array_Get_Item' has a wrong offset!");

// Function WeakSpot.WeakSpot_C.UserConstructionScript
// 0x0008 (0x0008 - 0x0000)
struct WeakSpot_C_UserConstructionScript final
{
public:
	class UMaterialInstanceDynamic*               CallFunc_CreateDynamicMaterialInstance_ReturnValue; // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(WeakSpot_C_UserConstructionScript) == 0x000008, "Wrong alignment on WeakSpot_C_UserConstructionScript");
static_assert(sizeof(WeakSpot_C_UserConstructionScript) == 0x000008, "Wrong size on WeakSpot_C_UserConstructionScript");
static_assert(offsetof(WeakSpot_C_UserConstructionScript, CallFunc_CreateDynamicMaterialInstance_ReturnValue) == 0x000000, "Member 'WeakSpot_C_UserConstructionScript::CallFunc_CreateDynamicMaterialInstance_ReturnValue' has a wrong offset!");

}

