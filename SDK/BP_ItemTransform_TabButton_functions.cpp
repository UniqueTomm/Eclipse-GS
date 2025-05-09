#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: BP_ItemTransform_TabButton

#include "Basic.hpp"

#include "BP_ItemTransform_TabButton_classes.hpp"
#include "BP_ItemTransform_TabButton_parameters.hpp"


namespace SDK
{

// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.ExecuteUbergraph_BP_ItemTransform_TabButton
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_ItemTransform_TabButton_C::ExecuteUbergraph_BP_ItemTransform_TabButton(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "ExecuteUbergraph_BP_ItemTransform_TabButton");

	Params::BP_ItemTransform_TabButton_C_ExecuteUbergraph_BP_ItemTransform_TabButton Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.OnUnhovered
// (Event, Protected, BlueprintEvent)

void UBP_ItemTransform_TabButton_C::OnUnhovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "OnUnhovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.OnHovered
// (Event, Protected, BlueprintEvent)

void UBP_ItemTransform_TabButton_C::OnHovered()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "OnHovered");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.OnDeselected
// (Event, Protected, BlueprintEvent)

void UBP_ItemTransform_TabButton_C::OnDeselected()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "OnDeselected");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.OnSelected
// (Event, Protected, BlueprintEvent)

void UBP_ItemTransform_TabButton_C::OnSelected()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "OnSelected");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UBP_ItemTransform_TabButton_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.SetTabLabelInfo
// (Event, Public, HasOutParams, BlueprintEvent)
// Parameters:
// struct FFortTabButtonLabelInfo          TabLabelInfo                                           (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)

void UBP_ItemTransform_TabButton_C::SetTabLabelInfo(const struct FFortTabButtonLabelInfo& TabLabelInfo)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "SetTabLabelInfo");

	Params::BP_ItemTransform_TabButton_C_SetTabLabelInfo Parms{};

	Parms.TabLabelInfo = std::move(TabLabelInfo);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.PreConstruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)
// Parameters:
// bool                                    IsDesignTime                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UBP_ItemTransform_TabButton_C::PreConstruct(bool IsDesignTime)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "PreConstruct");

	Params::BP_ItemTransform_TabButton_C_PreConstruct Parms{};

	Parms.IsDesignTime = IsDesignTime;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.OnCurrentTextStyleChanged
// (Event, Protected, BlueprintEvent)

void UBP_ItemTransform_TabButton_C::OnCurrentTextStyleChanged()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "OnCurrentTextStyleChanged");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.Set Text
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FText                             Param_ButtonText                                       (BlueprintVisible, BlueprintReadOnly, Parm)

void UBP_ItemTransform_TabButton_C::Set_Text(const class FText& Param_ButtonText)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "Set Text");

	Params::BP_ItemTransform_TabButton_C_Set_Text Parms{};

	Parms.Param_ButtonText = std::move(Param_ButtonText);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.Set Icon
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FSlateBrush                      Param_IconBrush                                        (BlueprintVisible, BlueprintReadOnly, Parm)

void UBP_ItemTransform_TabButton_C::Set_Icon(const struct FSlateBrush& Param_IconBrush)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "Set Icon");

	Params::BP_ItemTransform_TabButton_C_Set_Icon Parms{};

	Parms.Param_IconBrush = std::move(Param_IconBrush);

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.Refresh Bang State
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void UBP_ItemTransform_TabButton_C::Refresh_Bang_State()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "Refresh Bang State");

	UObject::ProcessEvent(Func, nullptr);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.Set Tab Id
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class FName                             Param_TabId                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UBP_ItemTransform_TabButton_C::Set_Tab_Id(class FName Param_TabId)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "Set Tab Id");

	Params::BP_ItemTransform_TabButton_C_Set_Tab_Id Parms{};

	Parms.Param_TabId = Param_TabId;

	UObject::ProcessEvent(Func, &Parms);
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.Get Tab Id as Request Type
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// EConversionControlKeyRequest            ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

EConversionControlKeyRequest UBP_ItemTransform_TabButton_C::Get_Tab_Id_as_Request_Type()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "Get Tab Id as Request Type");

	Params::BP_ItemTransform_TabButton_C_Get_Tab_Id_as_Request_Type Parms{};

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function BP_ItemTransform_TabButton.BP_ItemTransform_TabButton_C.Refresh Bang State Internal
// (Private, BlueprintCallable, BlueprintEvent)

void UBP_ItemTransform_TabButton_C::Refresh_Bang_State_Internal()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("BP_ItemTransform_TabButton_C", "Refresh Bang State Internal");

	UObject::ProcessEvent(Func, nullptr);
}

}

