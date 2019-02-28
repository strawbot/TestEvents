#include "testcpp.h"

testcpp object;
extern "C" struct EventQueue_t * cppButton() { return &object.button; }

extern "C" void test1Cpp() { object.test1Cpp(); }
extern "C" void test2Cpp() { object.test2Cpp(); }
