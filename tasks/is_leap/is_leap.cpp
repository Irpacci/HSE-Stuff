#include "is_leap.h"

const int f1 = 4;
const int f2 = 100;
const int f3 = 400;

bool IsLeap(int year) {

    if ((year % f1 == 0 && year % f2 != 0) || year % f3 == 0) {
        return true;
    }
    return false;
}
