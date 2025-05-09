#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: FrontEnd

#include "Basic.hpp"

#include "FrontEnd_classes.hpp"
#include "FrontEnd_parameters.hpp"


namespace SDK
{

// Function FrontEnd.FrontEnd_C.ExecuteUbergraph_FrontEnd
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::ExecuteUbergraph_FrontEnd(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "ExecuteUbergraph_FrontEnd");

	Params::FrontEnd_C_ExecuteUbergraph_FrontEnd Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.OnEnterState
// (Event, Public, BlueprintEvent)
// Parameters:
// EFortUIState                            Param_PreviousUIState                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::OnEnterState(EFortUIState Param_PreviousUIState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "OnEnterState");

	Params::FrontEnd_C_OnEnterState Parms{};

	Parms.Param_PreviousUIState = Param_PreviousUIState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.On Can PTT
// (BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::On_Can_PTT()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "On Can PTT");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.BndEvt__ButtonPTT_K2Node_ComponentBoundEvent_138_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButton*                    Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::BndEvt__ButtonPTT_K2Node_ComponentBoundEvent_138_CommonButtonClicked__DelegateSignature(class UCommonButton* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "BndEvt__ButtonPTT_K2Node_ComponentBoundEvent_138_CommonButtonClicked__DelegateSignature");

	Params::FrontEnd_C_BndEvt__ButtonPTT_K2Node_ComponentBoundEvent_138_CommonButtonClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.BndEvt__ButtonToggleChat_K2Node_ComponentBoundEvent_39_CommonSelectedStateChanged__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButton*                    Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    Selected                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::BndEvt__ButtonToggleChat_K2Node_ComponentBoundEvent_39_CommonSelectedStateChanged__DelegateSignature(class UCommonButton* Button, bool Selected)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "BndEvt__ButtonToggleChat_K2Node_ComponentBoundEvent_39_CommonSelectedStateChanged__DelegateSignature");

	Params::FrontEnd_C_BndEvt__ButtonToggleChat_K2Node_ComponentBoundEvent_39_CommonSelectedStateChanged__DelegateSignature Parms{};

	Parms.Button = Button;
	Parms.Selected = Selected;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.HandleQuestsGranted
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// TArray<class UFortQuestItem*>           Quests                                                 (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)

void UFrontEnd_C::HandleQuestsGranted(const TArray<class UFortQuestItem*>& Quests)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleQuestsGranted");

	Params::FrontEnd_C_HandleQuestsGranted Parms{};

	Parms.Quests = std::move(Quests);

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.BndEvt__ButtonToggleChat_K2Node_ComponentBoundEvent_6_CommonButtonClicked__DelegateSignature
// (BlueprintEvent)
// Parameters:
// class UCommonButton*                    Button                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::BndEvt__ButtonToggleChat_K2Node_ComponentBoundEvent_6_CommonButtonClicked__DelegateSignature(class UCommonButton* Button)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "BndEvt__ButtonToggleChat_K2Node_ComponentBoundEvent_6_CommonButtonClicked__DelegateSignature");

	Params::FrontEnd_C_BndEvt__ButtonToggleChat_K2Node_ComponentBoundEvent_6_CommonButtonClicked__DelegateSignature Parms{};

	Parms.Button = Button;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.Loading Screen Changed
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_IsVisible                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::Loading_Screen_Changed(bool Param_IsVisible)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "Loading Screen Changed");

	Params::FrontEnd_C_Loading_Screen_Changed Parms{};

	Parms.Param_IsVisible = Param_IsVisible;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.Construct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UFrontEnd_C::Construct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "Construct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.OnGiftBoxRemoved
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bSuccess                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::OnGiftBoxRemoved(bool bSuccess)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "OnGiftBoxRemoved");

	Params::FrontEnd_C_OnGiftBoxRemoved Parms{};

	Parms.bSuccess = bSuccess;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.Check For Gifts
// (BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::Check_For_Gifts()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "Check For Gifts");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.Gifting Complete
// (BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::Gifting_Complete()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "Gifting Complete");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.OnGiftNotifyReceived
// (Event, Protected, BlueprintEvent)

void UFrontEnd_C::OnGiftNotifyReceived()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "OnGiftNotifyReceived");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.RequestOpenSocialMenu
// (Event, Public, BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::RequestOpenSocialMenu()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "RequestOpenSocialMenu");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.HandleClientEvent_NotPlayingEventMovie
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          EventSource                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          EventFocus                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FFortClientEvent                 ClientEvent                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)

void UFrontEnd_C::HandleClientEvent_NotPlayingEventMovie(class UObject* EventSource, class UObject* EventFocus, const struct FFortClientEvent& ClientEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleClientEvent_NotPlayingEventMovie");

	Params::FrontEnd_C_HandleClientEvent_NotPlayingEventMovie Parms{};

	Parms.EventSource = EventSource;
	Parms.EventFocus = EventFocus;
	Parms.ClientEvent = std::move(ClientEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.HandleClientEvent_EventMovieFinishedPlaying
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          EventSource                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          EventFocus                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FFortClientEvent                 ClientEvent                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)

void UFrontEnd_C::HandleClientEvent_EventMovieFinishedPlaying(class UObject* EventSource, class UObject* EventFocus, const struct FFortClientEvent& ClientEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleClientEvent_EventMovieFinishedPlaying");

	Params::FrontEnd_C_HandleClientEvent_EventMovieFinishedPlaying Parms{};

	Parms.EventSource = EventSource;
	Parms.EventFocus = EventFocus;
	Parms.ClientEvent = std::move(ClientEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.OnFrontEndVisibilityUpdated
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bHideHeader                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    bHideFooter                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    bHideChatWidget                                        (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::OnFrontEndVisibilityUpdated(bool bHideHeader, bool bHideFooter, bool bHideChatWidget)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "OnFrontEndVisibilityUpdated");

	Params::FrontEnd_C_OnFrontEndVisibilityUpdated Parms{};

	Parms.bHideHeader = bHideHeader;
	Parms.bHideFooter = bHideFooter;
	Parms.bHideChatWidget = bHideChatWidget;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.HandleClientEvent_FinishedModalWindows
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UObject*                          EventSource                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class UObject*                          EventFocus                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FFortClientEvent                 ClientEvent                                            (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm, NoDestructor)

void UFrontEnd_C::HandleClientEvent_FinishedModalWindows(class UObject* EventSource, class UObject* EventFocus, const struct FFortClientEvent& ClientEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleClientEvent_FinishedModalWindows");

	Params::FrontEnd_C_HandleClientEvent_FinishedModalWindows Parms{};

	Parms.EventSource = EventSource;
	Parms.EventFocus = EventFocus;
	Parms.ClientEvent = std::move(ClientEvent);

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.DailyRewardsTokenGranted
// (BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::DailyRewardsTokenGranted()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "DailyRewardsTokenGranted");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.Destruct
// (BlueprintCosmetic, Event, Public, BlueprintEvent)

void UFrontEnd_C::Destruct()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "Destruct");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.OnExitState
// (Event, Public, BlueprintEvent)
// Parameters:
// EFortUIState                            NextUIState                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::OnExitState(EFortUIState NextUIState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "OnExitState");

	Params::FrontEnd_C_OnExitState Parms{};

	Parms.NextUIState = NextUIState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.PushContentWidgetInternal
// (Event, Protected, BlueprintEvent)
// Parameters:
// class UWidget*                          Widget                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// struct FContentPushState                State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)

void UFrontEnd_C::PushContentWidgetInternal(class UWidget* Widget, const struct FContentPushState& State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "PushContentWidgetInternal");

	Params::FrontEnd_C_PushContentWidgetInternal Parms{};

	Parms.Widget = Widget;
	Parms.State = std::move(State);

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.HandleLobbyDisconnected
// (BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::HandleLobbyDisconnected()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleLobbyDisconnected");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.HandleQuestsCompleted
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// TArray<class UFortQuestItem*>           Quests                                                 (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)

void UFrontEnd_C::HandleQuestsCompleted(const TArray<class UFortQuestItem*>& Quests)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleQuestsCompleted");

	Params::FrontEnd_C_HandleQuestsCompleted Parms{};

	Parms.Quests = std::move(Quests);

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.On_MainAreaDarken_MouseButtonUp
// (Private, HasOutParams, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGeometry                        MyGeometry                                             (BlueprintVisible, BlueprintReadOnly, Parm, IsPlainOldData, NoDestructor)
// struct FPointerEvent                    MouseEvent                                             (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FEventReply                      ReturnValue                                            (Parm, OutParm, ReturnParm)

struct FEventReply UFrontEnd_C::On_MainAreaDarken_MouseButtonUp(const struct FGeometry& MyGeometry, struct FPointerEvent& MouseEvent)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "On_MainAreaDarken_MouseButtonUp");

	Params::FrontEnd_C_On_MainAreaDarken_MouseButtonUp Parms{};

	Parms.MyGeometry = std::move(MyGeometry);
	Parms.MouseEvent = std::move(MouseEvent);

	UObject::ProcessEvent(Func, &Parms);

	MouseEvent = std::move(Parms.MouseEvent);

	return Parms.ReturnValue;
}


// Function FrontEnd.FrontEnd_C.HandleMainMenuStateChanged
// (Private, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_Index                                            (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::HandleMainMenuStateChanged(bool Param_Index)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleMainMenuStateChanged");

	Params::FrontEnd_C_HandleMainMenuStateChanged Parms{};

	Parms.Param_Index = Param_Index;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.RegisterScriptedActions
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// EFortUIState                            InPreviousUIState                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::RegisterScriptedActions(EFortUIState InPreviousUIState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "RegisterScriptedActions");

	Params::FrontEnd_C_RegisterScriptedActions Parms{};

	Parms.InPreviousUIState = InPreviousUIState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.PushContentWidget_Internal
// (Private, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWidget*                          InWidget                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// bool                                    HideHeader                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    HideFooter                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::PushContentWidget_Internal(class UWidget* InWidget, bool HideHeader, bool HideFooter)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "PushContentWidget_Internal");

	Params::FrontEnd_C_PushContentWidget_Internal Parms{};

	Parms.InWidget = InWidget;
	Parms.HideHeader = HideHeader;
	Parms.HideFooter = HideFooter;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.SetHeaderVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Visible                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::SetHeaderVisibility(bool Visible)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "SetHeaderVisibility");

	Params::FrontEnd_C_SetHeaderVisibility Parms{};

	Parms.Visible = Visible;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.PopContentWidget_Internal
// (Public, BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::PopContentWidget_Internal()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "PopContentWidget_Internal");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.SetFooterVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Visible                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::SetFooterVisibility(bool Visible)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "SetFooterVisibility");

	Params::FrontEnd_C_SetFooterVisibility Parms{};

	Parms.Visible = Visible;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.HandleEnterFrontend
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// EFortUIState                            UIState                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::HandleEnterFrontend(EFortUIState UIState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleEnterFrontend");

	Params::FrontEnd_C_HandleEnterFrontend Parms{};

	Parms.UIState = UIState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.BindDelegates
// (Public, BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::BindDelegates()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "BindDelegates");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.HandleQuestRewardClaimed
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UFortQuestItem*                   Quest                                                  (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// TArray<struct FFortItemInstanceQuantityPair>Rewards                                                (BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ZeroConstructor, ReferenceParm)

void UFrontEnd_C::HandleQuestRewardClaimed(class UFortQuestItem* Quest, TArray<struct FFortItemInstanceQuantityPair>& Rewards)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleQuestRewardClaimed");

	Params::FrontEnd_C_HandleQuestRewardClaimed Parms{};

	Parms.Quest = Quest;
	Parms.Rewards = std::move(Rewards);

	UObject::ProcessEvent(Func, &Parms);

	Rewards = std::move(Parms.Rewards);
}


// Function FrontEnd.FrontEnd_C.PopContentWidgetInternal
// (Event, Protected, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FContentPushState                State                                                  (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor)
// class UWidget*                          ReturnValue                                            (Parm, OutParm, ZeroConstructor, ReturnParm, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

class UWidget* UFrontEnd_C::PopContentWidgetInternal(const struct FContentPushState& State)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "PopContentWidgetInternal");

	Params::FrontEnd_C_PopContentWidgetInternal Parms{};

	Parms.State = std::move(State);

	UObject::ProcessEvent(Func, &Parms);

	return Parms.ReturnValue;
}


// Function FrontEnd.FrontEnd_C.HandlePopContentStackOp
// (Public, BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::HandlePopContentStackOp()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandlePopContentStackOp");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.UnbindDelegates
// (Public, BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::UnbindDelegates()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "UnbindDelegates");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.HandleWidgetStackChanged
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// class UWidget*                          Widget                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, InstancedReference, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// int32                                   ActiveWidgetIndex                                      (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::HandleWidgetStackChanged(class UWidget* Widget, int32 ActiveWidgetIndex)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "HandleWidgetStackChanged");

	Params::FrontEnd_C_HandleWidgetStackChanged Parms{};

	Parms.Widget = Widget;
	Parms.ActiveWidgetIndex = ActiveWidgetIndex;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.GetActiveTab
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent, BlueprintPure)
// Parameters:
// class FName                             ActiveTab                                              (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::GetActiveTab(class FName* ActiveTab)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "GetActiveTab");

	Params::FrontEnd_C_GetActiveTab Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (ActiveTab != nullptr)
		*ActiveTab = Parms.ActiveTab;
}


// Function FrontEnd.FrontEnd_C.InitForSubGame
// (Public, BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::InitForSubGame()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "InitForSubGame");

	UObject::ProcessEvent(Func, nullptr);
}


// Function FrontEnd.FrontEnd_C.SetChatWidgetVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Visible                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::SetChatWidgetVisibility(bool Visible)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "SetChatWidgetVisibility");

	Params::FrontEnd_C_SetChatWidgetVisibility Parms{};

	Parms.Visible = Visible;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.UpdateVisibilityState
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    HideHeader                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    HideFooter                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)
// bool                                    HideChat                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::UpdateVisibilityState(bool HideHeader, bool HideFooter, bool HideChat)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "UpdateVisibilityState");

	Params::FrontEnd_C_UpdateVisibilityState Parms{};

	Parms.HideHeader = HideHeader;
	Parms.HideFooter = HideFooter;
	Parms.HideChat = HideChat;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.NeedsToPlayEventMovie
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Param_NeedsToPlayEventMovie                            (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::NeedsToPlayEventMovie(bool* Param_NeedsToPlayEventMovie)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "NeedsToPlayEventMovie");

	Params::FrontEnd_C_NeedsToPlayEventMovie Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (Param_NeedsToPlayEventMovie != nullptr)
		*Param_NeedsToPlayEventMovie = Parms.Param_NeedsToPlayEventMovie;
}


// Function FrontEnd.FrontEnd_C.PlayEventMovieIfNecessary
// (Public, HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    PlayingEventMovie                                      (Parm, OutParm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::PlayEventMovieIfNecessary(bool* PlayingEventMovie)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "PlayEventMovieIfNecessary");

	Params::FrontEnd_C_PlayEventMovieIfNecessary Parms{};

	UObject::ProcessEvent(Func, &Parms);

	if (PlayingEventMovie != nullptr)
		*PlayingEventMovie = Parms.PlayingEventMovie;
}


// Function FrontEnd.FrontEnd_C.SetOverlayTitleBarVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    Visible                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UFrontEnd_C::SetOverlayTitleBarVisibility(bool Visible)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "SetOverlayTitleBarVisibility");

	Params::FrontEnd_C_SetOverlayTitleBarVisibility Parms{};

	Parms.Visible = Visible;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.UpdatePttVisibility
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// EPTTState                               PTTState                                               (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UFrontEnd_C::UpdatePttVisibility(EPTTState PTTState)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "UpdatePttVisibility");

	Params::FrontEnd_C_UpdatePttVisibility Parms{};

	Parms.PTTState = PTTState;

	UObject::ProcessEvent(Func, &Parms);
}


// Function FrontEnd.FrontEnd_C.InitChatVisibilityButton
// (Public, BlueprintCallable, BlueprintEvent)

void UFrontEnd_C::InitChatVisibilityButton()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("FrontEnd_C", "InitChatVisibilityButton");

	UObject::ProcessEvent(Func, nullptr);
}

}

