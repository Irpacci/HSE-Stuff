#include "password.h"
#include <cstdint>

bool ValidatePassword(const std::string& password) {
    bool checked_size = false;
    bool checked_codes = true;
    bool checked_classes = false;
    int64_t has_alpha = 0;
    int64_t has_Alpha = 0;
    int64_t has_digit = 0;
    int64_t has_extra = 0;
    int64_t lower = 8;
    int64_t greater = 14;
    if (password.size() >= lower && password.size() <= greater) {
        checked_size = true;
    }
    for (auto character: password) {
        if (character >= 'A' && character <= 'Z') {
            has_Alpha = 1;
        } else if (character >= 'a' && character <= 'z') {
            has_alpha = 1;
        } else if (character >= '0' && character <= '9') {
            has_digit = 1;
        } else {
            has_extra = 1;
        }
        int64_t left_ascii = 33;
        int64_t right_ascii = 126;
        if (static_cast<int64_t>(character) < left_ascii || static_cast<int64_t>(character) > right_ascii) {
            checked_codes = false;
        }
    }
    int64_t sum = has_Alpha + has_alpha + has_digit + has_extra;
    if (sum > 2) {
        checked_classes = true;
    }
    return (checked_classes & checked_codes & checked_size);
}
