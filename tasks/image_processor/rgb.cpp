#include "rgb.h"

RGB::RGB(uint8_t r, uint8_t g, uint8_t b) : b{b}, g{g}, r{r} {
}

RGB operator-(const RGB& lhs, const RGB& rhs) {
    RGB tmp;
    tmp.r = lhs.r < rhs.r ? 0 : lhs.r - rhs.r;
    tmp.g = lhs.g < rhs.g ? 0 : lhs.g - rhs.g;
    tmp.b = lhs.b < rhs.b ? 0 : lhs.b - rhs.b;
    return tmp;
}

RGB operator+(const RGB& lhs, const RGB& rhs) {
    RGB tmp;
    tmp.r = lhs.r > 255 - rhs.r ? 255 : lhs.r + rhs.r;
    tmp.g = lhs.g > 255 - rhs.g ? 255 : lhs.g + rhs.g;
    tmp.b = lhs.b > 255 - rhs.b ? 255 : lhs.b + rhs.b;
    return tmp;
}

RGB operator*(const int32_t& lhs, const RGB& rhs) {
    return RGB(std::min(256, lhs * rhs.r), std::min(256, lhs * rhs.g), std::min(256, lhs * rhs.b));
}
