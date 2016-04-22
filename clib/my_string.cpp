#include "../test.h"
#include "my_string.h"

int tt(int count) {
    while (--count) {
        PRINT("hello world %d\n", count);
    }
    return 0;
}

UTEST(tt_demo) {
    test_eq(0, tt(10));
}
