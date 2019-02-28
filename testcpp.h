#ifndef TESTCPP_H
#define TESTCPP_H

#include "eventcpp.h"
#include <stdio.h>
extern "C" EventQueue cbutton;
class testcpp
{
    int i;
public:
    EventQueue button;
    testcpp() : button(3) { i = 2; };
    void press() { happenEventQ(&button); }
    static void action1(testcpp * self) { (void)self; printf("\nButton press 1"); }
    static void action2(testcpp * self) { printf("\nButton press %i",self->i++); }
    void test1Cpp () {
        printf("\nTest1 no handler button press");
        press();
        onceEventQ(&button, (void *)this, (void *)&action1);
        printf("\nTest2 with action1");
        press();
        printf("\nTest3 no handler button press");
        press();
        printf("\nTest4 multiple (3) button presses");
        _whenEventQ(&button, (void *)this, (void *)&action2);
        press();
        press();
        press();
        clearEventQ(&button);
        printf("\nTest5 never handler button press");
        press();
    }
    void test2Cpp () {
        printf("\nTest1 no handler button press");
        press();
        onceEventQ(&cbutton, (void *)this, (void *)&action1);
        printf("\nTest2 with action1");
        press();
        printf("\nTest3 no handler button press");
        press();
        printf("\nTest4 multiple (3) button presses");
        _whenEventQ(&cbutton, (void *)this, (void *)&action2);
        press();
        press();
        press();
        clearEventQ(&cbutton);
        printf("\nTest5 never handler button press");
        press();
    }
};

#endif // TESTCPP_H
