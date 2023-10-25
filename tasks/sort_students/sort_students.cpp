#include <algorithm>
#include <cstdint>

#include "sort_students.h"

int32_t DAYS_IN_MONTH = 31;
int32_t DAYS_IN_YEAR = 365;

bool isLess(Student a, Student b, SortKind sortKind) {
    std::pair<std::string, std::string> a_name = {a.last_name, a.name};
    std::pair<std::string, std::string> b_name = {b.last_name, b.name};
    time_t a_date = a.birth_date.day + a.birth_date.month * DAYS_IN_MONTH + a.birth_date.year * DAYS_IN_YEAR;
    time_t b_date = b.birth_date.day + b.birth_date.month * DAYS_IN_MONTH + b.birth_date.year * DAYS_IN_YEAR;
    if (sortKind == SortKind::Name) {
        return std::make_pair(a_name, a_date) < std::make_pair(b_name, b_date);
    } else {
        return std::make_pair(a_date, a_name) < std::make_pair(b_date, b_name);
    }
}

void SortStudents(std::vector<Student>& students, SortKind sortKind) {
    size_t number_of_students = students.size();
    for (size_t i = 0; i < number_of_students; i++) {
        for (size_t j = 0; j < number_of_students - 1; j++) {
            if (isLess(students[j + 1], students[j], sortKind)) {
                std::swap(students[j], students[j + 1]);
            }
        }
    }
}
