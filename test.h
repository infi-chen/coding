#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <assert.h>


//the following are UBUNTU/LINUX ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

#define PRINT(fmt, args...) printf(RESET"test: "fmt, ##args)
#define PERROR(fmt, args...) printf(BOLDRED"test: "fmt, ##args)
#define DBG(x) PRINT(#x" = %d\n", x)
#define XDBG(x) PRINT(#x" = %x\n", x)

class TestCase
{
public:
    TestCase(const char* case_name) : testcase_name(case_name){}

    // 执行测试案例的方法
    virtual void Run() = 0;

    int nTestResult; // 测试案例的执行结果
    const char* testcase_name; // 测试案例名称
};

class UnitTest
{
public:
    // 获取单例
    static UnitTest* GetInstance();

    // 注册测试案例
    TestCase* RegisterTestCase(TestCase* testcase);

    // 执行单元测试
    int Run();

    TestCase* CurrentTestCase; // 记录当前执行的测试案例
    int nTestResult; // 总的执行结果
    int nPassed; // 通过案例数
    int nFailed; // 失败案例数
protected:
    std::vector<TestCase*> testcases_; // 案例集合
};

#define TESTCASE_NAME(testcase_name) \
    testcase_name##_TEST

#define UTEST(testcase_name) \
class TESTCASE_NAME(testcase_name) : public TestCase \
{ \
public: \
    TESTCASE_NAME(testcase_name)(const char* case_name) : TestCase(case_name){}; \
    virtual void Run(); \
private: \
    static TestCase* const testcase_; \
}; \
\
TestCase* const TESTCASE_NAME(testcase_name) \
    ::testcase_ = UnitTest::GetInstance()->RegisterTestCase( \
        new TESTCASE_NAME(testcase_name)(#testcase_name)); \
void TESTCASE_NAME(testcase_name)::Run()


#define RUN_ALL_TESTS() \
    UnitTest::GetInstance()->Run();


static inline void test_eq(int expect, int result)
{
    if (expect != result) {
        UnitTest::GetInstance()->CurrentTestCase->nTestResult = false;
        std::cout << RED << "Failed!" << std::endl;
        std::cout << RED << "Expect:" << expect << std::endl;
        std::cout << RED << "Actual:" << result << std::endl;
    }
    else {
        UnitTest::GetInstance()->CurrentTestCase->nTestResult = true;
        std::cout << GREEN << "Pass!" << std::endl;
    }
}

#endif // TEST_H
