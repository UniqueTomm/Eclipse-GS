#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: GAB_TakerPortalBase

#include "Basic.hpp"

#include "GAB_TakerPortalBase_classes.hpp"
#include "GAB_TakerPortalBase_parameters.hpp"


namespace SDK
{

// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.ExecuteUbergraph_GAB_TakerPortalBase
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGAB_TakerPortalBase_C::ExecuteUbergraph_GAB_TakerPortalBase(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "ExecuteUbergraph_GAB_TakerPortalBase");

	Params::GAB_TakerPortalBase_C_ExecuteUbergraph_GAB_TakerPortalBase Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.K2_ActivateAbility
// (Event, Protected, BlueprintEvent)

void UGAB_TakerPortalBase_C::K2_ActivateAbility()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "K2_ActivateAbility");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.K2_OnEndAbility
// (Event, Protected, BlueprintEvent)
// Parameters:
// bool                                    bWasCancelled                                          (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void UGAB_TakerPortalBase_C::K2_OnEndAbility(bool bWasCancelled)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "K2_OnEndAbility");

	Params::GAB_TakerPortalBase_C_K2_OnEndAbility Parms{};

	Parms.bWasCancelled = bWasCancelled;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.Triggered_7D4D41B64C4603D73B5B158D82C73287
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGameplayAbilityTargetDataHandle TargetData                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FGameplayTag                     ApplicationTag                                         (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)

void UGAB_TakerPortalBase_C::Triggered_7D4D41B64C4603D73B5B158D82C73287(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "Triggered_7D4D41B64C4603D73B5B158D82C73287");

	Params::GAB_TakerPortalBase_C_Triggered_7D4D41B64C4603D73B5B158D82C73287 Parms{};

	Parms.TargetData = std::move(TargetData);
	Parms.ApplicationTag = std::move(ApplicationTag);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.Cancelled_7D4D41B64C4603D73B5B158D82C73287
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGameplayAbilityTargetDataHandle TargetData                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FGameplayTag                     ApplicationTag                                         (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)

void UGAB_TakerPortalBase_C::Cancelled_7D4D41B64C4603D73B5B158D82C73287(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "Cancelled_7D4D41B64C4603D73B5B158D82C73287");

	Params::GAB_TakerPortalBase_C_Cancelled_7D4D41B64C4603D73B5B158D82C73287 Parms{};

	Parms.TargetData = std::move(TargetData);
	Parms.ApplicationTag = std::move(ApplicationTag);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.Completed_7D4D41B64C4603D73B5B158D82C73287
// (HasOutParams, BlueprintCallable, BlueprintEvent)
// Parameters:
// struct FGameplayAbilityTargetDataHandle TargetData                                             (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, OutParm, ReferenceParm)
// struct FGameplayTag                     ApplicationTag                                         (BlueprintVisible, BlueprintReadOnly, Parm, NoDestructor, HasGetValueTypeHash)

void UGAB_TakerPortalBase_C::Completed_7D4D41B64C4603D73B5B158D82C73287(const struct FGameplayAbilityTargetDataHandle& TargetData, const struct FGameplayTag& ApplicationTag)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "Completed_7D4D41B64C4603D73B5B158D82C73287");

	Params::GAB_TakerPortalBase_C_Completed_7D4D41B64C4603D73B5B158D82C73287 Parms{};

	Parms.TargetData = std::move(TargetData);
	Parms.ApplicationTag = std::move(ApplicationTag);

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnComplete_F402FFCD40B6F77E728220BFF4A37F11
// (BlueprintCallable, BlueprintEvent)

void UGAB_TakerPortalBase_C::OnComplete_F402FFCD40B6F77E728220BFF4A37F11()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnComplete_F402FFCD40B6F77E728220BFF4A37F11");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnInterrupted_F402FFCD40B6F77E728220BFF4A37F11
// (BlueprintCallable, BlueprintEvent)

void UGAB_TakerPortalBase_C::OnInterrupted_F402FFCD40B6F77E728220BFF4A37F11()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnInterrupted_F402FFCD40B6F77E728220BFF4A37F11");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnCancelled_F402FFCD40B6F77E728220BFF4A37F11
// (BlueprintCallable, BlueprintEvent)

void UGAB_TakerPortalBase_C::OnCancelled_F402FFCD40B6F77E728220BFF4A37F11()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnCancelled_F402FFCD40B6F77E728220BFF4A37F11");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnRequestFailed_F402FFCD40B6F77E728220BFF4A37F11
// (BlueprintCallable, BlueprintEvent)

void UGAB_TakerPortalBase_C::OnRequestFailed_F402FFCD40B6F77E728220BFF4A37F11()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnRequestFailed_F402FFCD40B6F77E728220BFF4A37F11");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnMoveFinished_F402FFCD40B6F77E728220BFF4A37F11
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// EPathFollowingResult                    Result                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AAIController*                    AIController                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGAB_TakerPortalBase_C::OnMoveFinished_F402FFCD40B6F77E728220BFF4A37F11(EPathFollowingResult Result, class AAIController* AIController)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnMoveFinished_F402FFCD40B6F77E728220BFF4A37F11");

	Params::GAB_TakerPortalBase_C_OnMoveFinished_F402FFCD40B6F77E728220BFF4A37F11 Parms{};

	Parms.Result = Result;
	Parms.AIController = AIController;

	UObject::ProcessEvent(Func, &Parms);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnComplete_16BAAEB04DC04FA84D2FF3BBFD3A3425
// (BlueprintCallable, BlueprintEvent)

void UGAB_TakerPortalBase_C::OnComplete_16BAAEB04DC04FA84D2FF3BBFD3A3425()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnComplete_16BAAEB04DC04FA84D2FF3BBFD3A3425");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnInterrupted_16BAAEB04DC04FA84D2FF3BBFD3A3425
// (BlueprintCallable, BlueprintEvent)

void UGAB_TakerPortalBase_C::OnInterrupted_16BAAEB04DC04FA84D2FF3BBFD3A3425()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnInterrupted_16BAAEB04DC04FA84D2FF3BBFD3A3425");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnCancelled_16BAAEB04DC04FA84D2FF3BBFD3A3425
// (BlueprintCallable, BlueprintEvent)

void UGAB_TakerPortalBase_C::OnCancelled_16BAAEB04DC04FA84D2FF3BBFD3A3425()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnCancelled_16BAAEB04DC04FA84D2FF3BBFD3A3425");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnRequestFailed_16BAAEB04DC04FA84D2FF3BBFD3A3425
// (BlueprintCallable, BlueprintEvent)

void UGAB_TakerPortalBase_C::OnRequestFailed_16BAAEB04DC04FA84D2FF3BBFD3A3425()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnRequestFailed_16BAAEB04DC04FA84D2FF3BBFD3A3425");

	UObject::ProcessEvent(Func, nullptr);
}


// Function GAB_TakerPortalBase.GAB_TakerPortalBase_C.OnMoveFinished_16BAAEB04DC04FA84D2FF3BBFD3A3425
// (BlueprintCallable, BlueprintEvent)
// Parameters:
// EPathFollowingResult                    Result                                                 (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)
// class AAIController*                    AIController                                           (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void UGAB_TakerPortalBase_C::OnMoveFinished_16BAAEB04DC04FA84D2FF3BBFD3A3425(EPathFollowingResult Result, class AAIController* AIController)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("GAB_TakerPortalBase_C", "OnMoveFinished_16BAAEB04DC04FA84D2FF3BBFD3A3425");

	Params::GAB_TakerPortalBase_C_OnMoveFinished_16BAAEB04DC04FA84D2FF3BBFD3A3425 Parms{};

	Parms.Result = Result;
	Parms.AIController = AIController;

	UObject::ProcessEvent(Func, &Parms);
}

}

