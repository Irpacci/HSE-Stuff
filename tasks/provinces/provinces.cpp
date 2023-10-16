#include "provinces.h"

int64_t CountPassports(const std::vector<int>& provinces) {
    int64_t answer = 0;
    std::multiset<int64_t> set_of_all;
    for (int x : provinces) {
        set_of_all.insert(x);
    }
    while (set_of_all.size() > 1) {
        int64_t a = *set_of_all.begin();
        set_of_all.erase(set_of_all.find(a));
        int64_t b = *set_of_all.begin();
        set_of_all.erase(set_of_all.find(b));
        answer += a + b;
        set_of_all.insert(a + b);
    }
    return answer;
}
