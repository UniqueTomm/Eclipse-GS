#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: OptionsMenuInput

#include "Basic.hpp"

#include "Engine_structs.hpp"
#include "UMG_structs.hpp"
#include "SlateCore_structs.hpp"


namespace SDK::Params
{

// Function OptionsMenuInput.OptionsMenuInput_C.Input Clicked__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct OptionsMenuInput_C_Input_Clicked__DelegateSignature final
{
public:
	int32                                         Param_Number_in_List;                              // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          Is_Primary_Button;                                 // 0x0004(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OptionsMenuInput_C_Input_Clicked__DelegateSignature) == 0x000004, "Wrong alignment on OptionsMenuInput_C_Input_Clicked__DelegateSignature");
static_assert(sizeof(OptionsMenuInput_C_Input_Clicked__DelegateSignature) == 0x000008, "Wrong size on OptionsMenuInput_C_Input_Clicked__DelegateSignature");
static_assert(offsetof(OptionsMenuInput_C_Input_Clicked__DelegateSignature, Param_Number_in_List) == 0x000000, "Member 'OptionsMenuInput_C_Input_Clicked__DelegateSignature::Param_Number_in_List' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_Input_Clicked__DelegateSignature, Is_Primary_Button) == 0x000004, "Member 'OptionsMenuInput_C_Input_Clicked__DelegateSignature::Is_Primary_Button' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.UnbindClicked__DelegateSignature
// 0x0010 (0x0010 - 0x0000)
struct OptionsMenuInput_C_UnbindClicked__DelegateSignature final
{
public:
	int32                                         Param_Number_in_List;                              // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UOptionsMenuInput_C*                    Widget;                                            // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_UnbindClicked__DelegateSignature) == 0x000008, "Wrong alignment on OptionsMenuInput_C_UnbindClicked__DelegateSignature");
static_assert(sizeof(OptionsMenuInput_C_UnbindClicked__DelegateSignature) == 0x000010, "Wrong size on OptionsMenuInput_C_UnbindClicked__DelegateSignature");
static_assert(offsetof(OptionsMenuInput_C_UnbindClicked__DelegateSignature, Param_Number_in_List) == 0x000000, "Member 'OptionsMenuInput_C_UnbindClicked__DelegateSignature::Param_Number_in_List' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_UnbindClicked__DelegateSignature, Widget) == 0x000008, "Member 'OptionsMenuInput_C_UnbindClicked__DelegateSignature::Widget' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.ExecuteUbergraph_OptionsMenuInput
// 0x01E8 (0x01E8 - 0x0000)
struct OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput final
{
public:
	int32                                         EntryPoint;                                        // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_4[0x4];                                        // 0x0004(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UCommonButton*                          K2Node_ComponentBoundEvent_Button12;               // 0x0008(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCommonButton*                          K2Node_ComponentBoundEvent_Button1;                // 0x0010(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UObject*                                K2Node_Event_InData;                               // 0x0018(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCommonListView*                        K2Node_Event_OwningList;                           // 0x0020(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UFortOptionsMenuInputData*              K2Node_DynamicCast_AsFort_Options_Menu_Input_Data; // 0x0028(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_DynamicCast_bSuccess;                       // 0x0030(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_31[0x7];                                       // 0x0031(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FFormatArgumentData                    K2Node_MakeStruct_FormatArgumentData;              // 0x0038(0x0040)(HasGetValueTypeHash)
	TArray<struct FFormatArgumentData>            K2Node_MakeArray_Array;                            // 0x0078(0x0010)(ZeroConstructor, ReferenceParm)
	class FText                                   CallFunc_Format_ReturnValue;                       // 0x0088(0x0018)()
	bool                                          K2Node_Event_bSelected;                            // 0x00A0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_A1[0x7];                                       // 0x00A1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	struct FPointerEvent                          K2Node_Event_MouseEvent1;                          // 0x00A8(0x0070)(ConstParm)
	struct FGeometry                              K2Node_Event_MyGeometry;                           // 0x0118(0x0038)(IsPlainOldData, NoDestructor)
	struct FPointerEvent                          K2Node_Event_MouseEvent;                           // 0x0150(0x0070)(ConstParm)
	int32                                         K2Node_Event_InIndexInList;                        // 0x01C0(0x0004)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_1C4[0x4];                                      // 0x01C4(0x0004)(Fixing Size After Last Property [ Dumper-7 ])
	class UCommonButton*                          K2Node_ComponentBoundEvent_Button;                 // 0x01C8(0x0008)(ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	bool                                          K2Node_Event_bExpanded;                            // 0x01D0(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1D1[0x7];                                      // 0x01D1(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	TDelegate<void(class UUserWidget* Widget)>    K2Node_Event_Callback;                             // 0x01D8(0x0010)(ConstParm, ZeroConstructor, NoDestructor)
};
static_assert(alignof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput) == 0x000008, "Wrong alignment on OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput");
static_assert(sizeof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput) == 0x0001E8, "Wrong size on OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, EntryPoint) == 0x000000, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::EntryPoint' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_ComponentBoundEvent_Button12) == 0x000008, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_ComponentBoundEvent_Button12' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_ComponentBoundEvent_Button1) == 0x000010, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_ComponentBoundEvent_Button1' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_Event_InData) == 0x000018, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_Event_InData' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_Event_OwningList) == 0x000020, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_Event_OwningList' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_DynamicCast_AsFort_Options_Menu_Input_Data) == 0x000028, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_DynamicCast_AsFort_Options_Menu_Input_Data' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_DynamicCast_bSuccess) == 0x000030, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_DynamicCast_bSuccess' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_MakeStruct_FormatArgumentData) == 0x000038, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_MakeStruct_FormatArgumentData' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_MakeArray_Array) == 0x000078, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_MakeArray_Array' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, CallFunc_Format_ReturnValue) == 0x000088, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::CallFunc_Format_ReturnValue' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_Event_bSelected) == 0x0000A0, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_Event_bSelected' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_Event_MouseEvent1) == 0x0000A8, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_Event_MouseEvent1' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_Event_MyGeometry) == 0x000118, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_Event_MyGeometry' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_Event_MouseEvent) == 0x000150, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_Event_MouseEvent' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_Event_InIndexInList) == 0x0001C0, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_Event_InIndexInList' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_ComponentBoundEvent_Button) == 0x0001C8, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_ComponentBoundEvent_Button' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_Event_bExpanded) == 0x0001D0, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_Event_bExpanded' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput, K2Node_Event_Callback) == 0x0001D8, "Member 'OptionsMenuInput_C_ExecuteUbergraph_OptionsMenuInput::K2Node_Event_Callback' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.RegisterOnClicked
// 0x0010 (0x0010 - 0x0000)
struct alignas(0x08) OptionsMenuInput_C_RegisterOnClicked final
{
public:
	TDelegate<void(class UUserWidget* Widget)>    Callback;                                          // 0x0000(0x0010)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm, NoDestructor)
};
static_assert(alignof(OptionsMenuInput_C_RegisterOnClicked) == 0x000008, "Wrong alignment on OptionsMenuInput_C_RegisterOnClicked");
static_assert(sizeof(OptionsMenuInput_C_RegisterOnClicked) == 0x000010, "Wrong size on OptionsMenuInput_C_RegisterOnClicked");
static_assert(offsetof(OptionsMenuInput_C_RegisterOnClicked, Callback) == 0x000000, "Member 'OptionsMenuInput_C_RegisterOnClicked::Callback' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.SetExpanded
// 0x0001 (0x0001 - 0x0000)
struct OptionsMenuInput_C_SetExpanded final
{
public:
	bool                                          bExpanded;                                         // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OptionsMenuInput_C_SetExpanded) == 0x000001, "Wrong alignment on OptionsMenuInput_C_SetExpanded");
static_assert(sizeof(OptionsMenuInput_C_SetExpanded) == 0x000001, "Wrong size on OptionsMenuInput_C_SetExpanded");
static_assert(offsetof(OptionsMenuInput_C_SetExpanded, bExpanded) == 0x000000, "Member 'OptionsMenuInput_C_SetExpanded::bExpanded' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.BndEvt__IconTextButton_K2Node_ComponentBoundEvent_226_CommonButtonClicked__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct OptionsMenuInput_C_BndEvt__IconTextButton_K2Node_ComponentBoundEvent_226_CommonButtonClicked__DelegateSignature final
{
public:
	class UCommonButton*                          Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_BndEvt__IconTextButton_K2Node_ComponentBoundEvent_226_CommonButtonClicked__DelegateSignature) == 0x000008, "Wrong alignment on OptionsMenuInput_C_BndEvt__IconTextButton_K2Node_ComponentBoundEvent_226_CommonButtonClicked__DelegateSignature");
static_assert(sizeof(OptionsMenuInput_C_BndEvt__IconTextButton_K2Node_ComponentBoundEvent_226_CommonButtonClicked__DelegateSignature) == 0x000008, "Wrong size on OptionsMenuInput_C_BndEvt__IconTextButton_K2Node_ComponentBoundEvent_226_CommonButtonClicked__DelegateSignature");
static_assert(offsetof(OptionsMenuInput_C_BndEvt__IconTextButton_K2Node_ComponentBoundEvent_226_CommonButtonClicked__DelegateSignature, Button) == 0x000000, "Member 'OptionsMenuInput_C_BndEvt__IconTextButton_K2Node_ComponentBoundEvent_226_CommonButtonClicked__DelegateSignature::Button' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.OnMouseEnter
// 0x00A8 (0x00A8 - 0x0000)
struct OptionsMenuInput_C_OnMouseEnter final
{
public:
	struct FGeometry                              MyGeometry;                                        // 0x0000(0x0038)(BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
	struct FPointerEvent                          MouseEvent;                                        // 0x0038(0x0070)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(OptionsMenuInput_C_OnMouseEnter) == 0x000008, "Wrong alignment on OptionsMenuInput_C_OnMouseEnter");
static_assert(sizeof(OptionsMenuInput_C_OnMouseEnter) == 0x0000A8, "Wrong size on OptionsMenuInput_C_OnMouseEnter");
static_assert(offsetof(OptionsMenuInput_C_OnMouseEnter, MyGeometry) == 0x000000, "Member 'OptionsMenuInput_C_OnMouseEnter::MyGeometry' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_OnMouseEnter, MouseEvent) == 0x000038, "Member 'OptionsMenuInput_C_OnMouseEnter::MouseEvent' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.OnMouseLeave
// 0x0070 (0x0070 - 0x0000)
struct OptionsMenuInput_C_OnMouseLeave final
{
public:
	struct FPointerEvent                          MouseEvent;                                        // 0x0000(0x0070)(ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
};
static_assert(alignof(OptionsMenuInput_C_OnMouseLeave) == 0x000008, "Wrong alignment on OptionsMenuInput_C_OnMouseLeave");
static_assert(sizeof(OptionsMenuInput_C_OnMouseLeave) == 0x000070, "Wrong size on OptionsMenuInput_C_OnMouseLeave");
static_assert(offsetof(OptionsMenuInput_C_OnMouseLeave, MouseEvent) == 0x000000, "Member 'OptionsMenuInput_C_OnMouseLeave::MouseEvent' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.SetData
// 0x0010 (0x0010 - 0x0000)
struct OptionsMenuInput_C_SetData final
{
public:
	class UObject*                                InData;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	class UCommonListView*                        OwningList;                                        // 0x0008(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_SetData) == 0x000008, "Wrong alignment on OptionsMenuInput_C_SetData");
static_assert(sizeof(OptionsMenuInput_C_SetData) == 0x000010, "Wrong size on OptionsMenuInput_C_SetData");
static_assert(offsetof(OptionsMenuInput_C_SetData, InData) == 0x000000, "Member 'OptionsMenuInput_C_SetData::InData' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_SetData, OwningList) == 0x000008, "Member 'OptionsMenuInput_C_SetData::OwningList' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.BndEvt__SecondaryInput_K2Node_ComponentBoundEvent_55_CommonButtonClicked__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct OptionsMenuInput_C_BndEvt__SecondaryInput_K2Node_ComponentBoundEvent_55_CommonButtonClicked__DelegateSignature final
{
public:
	class UCommonButton*                          Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_BndEvt__SecondaryInput_K2Node_ComponentBoundEvent_55_CommonButtonClicked__DelegateSignature) == 0x000008, "Wrong alignment on OptionsMenuInput_C_BndEvt__SecondaryInput_K2Node_ComponentBoundEvent_55_CommonButtonClicked__DelegateSignature");
static_assert(sizeof(OptionsMenuInput_C_BndEvt__SecondaryInput_K2Node_ComponentBoundEvent_55_CommonButtonClicked__DelegateSignature) == 0x000008, "Wrong size on OptionsMenuInput_C_BndEvt__SecondaryInput_K2Node_ComponentBoundEvent_55_CommonButtonClicked__DelegateSignature");
static_assert(offsetof(OptionsMenuInput_C_BndEvt__SecondaryInput_K2Node_ComponentBoundEvent_55_CommonButtonClicked__DelegateSignature, Button) == 0x000000, "Member 'OptionsMenuInput_C_BndEvt__SecondaryInput_K2Node_ComponentBoundEvent_55_CommonButtonClicked__DelegateSignature::Button' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.BndEvt__PrimaryInput_K2Node_ComponentBoundEvent_33_CommonButtonClicked__DelegateSignature
// 0x0008 (0x0008 - 0x0000)
struct OptionsMenuInput_C_BndEvt__PrimaryInput_K2Node_ComponentBoundEvent_33_CommonButtonClicked__DelegateSignature final
{
public:
	class UCommonButton*                          Button;                                            // 0x0000(0x0008)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_BndEvt__PrimaryInput_K2Node_ComponentBoundEvent_33_CommonButtonClicked__DelegateSignature) == 0x000008, "Wrong alignment on OptionsMenuInput_C_BndEvt__PrimaryInput_K2Node_ComponentBoundEvent_33_CommonButtonClicked__DelegateSignature");
static_assert(sizeof(OptionsMenuInput_C_BndEvt__PrimaryInput_K2Node_ComponentBoundEvent_33_CommonButtonClicked__DelegateSignature) == 0x000008, "Wrong size on OptionsMenuInput_C_BndEvt__PrimaryInput_K2Node_ComponentBoundEvent_33_CommonButtonClicked__DelegateSignature");
static_assert(offsetof(OptionsMenuInput_C_BndEvt__PrimaryInput_K2Node_ComponentBoundEvent_33_CommonButtonClicked__DelegateSignature, Button) == 0x000000, "Member 'OptionsMenuInput_C_BndEvt__PrimaryInput_K2Node_ComponentBoundEvent_33_CommonButtonClicked__DelegateSignature::Button' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.SetSelected
// 0x0001 (0x0001 - 0x0000)
struct OptionsMenuInput_C_SetSelected final
{
public:
	bool                                          bSelected;                                         // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OptionsMenuInput_C_SetSelected) == 0x000001, "Wrong alignment on OptionsMenuInput_C_SetSelected");
static_assert(sizeof(OptionsMenuInput_C_SetSelected) == 0x000001, "Wrong size on OptionsMenuInput_C_SetSelected");
static_assert(offsetof(OptionsMenuInput_C_SetSelected, bSelected) == 0x000000, "Member 'OptionsMenuInput_C_SetSelected::bSelected' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.SetIndexInList
// 0x0004 (0x0004 - 0x0000)
struct OptionsMenuInput_C_SetIndexInList final
{
public:
	int32                                         InIndexInList;                                     // 0x0000(0x0004)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_SetIndexInList) == 0x000004, "Wrong alignment on OptionsMenuInput_C_SetIndexInList");
static_assert(sizeof(OptionsMenuInput_C_SetIndexInList) == 0x000004, "Wrong size on OptionsMenuInput_C_SetIndexInList");
static_assert(offsetof(OptionsMenuInput_C_SetIndexInList, InIndexInList) == 0x000000, "Member 'OptionsMenuInput_C_SetIndexInList::InIndexInList' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.Center on Widget
// 0x0008 (0x0008 - 0x0000)
struct OptionsMenuInput_C_Center_on_Widget final
{
public:
	class UFortUINavigationManager*               CallFunc_GetUINavigationManager_ReturnValue;       // 0x0000(0x0008)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_Center_on_Widget) == 0x000008, "Wrong alignment on OptionsMenuInput_C_Center_on_Widget");
static_assert(sizeof(OptionsMenuInput_C_Center_on_Widget) == 0x000008, "Wrong size on OptionsMenuInput_C_Center_on_Widget");
static_assert(offsetof(OptionsMenuInput_C_Center_on_Widget, CallFunc_GetUINavigationManager_ReturnValue) == 0x000000, "Member 'OptionsMenuInput_C_Center_on_Widget::CallFunc_GetUINavigationManager_ReturnValue' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.Change Key
// 0x0020 (0x0020 - 0x0000)
struct OptionsMenuInput_C_Change_Key final
{
public:
	bool                                          Primary_Key;                                       // 0x0000(0x0001)(BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
	uint8                                         Pad_1[0x7];                                        // 0x0001(0x0007)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   Key_To_Sets;                                       // 0x0008(0x0018)(BlueprintVisible, BlueprintReadOnly, Parm)
};
static_assert(alignof(OptionsMenuInput_C_Change_Key) == 0x000008, "Wrong alignment on OptionsMenuInput_C_Change_Key");
static_assert(sizeof(OptionsMenuInput_C_Change_Key) == 0x000020, "Wrong size on OptionsMenuInput_C_Change_Key");
static_assert(offsetof(OptionsMenuInput_C_Change_Key, Primary_Key) == 0x000000, "Member 'OptionsMenuInput_C_Change_Key::Primary_Key' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_Change_Key, Key_To_Sets) == 0x000008, "Member 'OptionsMenuInput_C_Change_Key::Key_To_Sets' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.SetClearButtonVisibility
// 0x0028 (0x0028 - 0x0000)
struct OptionsMenuInput_C_SetClearButtonVisibility final
{
public:
	bool                                          Temp_bool_Variable;                                // 0x0000(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              Temp_byte_Variable;                                // 0x0001(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	ESlateVisibility                              Temp_byte_Variable1;                               // 0x0002(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
	uint8                                         Pad_3[0x5];                                        // 0x0003(0x0005)(Fixing Size After Last Property [ Dumper-7 ])
	class FText                                   CallFunc_MakeLiteralText_ReturnValue;              // 0x0008(0x0018)()
	bool                                          CallFunc_EqualEqual_TextText_ReturnValue;          // 0x0020(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_EqualEqual_TextText_ReturnValue1;         // 0x0021(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	bool                                          CallFunc_BooleanAND_ReturnValue;                   // 0x0022(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor)
	ESlateVisibility                              K2Node_Select_Default;                             // 0x0023(0x0001)(ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_SetClearButtonVisibility) == 0x000008, "Wrong alignment on OptionsMenuInput_C_SetClearButtonVisibility");
static_assert(sizeof(OptionsMenuInput_C_SetClearButtonVisibility) == 0x000028, "Wrong size on OptionsMenuInput_C_SetClearButtonVisibility");
static_assert(offsetof(OptionsMenuInput_C_SetClearButtonVisibility, Temp_bool_Variable) == 0x000000, "Member 'OptionsMenuInput_C_SetClearButtonVisibility::Temp_bool_Variable' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_SetClearButtonVisibility, Temp_byte_Variable) == 0x000001, "Member 'OptionsMenuInput_C_SetClearButtonVisibility::Temp_byte_Variable' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_SetClearButtonVisibility, Temp_byte_Variable1) == 0x000002, "Member 'OptionsMenuInput_C_SetClearButtonVisibility::Temp_byte_Variable1' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_SetClearButtonVisibility, CallFunc_MakeLiteralText_ReturnValue) == 0x000008, "Member 'OptionsMenuInput_C_SetClearButtonVisibility::CallFunc_MakeLiteralText_ReturnValue' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_SetClearButtonVisibility, CallFunc_EqualEqual_TextText_ReturnValue) == 0x000020, "Member 'OptionsMenuInput_C_SetClearButtonVisibility::CallFunc_EqualEqual_TextText_ReturnValue' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_SetClearButtonVisibility, CallFunc_EqualEqual_TextText_ReturnValue1) == 0x000021, "Member 'OptionsMenuInput_C_SetClearButtonVisibility::CallFunc_EqualEqual_TextText_ReturnValue1' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_SetClearButtonVisibility, CallFunc_BooleanAND_ReturnValue) == 0x000022, "Member 'OptionsMenuInput_C_SetClearButtonVisibility::CallFunc_BooleanAND_ReturnValue' has a wrong offset!");
static_assert(offsetof(OptionsMenuInput_C_SetClearButtonVisibility, K2Node_Select_Default) == 0x000023, "Member 'OptionsMenuInput_C_SetClearButtonVisibility::K2Node_Select_Default' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.GetData
// 0x0008 (0x0008 - 0x0000)
struct OptionsMenuInput_C_GetData final
{
public:
	class UObject*                                ReturnValue;                                       // 0x0000(0x0008)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_GetData) == 0x000008, "Wrong alignment on OptionsMenuInput_C_GetData");
static_assert(sizeof(OptionsMenuInput_C_GetData) == 0x000008, "Wrong size on OptionsMenuInput_C_GetData");
static_assert(offsetof(OptionsMenuInput_C_GetData, ReturnValue) == 0x000000, "Member 'OptionsMenuInput_C_GetData::ReturnValue' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.IsItemExpanded
// 0x0001 (0x0001 - 0x0000)
struct OptionsMenuInput_C_IsItemExpanded final
{
public:
	bool                                          ReturnValue;                                       // 0x0000(0x0001)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor)
};
static_assert(alignof(OptionsMenuInput_C_IsItemExpanded) == 0x000001, "Wrong alignment on OptionsMenuInput_C_IsItemExpanded");
static_assert(sizeof(OptionsMenuInput_C_IsItemExpanded) == 0x000001, "Wrong size on OptionsMenuInput_C_IsItemExpanded");
static_assert(offsetof(OptionsMenuInput_C_IsItemExpanded, ReturnValue) == 0x000000, "Member 'OptionsMenuInput_C_IsItemExpanded::ReturnValue' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.DoesItemHaveChildren
// 0x0004 (0x0004 - 0x0000)
struct OptionsMenuInput_C_DoesItemHaveChildren final
{
public:
	int32                                         ReturnValue;                                       // 0x0000(0x0004)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_DoesItemHaveChildren) == 0x000004, "Wrong alignment on OptionsMenuInput_C_DoesItemHaveChildren");
static_assert(sizeof(OptionsMenuInput_C_DoesItemHaveChildren) == 0x000004, "Wrong size on OptionsMenuInput_C_DoesItemHaveChildren");
static_assert(offsetof(OptionsMenuInput_C_DoesItemHaveChildren, ReturnValue) == 0x000000, "Member 'OptionsMenuInput_C_DoesItemHaveChildren::ReturnValue' has a wrong offset!");

// Function OptionsMenuInput.OptionsMenuInput_C.GetIndentLevel
// 0x0004 (0x0004 - 0x0000)
struct OptionsMenuInput_C_GetIndentLevel final
{
public:
	int32                                         ReturnValue;                                       // 0x0000(0x0004)(Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
};
static_assert(alignof(OptionsMenuInput_C_GetIndentLevel) == 0x000004, "Wrong alignment on OptionsMenuInput_C_GetIndentLevel");
static_assert(sizeof(OptionsMenuInput_C_GetIndentLevel) == 0x000004, "Wrong size on OptionsMenuInput_C_GetIndentLevel");
static_assert(offsetof(OptionsMenuInput_C_GetIndentLevel, ReturnValue) == 0x000000, "Member 'OptionsMenuInput_C_GetIndentLevel::ReturnValue' has a wrong offset!");

}

