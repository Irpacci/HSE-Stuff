#include "is_leap.h"

const int F1 = 4;
const int F2 = 100;
const int F3 = 400;

bool IsLeap(int year) {

    if ((year % F1 == 0 && year % F2 != 0) || year % F3 == 0) {
        return true;
    }
    return false;
}
