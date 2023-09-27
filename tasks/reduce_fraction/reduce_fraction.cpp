#include "reduce_fraction.h"
#include <numeric>

int64_t ReduceFraction(int64_t numerator, int64_t denominator) {
    int64_t g = std::gcd(numerator, denominator);
    return (numerator + denominator) / g;
}
