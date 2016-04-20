#include "test.h"
#include <string.h>

long change(long a) {
    int base = 10;
    int mod;
    long ret = 0;
    PRINT("a = %ld\n", a);

    while(a > 0) {
        mod = a % base;
        a = a / base;
        ret = ret * base + mod;
    }
    PRINT("change: %ld\n", ret);
    return ret;
}

int revert(const char string[]) {
    char *result;
    int i;
    int len = strlen(string);
    //result = (char *)malloc(len+1);
    result = strdup(string);
    PRINT("string : %s %d\n", string, len);
    for(i=0;i< len;i++){
        result[i] = string[len-i-1];
    }
    result[len] = '\0';
    PRINT("result : %s %d\n", result, len);
    free(result);
    return 0;
}

int main(int argc, char *argv[])
{
    const char *s="12345678";
    FILE *f;
    f = fopen("/tmp/tmp.txt", "r");
    assert(f);
    change(0x12345678);
    fclose(f);
    perror("done");
    revert(s);
    fflush(stderr);
    return 0;
}

