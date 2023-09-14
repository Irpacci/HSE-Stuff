#include "password.h"
#include <cstdint>

const int64_t LOWER = 8;
const int64_t GREATER = 14;
const int64_t L_ASCII = 33;
const int64_t R_ASCII = 126;

bool ValidatePassword(const std::string& password) {
    bool checked_size = false;
    bool checked_codes = true;
    bool checked_classes = false;
    int64_t has_alpha = 0;
    int64_t has_clpha = 0;
    int64_t has_digit = 0;
    int64_t has_extra = 0;
    if (password.size() >= LOWER && password.size() <= GREATER) {
        checked_size = true;
    }
    for (auto character : password) {
        if (character >= 'A' && character <= 'Z') {
            has_clpha = 1;
        } else if (character >= 'a' && character <= 'z') {
            has_alpha = 1;
        } else if (character >= '0' && character <= '9') {
            has_digit = 1;
        } else {
            has_extra = 1;
        }
        if (static_cast<int64_t>(character) < L_ASCII || static_cast<int64_t>(character) > R_ASCII) {
            checked_codes = false;
        }
    }
    int64_t sum = has_clpha + has_alpha + has_digit + has_extra;
    if (sum > 2) {
        checked_classes = true;
    }
    return (checked_classes & checked_codes & checked_size);
}
