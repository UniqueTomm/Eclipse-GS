#pragma once
#include "framework.h"

namespace TestHooks
{

	__int64* (*oSendBunch)(UChannel* a1, __int64* a2, __int64 a3, char a4);
	__int64* hkSendBunch(UChannel* a1, __int64* a2, __int64 a3, char a4)
	{
		LogInfo("SendBunch:a1: 0x{:x}", __int64(a1));
		LogInfo("SendBunch:a2: 0x{:x}", __int64(a2));
		LogInfo("SendBunch:a3: 0x{:x}", __int64(a3));
		LogInfo("SendBunch:a4: 0x{:x}", __int64(a4));

		return oSendBunch(a1, a2, a3, a4);
	}

	void Initialize()
	{
		//  HookingManager::CreateHook(Memory::GetAddress(0x212AE70), hkSendBunch, (void**)&oSendBunch);
	}
}