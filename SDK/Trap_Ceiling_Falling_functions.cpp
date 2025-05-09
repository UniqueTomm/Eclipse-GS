#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: Trap_Ceiling_Falling

#include "Basic.hpp"

#include "Trap_Ceiling_Falling_classes.hpp"
#include "Trap_Ceiling_Falling_parameters.hpp"


namespace SDK
{

// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.ExecuteUbergraph_Trap_Ceiling_Falling
// (HasDefaults)
// Parameters:
// int32                                   EntryPoint                                             (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATrap_Ceiling_Falling_C::ExecuteUbergraph_Trap_Ceiling_Falling(int32 EntryPoint)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "ExecuteUbergraph_Trap_Ceiling_Falling");

	Params::Trap_Ceiling_Falling_C_ExecuteUbergraph_Trap_Ceiling_Falling Parms{};

	Parms.EntryPoint = EntryPoint;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.CloseDoors
// (BlueprintCallable, BlueprintEvent)

void ATrap_Ceiling_Falling_C::CloseDoors()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "CloseDoors");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.OpenDoors
// (BlueprintCallable, BlueprintEvent)

void ATrap_Ceiling_Falling_C::OpenDoors()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "OpenDoors");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.FireDustFX
// (BlueprintCallable, BlueprintEvent)

void ATrap_Ceiling_Falling_C::FireDustFX()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "FireDustFX");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.ShowTires
// (BlueprintCallable, BlueprintEvent)

void ATrap_Ceiling_Falling_C::ShowTires()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "ShowTires");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.TrapActivated
// (BlueprintAuthorityOnly, Event, Public, BlueprintEvent)
// Parameters:
// float                                   CooldownDuration                                       (ConstParm, BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor, HasGetValueTypeHash)

void ATrap_Ceiling_Falling_C::TrapActivated(const float CooldownDuration)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "TrapActivated");

	Params::Trap_Ceiling_Falling_C_TrapActivated Parms{};

	Parms.CooldownDuration = CooldownDuration;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.OnPlaced
// (Event, Public, BlueprintEvent)

void ATrap_Ceiling_Falling_C::OnPlaced()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "OnPlaced");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.OpenDoor__UpdateFunc
// (BlueprintEvent)

void ATrap_Ceiling_Falling_C::OpenDoor__UpdateFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "OpenDoor__UpdateFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.OpenDoor__FinishedFunc
// (BlueprintEvent)

void ATrap_Ceiling_Falling_C::OpenDoor__FinishedFunc()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "OpenDoor__FinishedFunc");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.UserConstructionScript
// (Event, Public, HasDefaults, BlueprintCallable, BlueprintEvent)

void ATrap_Ceiling_Falling_C::UserConstructionScript()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "UserConstructionScript");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.ToggleTireVisibility
// (Public, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    NewHidden                                              (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ATrap_Ceiling_Falling_C::ToggleTireVisibility(bool NewHidden)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "ToggleTireVisibility");

	Params::Trap_Ceiling_Falling_C_ToggleTireVisibility Parms{};

	Parms.NewHidden = NewHidden;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.OnRep_bActivated
// (BlueprintCallable, BlueprintEvent)

void ATrap_Ceiling_Falling_C::OnRep_bActivated()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "OnRep_bActivated");

	UObject::ProcessEvent(Func, nullptr);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.ToggleDoors
// (Public, HasDefaults, BlueprintCallable, BlueprintEvent)
// Parameters:
// bool                                    bToggle                                                (BlueprintVisible, BlueprintReadOnly, Parm, ZeroConstructor, IsPlainOldData, NoDestructor)

void ATrap_Ceiling_Falling_C::ToggleDoors(bool bToggle)
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "ToggleDoors");

	Params::Trap_Ceiling_Falling_C_ToggleDoors Parms{};

	Parms.bToggle = bToggle;

	UObject::ProcessEvent(Func, &Parms);
}


// Function Trap_Ceiling_Falling.Trap_Ceiling_Falling_C.ToggleTiresAndFX
// (Public, BlueprintCallable, BlueprintEvent)

void ATrap_Ceiling_Falling_C::ToggleTiresAndFX()
{
	static class UFunction* Func = nullptr;

	if (Func == nullptr)
		Func = Class->GetFunction("Trap_Ceiling_Falling_C", "ToggleTiresAndFX");

	UObject::ProcessEvent(Func, nullptr);
}

}

