#ifndef TESTCPP_H
#define TESTCPP_H

#include "event.hpp"
#include <stdio.h>
extern "C" EventQueue cbutton[];
extern int events, fails;
extern "C" void cpress(int);

class testcpp
{
public:
    int i = 0;
    QEvent(button);
    testcpp() { i = 2; };
    void press(int n) { happen(button); if (events != n) fails++, printf(" <<C++ FAIL>> "); }
    static void action1(testcpp * self) { (void)self; printf("\nC++ button press 1"); events++; }
    static void action2(testcpp * self) { printf("\nC++ button press %i",self->i++); events++; }
    void test1Cpp () {
        fails = events = 0;
        printf("\nTest1 no handler button press");
        press(0);
        once(button, action1);
        printf("\nTest2 with action1");
        press(1);
        printf("\nTest3 no handler button press");
        press(1);
        printf("\nTest4 multiple (3) button presses");
        when(button, action2);
        press(2);
        press(3);
        press(4);
        never(button);
        printf("\nTest5 never handler button press");
        press(4);
    }
    void test2Cpp () {
        fails = events = 0;
        printf("\nTest1 no handler button press");
        cpress(0);
        once(cbutton, action1);
        printf("\nTest2 with action1");
        cpress(1);
        printf("\nTest3 no handler button press");
        cpress(1);
        printf("\nTest4 multiple (3) button presses");
        when(cbutton, action2);
        cpress(2);
        cpress(3);
        cpress(4);
        never(cbutton);
        printf("\nTest5 never handler button press");
        cpress(4);
    }
};

class testcpp2 {
    void press(int n) { happen(cbutton); if (events != n) fails++, printf(" <<C++ FAIL>> "); }
    static void action1(testcpp * self) { (void)self; printf("\nC++ button press 1"); events++; }
    static void action2(testcpp * self) { printf("\nC++ button press %i",self->i++); events++; }
};

#endif // TESTCPP_H
