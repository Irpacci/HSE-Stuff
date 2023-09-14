#include "palindrome.h"
#include <cstdint>

bool IsPalindrome(const std::string& str) {
    bool answer = true;
    int64_t l = 0;
    int64_t r = str.size() - 1;
    while (l < r) {
        while (l < str.size() && str[l] == ' ') {
            l++;
        }
        while (r > 0 && str[r] == ' ') {
            r--;
        }
        if (l < r && str[l] != str[r]) {
            answer = false;
        }
        l++;
        r--;
    }
    return answer;
}
