#include "palindrome.h"

bool IsPalindrome(const std::string& str) {
    if (str.empty()) {
        return true;
    }
    bool answer = true;
    size_t l = 0;
    size_t r = str.size() - 1;
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
        if (r > 0) {
            r--;
        }
    }
    return answer;
}
