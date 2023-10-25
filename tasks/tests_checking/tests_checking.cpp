#include <deque>

#include "tests_checking.h"

std::vector<std::string> StudentsOrder(const std::vector<StudentAction>& student_actions,
                                       const std::vector<size_t>& queries) {
    std::vector<std::string> answer;
    std::deque<std::string> listofall;
    for (auto action : student_actions) {
        if (action.side == Side::Top) {
            listofall.push_front(action.name);
        } else {
            listofall.push_back(action.name);
        }
    }
    std::vector<std::string> ordered;
    while (!listofall.empty()) {
        ordered.push_back(listofall.front());
        listofall.pop_front();
    }
    for (size_t index : queries) {
        answer.push_back(ordered[index - 1]);
    }
    return answer;
}
