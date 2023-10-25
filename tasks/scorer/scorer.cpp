#include <cstdint>
#include <algorithm>

#include "scorer.h"

ScoreTable GetScoredStudents(const Events& events, time_t score_time) {
    ScoreTable answer;
    std::vector<std::pair<time_t, size_t>> events_order;
    size_t number_of_events = events.size();
    for (size_t i = 0; i < number_of_events; i++) {
        events_order.emplace_back(events[i].time, i);
    }
    std::map<std::string, std::map<std::string, std::pair<bool, bool>>> tasks; //if last commit is success/if no open merges
    sort(events_order.begin(), events_order.end());
    for (std::pair<time_t, size_t> event : events_order) {
        const Event& current_event = events[event.second];
        if (current_event.time > score_time) {
            break;
        }
        switch (current_event.event_type) {
            case EventType::CheckFailed:
                tasks[current_event.student_name][current_event.task_name].first = 0;
                break;
            case EventType::CheckSuccess:
                tasks[current_event.student_name][current_event.task_name].first = 1;
                break;
            case EventType::MergeRequestOpen:
                tasks[current_event.student_name][current_event.task_name].second = 1;
                break;
            case EventType::MergeRequestClosed:
                tasks[current_event.student_name][current_event.task_name].second = 0;
        }
    }
    for (auto tasks_pair : tasks) {
        for (auto task_info : tasks_pair.second) {
            if (task_info.second.first && !task_info.second.second) {
                answer[tasks_pair.first].insert(task_info.first);
            } 
        }
    }
    return answer;
}
