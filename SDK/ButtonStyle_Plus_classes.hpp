#pragma once

/*
* SDK generated by Dumper-7
*
* https://github.com/Encryqed/Dumper-7
*/

// Package: ButtonStyle_Plus

#include "Basic.hpp"

#include "ButtonStyleMinusMediumTransparentNoCues_classes.hpp"


namespace SDK
{

// BlueprintGeneratedClass ButtonStyle_Plus.ButtonStyle_Plus_C
// 0x0000 (0x04F0 - 0x04F0)
class UButtonStyle_Plus_C final : public UButtonStyleMinusMediumTransparentNoCues_C
{
public:
	static class UClass* StaticClass()
	{
		return StaticBPGeneratedClassImpl<"ButtonStyle_Plus_C">();
	}
	static class UButtonStyle_Plus_C* GetDefaultObj()
	{
		return GetDefaultObjImpl<UButtonStyle_Plus_C>();
	}
};
static_assert(alignof(UButtonStyle_Plus_C) == 0x000008, "Wrong alignment on UButtonStyle_Plus_C");
static_assert(sizeof(UButtonStyle_Plus_C) == 0x0004F0, "Wrong size on UButtonStyle_Plus_C");

}

