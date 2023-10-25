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

bool ApplicantsComparatorSort(Applicant &a, Applicant &b) {
    std::tuple<int32_t, int32_t, std::string> a_data = {-(a.points), BruteConvertion(a.student.birth_date), a.student.name};
    std::tuple<int32_t, int32_t, std::string> b_data = {-(b.points), BruteConvertion(b.student.birth_date), b.student.name};
    return a_data < b_data;
}

bool ApplicantsComparatorAnswer(Applicant &a, Applicant &b) {
    std::pair<std::string, int> a_data = {a.student.name, BruteConvertion(a.student.birth_date)};
    std::pair<std::string, int> b_data = {b.student.name, BruteConvertion(b.student.birth_date)};
    return a_data < b_data;
}

AdmissionTable FillUniversities(const std::vector<University>& universities, const std::vector<Applicant>& applicants) {
    AdmissionTable answer;
    std::map<std::string, int> max_size;
    for(auto university: universities) {
        max_size[university.name] = university.max_students;
    }
    std::vector<Applicant*> applicants_sorted;
    for (auto applicant: applicants) {
        applicants_sorted.push_back(applicant);
    }
    sort(applicants_sorted.begin(), applicants_sorted.end(), ApplicantsComparatorSort);
    for (auto applicant: applicants_sorted) {
        for (auto wanted_university: applicant->wish_list) {
            if(answer[wanted_university].size() < max_size[wanted_university]) {
                answer[wanted_university].push_back(applicant->student);
                break;
            }
        }
    }
    return {};
}
