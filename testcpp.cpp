#include "testcpp.h"

testcpp object, subject;
testcpp* actual = &object;

extern "C" EventQueue* cppButton() {
    return actual->button;
}
extern "C" void cppPress(int i) {
    actual->press(i);
}

extern "C" void test1Cpp() {
    actual->test1Cpp();
}

extern "C" void test2Cpp() {
    actual->test2Cpp();
}

extern "C" void test3Cpp() {
    actual->test3Cpp();
}

extern "C" void* oa = (void*)&actual->action1;

extern "C" void change() {
    actual = (actual == &subject) ? &object : &subject;
}
