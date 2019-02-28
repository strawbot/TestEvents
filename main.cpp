#include <iostream>

using namespace std;

extern "C" void test1C();
extern "C" void test2C();
extern "C" void test1Cpp();
extern "C" void test2Cpp();
extern "C" {
int events, fails;
}

int main()
{
    fails = 0;
    cout << "Begin C only tests:";
    test1C();
    cout << "\n\nBegin C++ only tests:";
    test1Cpp();
    cout << "\n\nBegin C++ local event, C action tests:";
    test1C();
    cout << "\n\nBegin C local event C++ action tests:";
    test2Cpp();
    cout << "\n\nBegin C++ local event C++ remote action tests:";
    cout << "\n\nBegin C++ remote event C++ local action tests:";
    cout << "\nEnd Tests:";
    if (fails) cout<< " Fails: " << fails << endl;
    else  cout << " All Passed," << endl;
    return 0;
}
