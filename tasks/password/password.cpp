#include "password.h"

#include <cstdint>

constexpr size_t LowerSize = 8;
constexpr size_t GreaterSize = 14;
constexpr char LeftAscii = '!';
constexpr char RightAscii = '~';
constexpr int MinimumClasses = 3;

bool ValidatePassword(const std::string& password) {
    bool has_alpha = false;
    bool has_clpha = false;
    bool has_digit = false;
    bool has_extra = false;
    if (password.size() < LowerSize || password.size() > GreaterSize) {
        return false;
    }
    for (auto character : password) {
        if (character >= 'A' && character <= 'Z') {
            has_clpha = true;
        } else if (character >= 'a' && character <= 'z') {
            has_alpha = true;
        } else if (character >= '0' && character <= '9') {
            has_digit = true;
        } else {
            has_extra = true;
        }
        if (character < LeftAscii || character > RightAscii) {
            return false;
        }
    }
    return (has_clpha + has_alpha + has_digit + has_extra >= MinimumClasses);
}