#include "provinces.h"

int64_t CountPassports(const std::vector<int>& provinces) {
    int64_t answer = 0;
    std::multiset<int64_t> setOfAll;
    for (int x: provinces) {
        setOfAll.insert(x);
    }
    while (setOfAll.size() > 1) {
        int64_t a = *setOfAll.begin();
        setOfAll.erase(setOfAll.find(a));
        int64_t b = *setOfAll.begin();
        setOfAll.erase(setOfAll.find(b));
        answer += a + b;
        setOfAll.insert(a + b);
    }
    return answer;
}
