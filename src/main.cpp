// Dmytro Demchuk K-25

#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>
#include <vector>

#include "plan/plan.hpp"

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
        threads.reserve(nt);
        for (int t = 0; t < nt; ++t) {
            threads.emplace_back(worker, t);
        }
    }

    std::chrono::duration<double> elapsed = std::chrono::steady_clock::now() - start;
    std::osyncstream(std::cout) << "Обчислення завершено. Тривалість обчислення "
                                << elapsed.count() << " секунд.\n";
}
