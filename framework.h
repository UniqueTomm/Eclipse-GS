#pragma once

#include <windows.h>
#include <algorithm>
#include <functional>
#include <thread>
#include <format>
#include <cstdio>
#include <intrin.h>
#include <map>
#include <random>
#include <vector>
#include <type_traits>
#include <d3d11.h>
#include <dxgi.h>
#include <chrono>
#include <future>
#include <string>
#include <numeric>
#include <sstream>

#include "MinHook/include/MinHook.h"
#include "kiero/kiero.h"
#include "imgui/imgui.h"
#include "imgui/imgui_impl_win32.h"
#include "imgui/imgui_impl_dx11.h"

#include "SDK.hpp"
#include "SDK/Engine_Parameters.hpp"
#include "SDK/FortniteGame_Parameters.hpp"

typedef HRESULT(__stdcall* Present) (IDXGISwapChain* pSwapChain, UINT SyncInterval, UINT Flags);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
typedef uintptr_t PTR;

extern LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

using namespace std;
using namespace SDK;

#include "Offsets.h"
#include "Memory.h"
#include "Color.hpp"
#include "Async.h"
#include "HookingManager.h"

#include "OutputDevice.h"
#include "Frame.h"

#define LogInfo(...) { cout << hue::white << "[" << hue::green << "Info" << hue::white << "]" <<  ": " << format(__VA_ARGS__) << endl; }
#define LogError(...) { cout << hue::white << "[" << hue::light_red << "Error" << hue::white << "]" <<  ": " << format(__VA_ARGS__) << endl; }
#define LogWarning(...) { cout << hue::white << "[" << hue::light_yellow << "Warning" << hue::white << "]" <<  ": " << format(__VA_ARGS__) << endl; }

std::string WStringToString(const std::wstring& wstr) {
    if (wstr.empty()) return {};
    int sizeNeeded = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, nullptr, 0, nullptr, nullptr);
    std::string str(sizeNeeded - 1, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], sizeNeeded, nullptr, nullptr);
    return str;
}

#include "Globals.h"

#include "Spawner.h"
#include "GameHelper.h"

#include "PlaylistManager.h"
#include "LootManagerNew.h"
#include "SpectatingManager.h"

#include "QuestHandler.h"

#include "Server.h"
#include "Abilities.h"
#include "Inventory.h"

#include "Overlay.h"