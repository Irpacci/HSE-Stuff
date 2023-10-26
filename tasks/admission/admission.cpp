#include <algorithm>
#include <cstdint>
#include <tuple>
#include <utility>
#include <map>
#include "admission.h"

int32_t DAYS_IN_MONTH = 30;
int32_t DAYS_IN_YEAR = 365;

int32_t BruteConvertion(const Date& date) {
    return date.day + date.month * DAYS_IN_MONTH + date.year * DAYS_IN_YEAR;
} 

bool operator<(const Date& lhs, const Date& rhs) {
    return BruteConvertion(lhs) < BruteConvertion(rhs);
}

bool ApplicantsComparatorSort(std::pair<Applicant, size_t> &a, std::pair<Applicant, size_t> &b) {
    std::tuple<int32_t, int32_t, std::string> a_data = {-(a.first.points), BruteConvertion(a.first.student.birth_date), a.first.student.name};
    std::tuple<int32_t, int32_t, std::string> b_data = {-(b.first.points), BruteConvertion(b.first.student.birth_date), b.first.student.name};
    return a_data < b_data;
}

bool ApplicantsComparatorAnswer(const Student *a, const Student *b) {
    std::pair<std::string, int> a_data = {a->name, BruteConvertion(a->birth_date)};
    std::pair<std::string, int> b_data = {b->name, BruteConvertion(b->birth_date)};
    return a_data < b_data;
}

AdmissionTable FillUniversities(const std::vector<University>& universities, const std::vector<Applicant>& applicants) {
    AdmissionTable answer;
    size_t number_of_students = applicants.size();
    std::map<std::string, size_t> max_size;
    for (auto university : universities) {
        max_size[university.name] = university.max_students;
    }
    std::vector<std::pair<Applicant, size_t>> applicants_sorted;
    for (size_t i = 0; i < number_of_students; i++) {
        applicants_sorted.emplace_back(applicants[i], i);
    }
    std::sort(applicants_sorted.begin(), applicants_sorted.end(), ApplicantsComparatorSort);
    for (auto applicant : applicants_sorted) {
        for (auto wanted_university : applicant.first.wish_list) {
            if (answer[wanted_university].size() < max_size[wanted_university]) {
                answer[wanted_university].push_back(&applicants[applicant.second].student);
                break;
            }
        }
    }
    for (auto university : answer) {
        std::sort(university.second.begin(), university.second.end(), ApplicantsComparatorAnswer);
    }
    return answer;
}
