#ifndef TEST_H
#define TEST_H

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <assert.h>

#define PRINT(fmt, args...) printf("test: "fmt, ##args)
#define DBG(x) PRINT(#x" = %d\n", x)
#define XDBG(x) PRINT(#x" = %x\n", x)
#endif // TEST_H
