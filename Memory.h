#pragma once
#include "framework.h"

namespace Memory
{
	uintptr_t GetBaseAddress()
	{
		return (uintptr_t)GetModuleHandle(0);
	}

	uintptr_t GetAddress(uintptr_t iOffset)
	{
		return GetBaseAddress() + iOffset;
	}

    uintptr_t GetOffset(uintptr_t Address)
    {
        return Address - GetBaseAddress();
    }

    static __forceinline uintptr_t FindPattern(const char* signature, bool bRelative = false, uint32_t offset = 0)
    {
        uintptr_t base_address = reinterpret_cast<uintptr_t>(GetModuleHandle(NULL));
        static auto patternToByte = [](const char* pattern)
            {
                auto bytes = std::vector<int>{};
                const auto start = const_cast<char*>(pattern);
                const auto end = const_cast<char*>(pattern) + strlen(pattern);

                for (auto current = start; current < end; ++current)
                {
                    if (*current == '?')
                    {
                        ++current;
                        if (*current == '?')
                            ++current;
                        bytes.push_back(-1);
                    }
                    else
                    {
                        bytes.push_back(strtoul(current, &current, 16));
                    }
                }
                return bytes;
            };

        const auto dosHeader = (PIMAGE_DOS_HEADER)base_address;
        const auto ntHeaders = (PIMAGE_NT_HEADERS)((std::uint8_t*)base_address + dosHeader->e_lfanew);

        const auto sizeOfImage = ntHeaders->OptionalHeader.SizeOfImage;
        auto patternBytes = patternToByte(signature);
        const auto scanBytes = reinterpret_cast<std::uint8_t*>(base_address);

        const auto s = patternBytes.size();
        const auto d = patternBytes.data();

        for (auto i = 0ul; i < sizeOfImage - s; ++i)
        {
            bool found = true;
            for (auto j = 0ul; j < s; ++j)
            {
                if (scanBytes[i + j] != d[j] && d[j] != -1)
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                uintptr_t address = reinterpret_cast<uintptr_t>(&scanBytes[i]);
                if (bRelative)
                {
                    address = ((address + offset + 4) + *(int32_t*)(address + offset));
                    return address;
                }
                return address;
            }
        }
        return NULL;
    }

    static bool IsBadReadPtr(void* p)
    {
        MEMORY_BASIC_INFORMATION mbi = { 0 };
        if (::VirtualQuery(p, &mbi, sizeof(mbi)))
        {
            DWORD mask = (PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ | PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY);
            bool b = !(mbi.Protect & mask);
            // check the page is not a guard page
            if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) b = true;

            return b;
        }
        return true;
    }

    void replaceAll(std::string& str, const std::string& from, const std::string& to) {
        if (from.empty())
            return;
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
        }
    }
}

