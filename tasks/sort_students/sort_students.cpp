#include <algorithm>
#include <cstdint>

#include "sort_students.h"

using RightDate = std::pair<int32_t, std::pair<int32_t, int32_t>>;
using RightName = std::pair<std::string, std::string>;

bool isLess(Student a, Student b, SortKind sortKind) {
    RightName a_name = {a.last_name, a.name};
    RightName b_name = {b.last_name, b.name};
    RightDate a_date = {a.birth_date.year, {a.birth_date.month, a.birth_date.day}};
    RightDate b_date = {b.birth_date.year, {b.birth_date.month, b.birth_date.day}};
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
