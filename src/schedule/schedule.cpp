// Dmytro Demchuk K-25

#include "schedule/schedule.hpp"

#include <vector>

#include "dependencies/dependencies.hpp"

namespace {

struct ScheduledAction {
    char set_name;
    int action_number;
};

const std::vector<ScheduledAction> thread_schedules[thread_count] = {
    {{'b', 1}, {'a', 1}, {'a', 6}, {'e', 1}, {'e', 4}, {'k', 1}, {'h', 2},
     {'g', 2}, {'c', 1}, {'c', 3}, {'c', 8}, {'f', 1}, {'f', 6}},
    {{'b', 2}, {'a', 2}, {'i', 1}, {'e', 2}, {'e', 5}, {'k', 2}, {'h', 3},
     {'g', 3}, {'c', 2}, {'c', 4}, {'f', 2}, {'f', 7}},
    {{'b', 3}, {'a', 3}, {'i', 2}, {'e', 3}, {'e', 6}, {'k', 3}, {'h', 4},
     {'g', 4}, {'d', 3}, {'c', 5}, {'f', 3}, {'f', 8}},
    {{'b', 4}, {'a', 4}, {'i', 3}, {'i', 5}, {'e', 7}, {'k', 4}, {'h', 5},
     {'d', 1}, {'d', 4}, {'c', 6}, {'f', 4}, {'f', 9}},
    {{'b', 5}, {'a', 5}, {'i', 4}, {'i', 6}, {'e', 8}, {'h', 1}, {'g', 1},
     {'d', 2}, {'d', 5}, {'c', 7}, {'f', 5}},
};

}  // namespace

void run_thread_schedule(int thread_index) {
    for (const ScheduledAction& action : thread_schedules[thread_index]) {
        execute_action(action.set_name, action.action_number);
    }
}
