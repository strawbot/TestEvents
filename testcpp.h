#ifndef TESTCPP_H
#define TESTCPP_H

#include "event.hpp"
#include <stdio.h>
extern "C" EventQueue cbutton[];
extern int events, fails;
class testcpp
{
public:
    int i = 0;
    EventQueue button;
    testcpp() : button(3) { i = 2; };
    void press(int n) { happen(&button); if (events != n) fails++, printf(" <<C++ FAIL>> "); }
    static void action1(testcpp * self) { (void)self; printf("\nC++ button press 1"); events++; }
    static void action2(testcpp * self) { printf("\nC++ button press %i",self->i++); events++; }
    void test1Cpp () {
        fails = events = 0;
        printf("\nTest1 no handler button press");
        press(0);
        onceEventQ(&button, (void *)this, (void *)&action1);
        printf("\nTest2 with action1");
        press(1);
        printf("\nTest3 no handler button press");
        press(1);
        printf("\nTest4 multiple (3) button presses");
        _whenEventQ(&button, (void *)this, (void *)&action2);
        press(2);
        press(3);
        press(4);
        never(&button);
        printf("\nTest5 never handler button press");
        press(4);
    }
    void test2Cpp () {
        fails = events = 0;
        printf("\nTest1 no handler button press");
        press(0);
        onceEventQ(cbutton, (void *)this, (void *)&action1);
        printf("\nTest2 with action1");
        press(1);
        printf("\nTest3 no handler button press");
        press(1);
        printf("\nTest4 multiple (3) button presses");
        _whenEventQ(cbutton, (void *)this, (void *)&action2);
        press(2);
        press(3);
        press(4);
        never(cbutton);
        printf("\nTest5 never handler button press");
        press(4);
    }
};

class testcpp2 {
    void press(int n) { happen(cbutton); if (events != n) fails++, printf(" <<C++ FAIL>> "); }
    static void action1(testcpp * self) { (void)self; printf("\nC++ button press 1"); events++; }
    static void action2(testcpp * self) { printf("\nC++ button press %i",self->i++); events++; }
};

#endif // TESTCPP_H
