#include "testcpp.h"

testcpp object;
extern "C" struct EventQueue_t * cppButton() { return object.button; }
extern "C" void cppPress(int i) { object.press(i); }

extern "C" void test1Cpp() { object.test1Cpp(); }
extern "C" void test2Cpp() { object.test2Cpp(); }
extern "C" void * oa = (void *)&object.action1;
