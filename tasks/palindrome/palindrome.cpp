#include "palindrome.h"
#include <cstdint>

bool IsPalindrome(const std::string& str) {
    bool answer = true;
    unsigned long l = 0;
    unsigned long r = str.size() - 1;
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
