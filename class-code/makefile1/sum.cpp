#include "sum.hpp"

int sum(int start, int end) {
    int i;
    int sum = 0;

    for (i = start; i <= end; i++) {
        sum += i;
    }


    return sum;
}
