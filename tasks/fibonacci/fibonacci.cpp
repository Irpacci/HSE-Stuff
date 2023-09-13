#include "fibonacci.h"

int64_t CalculateNthFibonacci(int64_t n) {
    if (n == 0){
        return 0;
    }
    if (n < 3){
        return 1;
    }
    int64_t a = 1;
    int64_t b = 1;
    int64_t c = 1;
    while (n > 2){
        a = b;
        b = c;
        c = a + b;
        n--;
    }
    return c;
}
