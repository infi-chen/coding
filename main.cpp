#include "test.h"
#include "clib/my_string.h"
#include <string.h>

long change(long a) {
    int base = 10;
    int mod;
    long ret = 0;
    PRINT("colored: input = %ld\n", a);

    while(a > 0) {
        mod = a % base;
        a = a / base;
        ret = ret * base + mod;
    }
    PRINT("result: %ld\n", ret);
    return ret;
}

UTEST(ChangeTest_PassDemo)
{
    test_eq(4321, change(1234));
    test_eq(87654321, change(12345678));
}

UTEST(ChangeTest_FailDemo)
{
    test_eq(1234, change(1234));
    test_eq(12345678, change(12345678));
}


int test_function() {

    RUN_ALL_TESTS();

    return 0;
}


int main(int argc, char *argv[])
{
    test_function();
    return 0;
}

