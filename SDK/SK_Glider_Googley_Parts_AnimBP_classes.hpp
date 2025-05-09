#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: SK_Glider_Googley_Parts_AnimBP

#include "Basic.hpp"

#include "FortniteGame_classes.hpp"
#include "ImmediatePhysics_structs.hpp"
#include "Engine_structs.hpp"
#include "AnimGraphRuntime_structs.hpp"


namespace SDK
{

// AnimBlueprintGeneratedClass SK_Glider_Googley_Parts_AnimBP.SK_Glider_Googley_Parts_AnimBP_C
// 0x0DC0 (0x11F0 - 0x0430)
class USK_Glider_Googley_Parts_AnimBP_C final : public UCustomCharacterPartAnimInstance
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0430(0x0008)(Transient, DuplicateTransient)
	struct FAnimNode_Root                         AnimGraphNode_Root_4AAF732D4F37CA3F8DCE94B33002EBE7; // 0x0438(0x0048)()
	struct FAnimNode_ConvertLocalToComponentSpace AnimGraphNode_LocalToComponentSpace_20F0BA694D35D3FD9E2BDBB9357DA733; // 0x0480(0x0048)()
	struct FAnimNode_CopyPoseFromMesh             AnimGraphNode_CopyPoseFromMesh_C74F96C74EF4CA217AEFE7BB5A9B2D39; // 0x04C8(0x00E8)(ContainsInstancedReference)
	struct FAnimNode_ConvertComponentToLocalSpace AnimGraphNode_ComponentToLocalSpace_BDA7084443718201EC023284E8C9918F; // 0x05B0(0x0048)()
	uint8                                         Pad_5F8[0x8];                                      // 0x05F8(0x0008)(Fixing Size After Last Property [ Dumper-7 ])
	struct FAnimNode_RigidBody                    AnimGraphNode_RigidBody_F32958DA456544FF8E7090BF0B10ABED; // 0x0600(0x0520)()
	struct FAnimNode_AnimDynamics                 AnimGraphNode_AnimDynamics_130377F1445AC9726373FDA9ABC50D1F; // 0x0B20(0x0360)()
	struct FAnimNode_AnimDynamics                 AnimGraphNode_AnimDynamics_83986EED479DA633015302A4184AF563; // 0x0E80(0x0360)()
	class USkeletalMeshComponent*                 MeshToCopy;                                        // 0x11E0(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          DynamicsAlpha;                                     // 0x11E8(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)

public:
	void ExecuteUbergraph_SK_Glider_Googley_Parts_AnimBP(int32 EntryPoint);
	void BlueprintInitializeAnimation();
	void BlueprintUpdateAnimation(float DeltaTimeX);
	void EvaluateGraphExposedInputs_ExecuteUbergraph_SK_Glider_Googley_Parts_AnimBP_AnimGraphNode_CopyPoseFromMesh_C74F96C74EF4CA217AEFE7BB5A9B2D39();
	void EvaluateGraphExposedInputs_ExecuteUbergraph_SK_Glider_Googley_Parts_AnimBP_AnimGraphNode_RigidBody_F32958DA456544FF8E7090BF0B10ABED();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"SK_Glider_Googley_Parts_AnimBP_C">();
	}
	static class USK_Glider_Googley_Parts_AnimBP_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<USK_Glider_Googley_Parts_AnimBP_C>();
	}
};
static_assert(alignof(USK_Glider_Googley_Parts_AnimBP_C) == 0x000010, "Wrong alignment on USK_Glider_Googley_Parts_AnimBP_C");
static_assert(sizeof(USK_Glider_Googley_Parts_AnimBP_C) == 0x0011F0, "Wrong size on USK_Glider_Googley_Parts_AnimBP_C");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, UberGraphFrame) == 0x000430, "Member 'USK_Glider_Googley_Parts_AnimBP_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, AnimGraphNode_Root_4AAF732D4F37CA3F8DCE94B33002EBE7) == 0x000438, "Member 'USK_Glider_Googley_Parts_AnimBP_C::AnimGraphNode_Root_4AAF732D4F37CA3F8DCE94B33002EBE7' has a wrong offset!");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, AnimGraphNode_LocalToComponentSpace_20F0BA694D35D3FD9E2BDBB9357DA733) == 0x000480, "Member 'USK_Glider_Googley_Parts_AnimBP_C::AnimGraphNode_LocalToComponentSpace_20F0BA694D35D3FD9E2BDBB9357DA733' has a wrong offset!");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, AnimGraphNode_CopyPoseFromMesh_C74F96C74EF4CA217AEFE7BB5A9B2D39) == 0x0004C8, "Member 'USK_Glider_Googley_Parts_AnimBP_C::AnimGraphNode_CopyPoseFromMesh_C74F96C74EF4CA217AEFE7BB5A9B2D39' has a wrong offset!");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, AnimGraphNode_ComponentToLocalSpace_BDA7084443718201EC023284E8C9918F) == 0x0005B0, "Member 'USK_Glider_Googley_Parts_AnimBP_C::AnimGraphNode_ComponentToLocalSpace_BDA7084443718201EC023284E8C9918F' has a wrong offset!");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, AnimGraphNode_RigidBody_F32958DA456544FF8E7090BF0B10ABED) == 0x000600, "Member 'USK_Glider_Googley_Parts_AnimBP_C::AnimGraphNode_RigidBody_F32958DA456544FF8E7090BF0B10ABED' has a wrong offset!");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, AnimGraphNode_AnimDynamics_130377F1445AC9726373FDA9ABC50D1F) == 0x000B20, "Member 'USK_Glider_Googley_Parts_AnimBP_C::AnimGraphNode_AnimDynamics_130377F1445AC9726373FDA9ABC50D1F' has a wrong offset!");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, AnimGraphNode_AnimDynamics_83986EED479DA633015302A4184AF563) == 0x000E80, "Member 'USK_Glider_Googley_Parts_AnimBP_C::AnimGraphNode_AnimDynamics_83986EED479DA633015302A4184AF563' has a wrong offset!");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, MeshToCopy) == 0x0011E0, "Member 'USK_Glider_Googley_Parts_AnimBP_C::MeshToCopy' has a wrong offset!");
static_assert(offsetof(USK_Glider_Googley_Parts_AnimBP_C, DynamicsAlpha) == 0x0011E8, "Member 'USK_Glider_Googley_Parts_AnimBP_C::DynamicsAlpha' has a wrong offset!");

}

