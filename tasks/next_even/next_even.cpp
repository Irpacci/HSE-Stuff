#include "next_even.h"

int64_t NextEven(int64_t n) {
    n /= 2;
    n++;
    n *= 2;
    return n;
}
