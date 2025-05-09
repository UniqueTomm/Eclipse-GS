#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Results_Badge

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "CommonUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass Results_Badge.Results_Badge_C
// 0x0078 (0x0290 - 0x0218)
class UResults_Badge_C final : public UCommonUserWidget
{
public:
	struct FPointerToUberGraphFrame               UberGraphFrame;                                    // 0x0218(0x0008)(Transient, DuplicateTransient)
	class UWidgetAnimation*                       Anim_Reset;                                        // 0x0220(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Anim_Convert;                                      // 0x0228(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UWidgetAnimation*                       Anim_Intro;                                        // 0x0230(0x0008)(BlueprintVisible, ExportObject, BlueprintReadOnly, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UFortItemIcon*                          FortItemIcon_0;                                    // 0x0238(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class USizeBox*                               ItemCardBox;                                       // 0x0240(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TextBadgeName;                                     // 0x0248(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UCommonTextBlock*                       TextDebugID;                                       // 0x0250(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)
	class UFortItem*                              BadgeItem;                                         // 0x0258(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	UMulticastDelegateProperty_                   ConvertFinished;                                   // 0x0260(0x0010)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, BlueprintAssignable, BlueprintCallable)
	class FString                                 DebugIDText;                                       // 0x0270(0x0010)(Edit, BlueprintVisible, ZeroConstructor, HasGetValueTypeHash)
	float                                         PlayRate;                                          // 0x0280(0x0004)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          bSkippingToEnd;                                    // 0x0284(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	bool                                          bSkippedToEnd;                                     // 0x0285(0x0001)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor)
	uint8                                         Pad_286[0x2];                                      // 0x0286(0x0002)(Fixing Size After Last Property [ Dumper-7 ])
	class USoundBase*                             BadgeWhooshToChest;                                // 0x0288(0x0008)(Edit, BlueprintVisible, ZeroConstructor, DisableEditOnInstance, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

public:
	void ConvertFinished__DelegateSignature();
	void ExecuteUbergraph_Results_Badge(int32 EntryPoint);
	void Reset_Sequence();
	void PreConstruct(bool IsDesignTime);
	void BndEvt__Anim_Convert_K2Node_ComponentBoundEvent_1_OnWidgetAnimationPlaybackStatusChanged__DelegateSignature();
	void Convert_Sequence();
	void Intro_Sequence();
	void SetItem(class UFortItem* Item);
	void HasValidItem(bool* Param_HasValidItem);
	void Initialize(float Param_PlayRate);
	void SetSkippingToEnd();
	void DoDesignTimeRandomization();
	void SkipToFinalState();

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"Results_Badge_C">();
	}
	static class UResults_Badge_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UResults_Badge_C>();
	}
};
static_assert(alignof(UResults_Badge_C) == 0x000008, "Wrong alignment on UResults_Badge_C");
static_assert(sizeof(UResults_Badge_C) == 0x000290, "Wrong size on UResults_Badge_C");
static_assert(offsetof(UResults_Badge_C, UberGraphFrame) == 0x000218, "Member 'UResults_Badge_C::UberGraphFrame' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, Anim_Reset) == 0x000220, "Member 'UResults_Badge_C::Anim_Reset' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, Anim_Convert) == 0x000228, "Member 'UResults_Badge_C::Anim_Convert' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, Anim_Intro) == 0x000230, "Member 'UResults_Badge_C::Anim_Intro' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, FortItemIcon_0) == 0x000238, "Member 'UResults_Badge_C::FortItemIcon_0' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, ItemCardBox) == 0x000240, "Member 'UResults_Badge_C::ItemCardBox' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, TextBadgeName) == 0x000248, "Member 'UResults_Badge_C::TextBadgeName' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, TextDebugID) == 0x000250, "Member 'UResults_Badge_C::TextDebugID' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, BadgeItem) == 0x000258, "Member 'UResults_Badge_C::BadgeItem' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, ConvertFinished) == 0x000260, "Member 'UResults_Badge_C::ConvertFinished' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, DebugIDText) == 0x000270, "Member 'UResults_Badge_C::DebugIDText' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, PlayRate) == 0x000280, "Member 'UResults_Badge_C::PlayRate' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, bSkippingToEnd) == 0x000284, "Member 'UResults_Badge_C::bSkippingToEnd' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, bSkippedToEnd) == 0x000285, "Member 'UResults_Badge_C::bSkippedToEnd' has a wrong offset!");
static_assert(offsetof(UResults_Badge_C, BadgeWhooshToChest) == 0x000288, "Member 'UResults_Badge_C::BadgeWhooshToChest' has a wrong offset!");

}

