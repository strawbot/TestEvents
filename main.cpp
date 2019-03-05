#include <iostream>

using namespace std;

extern "C" {
// inits
void init_ta();

// tests
void test1C();
void test2C();
void test3C();
void test1Cpp();
void test2Cpp();
void* oa();
void change();
void testCppFunction();

// accounting
extern int events, fails;
int events, fails;
}

int main() {
  fails = 0;
  events = 0;

  // setup
  init_ta();

  // event
  test1C();
  test1Cpp();
  test2C();
  test2Cpp();
  testCppFunction();

  change();
  test2Cpp();
  test1Cpp();
  test1C();
  test2C();

  // time events
  test3C();

//  cout << "\n\nBegin C++ local event C++ function action tests:";
//  cout << "\n\nBegin C++ local event C++ remote action tests:";
//  cout << "\n\nBegin C++ remote event C++ local action tests:";
  cout << "\nEnd Tests:";
  if (fails)
    cout << " Fails -------> " << fails << " for " << events << endl;
  else
    cout << " All Passed ++++++++> " << events << endl;
  return 0;
}

/* Notes:
 *  How do we use TEA interface with C++ functions? Since it is C++
 *  code, it assumes a method is being called.
 *  1. use different macro for methods
 *  2. smarten up the macro to figure out what to do
 *  3. only use methods in C++
 */
