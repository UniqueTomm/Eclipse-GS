#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: CollectionBookItemPickerButton

#include "Basic.hpp"

#include "FortniteUI_classes.hpp"


namespace SDK
{

// WidgetBlueprintGeneratedClass CollectionBookItemPickerButton.CollectionBookItemPickerButton_C
// 0x0008 (0x0840 - 0x0838)
class UCollectionBookItemPickerButton_C final : public UFortItemPickerButton
{
public:
	class UWidgetSwitcher*                        RootWidgetSwitcher;                                // 0x0838(0x0008)(BlueprintVisible, ExportObject, ZeroConstructor, InstancedReference, IsPlainOldData, RepSkip, NoDestructor, PersistentInstance, HasGetValueTypeHash)

public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"CollectionBookItemPickerButton_C">();
	}
	static class UCollectionBookItemPickerButton_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UCollectionBookItemPickerButton_C>();
	}
};
static_assert(alignof(UCollectionBookItemPickerButton_C) == 0x000008, "Wrong alignment on UCollectionBookItemPickerButton_C");
static_assert(sizeof(UCollectionBookItemPickerButton_C) == 0x000840, "Wrong size on UCollectionBookItemPickerButton_C");
static_assert(offsetof(UCollectionBookItemPickerButton_C, RootWidgetSwitcher) == 0x000838, "Member 'UCollectionBookItemPickerButton_C::RootWidgetSwitcher' has a wrong offset!");

}

