#include <iostream>

using namespace std;

extern "C" void test1C();
extern "C" void test2C();
extern "C" void test1Cpp();
extern "C" void test2Cpp();

int main()
{
    cout << "Begin C only tests:";
    test1C();
    cout << "\n\nBegin C++ only tests:";
    test1Cpp();
    cout << "\n\nBegin C++ local event, C action tests:";
    test1C();
    cout << "\n\nBegin C local event C++ action tests:";
    test2Cpp();
    cout << "\n\nBegin C++ event C action tests:";
    cout << "\n\nBegin C++ local event remote action tests:";
    cout << "\nEnd Tests:" << endl;
    return 0;
}
