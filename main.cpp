#include <iostream>

using namespace std;

extern "C" void test1C();
extern "C" void test2C();
extern "C" void test1Cpp();
extern "C" void test2Cpp();
extern "C" void* oa();
extern "C" void change();
extern "C" {
int events, fails;
}

int main() {
  fails = 0;
  events = 0;

  test1C();
  test1Cpp();
  test2C();
  test2Cpp();

  change();
  test2Cpp();
  test1Cpp();
  test1C();
  test2C();

  cout << "\n\nBegin C++ local event C++ remote action tests:";
  cout << "\n\nBegin C++ remote event C++ local action tests:";
  cout << "\nEnd Tests:";
  if (fails)
    cout << " Fails -------> " << fails << " for " << events << endl;
  else
    cout << " All Passed ++++++++> " << events << endl;
  return 0;
}
