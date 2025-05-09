#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_SmasherMelee

#include "Basic.hpp"

#include "GAB_SmasherMelee_classes.hpp"
#include "GAB_SmasherMelee_parameters.hpp"


namespace SDK
{

// Function GAB_SmasherMelee.GAB_SmasherMelee_C.ExecuteUbergraph_GAB_SmasherMelee
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGAB_SmasherMelee_C::ExecuteUbergraph_GAB_SmasherMelee(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "ExecuteUbergraph_GAB_SmasherMelee");

	Params::GAB_SmasherMelee_C_ExecuteUbergraph_GAB_SmasherMelee Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.K2_OnEndAbility
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bWasCancelled                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UGAB_SmasherMelee_C::K2_OnEndAbility(bool bWasCancelled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "K2_OnEndAbility");

	Params::GAB_SmasherMelee_C_K2_OnEndAbility Parms{};

	Parms.bWasCancelled = bWasCancelled;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.MoveToLoop
// (BlueprintCallable, BlueprintEvent)

void UGAB_SmasherMelee_C::MoveToLoop()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "MoveToLoop");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.K2_ActivateAbility
// (Event, Protected, BlueprintEvent)

void UGAB_SmasherMelee_C::K2_ActivateAbility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "K2_ActivateAbility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.OnComplete_6E0FFA2F4367D5F26D5F5CB20E78DEFC
// (BlueprintCallable, BlueprintEvent)

void UGAB_SmasherMelee_C::OnComplete_6E0FFA2F4367D5F26D5F5CB20E78DEFC()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "OnComplete_6E0FFA2F4367D5F26D5F5CB20E78DEFC");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.OnInterrupted_6E0FFA2F4367D5F26D5F5CB20E78DEFC
// (BlueprintCallable, BlueprintEvent)

void UGAB_SmasherMelee_C::OnInterrupted_6E0FFA2F4367D5F26D5F5CB20E78DEFC()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "OnInterrupted_6E0FFA2F4367D5F26D5F5CB20E78DEFC");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.OnCancelled_6E0FFA2F4367D5F26D5F5CB20E78DEFC
// (BlueprintCallable, BlueprintEvent)

void UGAB_SmasherMelee_C::OnCancelled_6E0FFA2F4367D5F26D5F5CB20E78DEFC()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "OnCancelled_6E0FFA2F4367D5F26D5F5CB20E78DEFC");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.OnRequestFailed_6E0FFA2F4367D5F26D5F5CB20E78DEFC
// (BlueprintCallable, BlueprintEvent)

void UGAB_SmasherMelee_C::OnRequestFailed_6E0FFA2F4367D5F26D5F5CB20E78DEFC()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "OnRequestFailed_6E0FFA2F4367D5F26D5F5CB20E78DEFC");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.OnMoveFinished_6E0FFA2F4367D5F26D5F5CB20E78DEFC
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// EPathFollowingResult                    Result                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AAIController*                    AIController                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGAB_SmasherMelee_C::OnMoveFinished_6E0FFA2F4367D5F26D5F5CB20E78DEFC(EPathFollowingResult Result, class AAIController* AIController)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "OnMoveFinished_6E0FFA2F4367D5F26D5F5CB20E78DEFC");

	Params::GAB_SmasherMelee_C_OnMoveFinished_6E0FFA2F4367D5F26D5F5CB20E78DEFC Parms{};

	Parms.Result = Result;
	Parms.AIController = AIController;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.Cancelled_D4EB604A4AFDAD65E3461A86287A3EFE
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGameplayAbilityTargetDataHandle TargetData                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FGameplayTag                     ApplicationTag                                         (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)

void UGAB_SmasherMelee_C::Cancelled_D4EB604A4AFDAD65E3461A86287A3EFE(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "Cancelled_D4EB604A4AFDAD65E3461A86287A3EFE");

	Params::GAB_SmasherMelee_C_Cancelled_D4EB604A4AFDAD65E3461A86287A3EFE Parms{};

	Parms.TargetData = std::move(TargetData);
	Parms.ApplicationTag = std::move(ApplicationTag);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.Completed_D4EB604A4AFDAD65E3461A86287A3EFE
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGameplayAbilityTargetDataHandle TargetData                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FGameplayTag                     ApplicationTag                                         (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)

void UGAB_SmasherMelee_C::Completed_D4EB604A4AFDAD65E3461A86287A3EFE(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "Completed_D4EB604A4AFDAD65E3461A86287A3EFE");

	Params::GAB_SmasherMelee_C_Completed_D4EB604A4AFDAD65E3461A86287A3EFE Parms{};

	Parms.TargetData = std::move(TargetData);
	Parms.ApplicationTag = std::move(ApplicationTag);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_SmasherMelee.GAB_SmasherMelee_C.Triggered_D4EB604A4AFDAD65E3461A86287A3EFE
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGameplayAbilityTargetDataHandle TargetData                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FGameplayTag                     ApplicationTag                                         (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)

void UGAB_SmasherMelee_C::Triggered_D4EB604A4AFDAD65E3461A86287A3EFE(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_SmasherMelee_C", "Triggered_D4EB604A4AFDAD65E3461A86287A3EFE");

	Params::GAB_SmasherMelee_C_Triggered_D4EB604A4AFDAD65E3461A86287A3EFE Parms{};

	Parms.TargetData = std::move(TargetData);
	Parms.ApplicationTag = std::move(ApplicationTag);

	UObject::ProcessEvent(Func, &Parms);
}

}

