#include "password.h"

#include <cstdint>

constexpr size_t LOWER = 8;
constexpr size_t GREATER = 14;
constexpr char LA = '!';
constexpr char RA = '~';
constexpr int MinimumClasses = 3;

bool ValidatePassword(const std::string& password) {
    bool has_alpha = false;
    bool has_clpha = false;
    bool has_digit = false;
    bool has_extra = false;
    if (password.size() < LOWER || password.size() > GREATER) {
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
        if (character < LA || character > RA) {
            return false;
        }
    }
    return (has_clpha + has_alpha + has_digit + has_extra >= MinimumClasses);
}