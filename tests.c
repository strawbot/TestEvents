// test C events

#include <stdio.h>
#include "event.h"

QEvent(cbutton);
extern struct EventQueue_t * cppButton();
extern int events, fails;

void press(int n) { happen(cbutton);  if (events != n)  fails++, printf(" <<C FAIL>> "); }
void action1() { printf("\nC button press 1"); events++; }
void action2() { printf("\nC button press %i",events++); }

void test1C() {
    events = 0;
    printf("\nTest1 no handler button press");
    press(0);
    once(cbutton, action1);
    printf("\nTest2 with action1");
    press(1);
    printf("\nTest3 no handler button press");
    press(1);
    printf("\nTest4 multiple (3) button presses");
    when(cbutton, action2);
    press(2);
    press(3);
    press(4);
    never(cbutton);
    printf("\nTest5 never handler button press");
    press(4);
}

void test2() {
    events = 0;
    printf("\nTest1 no handler button press");
    press(0);
    onceEventQ(cppButton(), action1);
    printf("\nTest2 with action1");
    press(1);
    printf("\nTest3 no handler button press");
    press(1);
    printf("\nTest4 multiple (3) button presses");
    whenEventQ(cppButton(), action2);
    press(2);
    press(3);
    press(4);
    never(cppButton());
    printf("\nTest5 never handler button press");
    press(4);
}
