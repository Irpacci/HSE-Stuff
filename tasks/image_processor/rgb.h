#ifndef RGB_H
#define RGB_H

#include <algorithm>
#include <cstdint>

class RGB {
public:
    RGB(uint8_t r, uint8_t g, uint8_t b);
    RGB(){};
    ~RGB(){};

public:
    uint8_t b;
    uint8_t g;
    uint8_t r;
} __attribute__((packed));

RGB operator-(const RGB& lhs, const RGB& rhs);

RGB operator+(const RGB& lhs, const RGB& rhs);

RGB operator*(const int32_t& lhs, const RGB& rhs);

#endif  // RGB_H