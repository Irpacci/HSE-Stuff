#include "password.h"
#include <cstdint>

constexpr size_t LOWER = 8;
constexpr size_t GREATER = 14;
constexpr char LA = '!';
constexpr char RA = '~';

bool ValidatePassword(const std::string& password) {
    bool has_alpha = 0;
    bool has_clpha = 0;
    bool has_digit = 0;
    bool has_extra = 0;
    if (password.size() < LOWER || password.size() > GREATER) {
        return false;
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
        if (character < LA || character > RA) {
            return false;
        }
    }
    return (has_clpha + has_alpha + has_digit + has_extra > 2);
}