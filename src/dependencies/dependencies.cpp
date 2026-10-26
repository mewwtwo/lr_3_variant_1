// Dmytro Demchuk K-25

#include "dependencies/dependencies.hpp"

#include <latch>

#include "action/action.hpp"

namespace {

std::latch set_a_finished{6};
std::latch set_b_finished{5};
std::latch set_e_finished{8};
std::latch set_g_finished{4};
std::latch set_h_finished{5};
std::latch set_i_finished{6};
std::latch set_k_finished{4};
std::latch set_c_finished{8};
std::latch set_d_finished{5};

}

void execute_action(char set_name, int action_number) {
    switch (set_name) {
        case 'a':
            perform_action(set_name, action_number);
            set_a_finished.count_down();
            break;
        case 'b':
            perform_action(set_name, action_number);
            set_b_finished.count_down();
            break;
        case 'e':
            set_a_finished.wait();
            perform_action(set_name, action_number);
            set_e_finished.count_down();
            break;
        case 'g':
            set_a_finished.wait();
            perform_action(set_name, action_number);
            set_g_finished.count_down();
            break;
        case 'h':
            set_b_finished.wait();
            perform_action(set_name, action_number);
            set_h_finished.count_down();
            break;
        case 'i':
            set_b_finished.wait();
            perform_action(set_name, action_number);
            set_i_finished.count_down();
            break;
        case 'k':
            set_e_finished.wait();
            perform_action(set_name, action_number);
            set_k_finished.count_down();
            break;
        case 'c':
            set_g_finished.wait();
            set_h_finished.wait();
            perform_action(set_name, action_number);
            set_c_finished.count_down();
            break;
        case 'd':
            set_i_finished.wait();
            perform_action(set_name, action_number);
            set_d_finished.count_down();
            break;
        case 'f':
            set_k_finished.wait();
            set_c_finished.wait();
            set_d_finished.wait();
            perform_action(set_name, action_number);
            break;
    }
}
