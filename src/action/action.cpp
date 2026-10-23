// Dmytro Demchuk K-25

#include "action/action.hpp"

#include <chrono>
#include <iostream>
#include <syncstream>
#include <thread>

void perform_action(char set_name, int action_number) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::osyncstream(std::cout) << "З набору " << set_name << " виконано дію " << action_number << ".\n";
}
