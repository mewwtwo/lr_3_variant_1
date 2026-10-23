// Dmytro Demchuk K-25

#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>
#include <vector>

#include "schedule/schedule.hpp"

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#endif

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
#endif

    std::osyncstream(std::cout) << "Обчислення розпочато.\n";
    auto start = std::chrono::steady_clock::now();

    {
        std::vector<std::jthread> threads;
        threads.reserve(thread_count);
        for (int thread_index = 0; thread_index < thread_count; ++thread_index) {
            threads.emplace_back(run_thread_schedule, thread_index);
        }
    }

    std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - start;
    std::osyncstream(std::cout) << "Обчислення завершено. Тривалість обчислення "
                                << elapsed.count() << " секунд.\n";
}
