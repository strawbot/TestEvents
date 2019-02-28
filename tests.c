// test C events

#include <stdio.h>
#include "event.h"

QEvent(cbutton);
extern struct EventQueue_t * cppButton();
void cppPress(int i);
extern int events, fails;

void cpress(int n) { happen(cbutton);  if (events != n)  fails++, printf(" <<C FAIL>> "); }
void action1() { printf("\nC button press 1"); events++; }
void action2() { printf("\nC button press %i",events++); }

void test1C() {
    events = 0;
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

void test2() {
    events = 0;
    printf("\nTest1 no handler button press");
    cppPress(0);
    once(cppButton(), action1);
    printf("\nTest2 with action1");
    cppPress(1);
    printf("\nTest3 no handler button press");
    cppPress(1);
    printf("\nTest4 multiple (3) button presses");
    whenEventQ(cppButton(), action2);
    cppPress(2);
    cppPress(3);
    cppPress(4);
    never(cppButton());
    printf("\nTest5 never handler button press");
    cppPress(4);
}
