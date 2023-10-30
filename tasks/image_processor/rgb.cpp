#include "rgb.h"

const int32_t MAX_INT8 = 255;

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
    tmp.r = lhs.r > MAX_INT8 - rhs.r ? MAX_INT8 : lhs.r + rhs.r;
    tmp.g = lhs.g > MAX_INT8 - rhs.g ? MAX_INT8 : lhs.g + rhs.g;
    tmp.b = lhs.b > MAX_INT8 - rhs.b ? MAX_INT8 : lhs.b + rhs.b;
    return tmp;
}

RGB operator*(const int32_t& lhs, const RGB& rhs) {
    return RGB(std::min(MAX_INT8, lhs * rhs.r), std::min(MAX_INT8, lhs * rhs.g), std::min(MAX_INT8, lhs * rhs.b));
}
