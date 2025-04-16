#pragma once
#include "framework.h"

namespace Async
{
    void runAsync(std::function<void()> task) {
        std::thread([task]() {
            task();
            }).detach();
    }

    void runAsync(int delay, std::function<void()> task) {
        std::thread([delay, task]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(delay));
            task();
            }).detach();
    }
}