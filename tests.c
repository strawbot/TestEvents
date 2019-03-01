// test C events

#include <stdio.h>
#include "event.h"

// from the accounting department
extern int events, fails;

// define an event in C
QEvent(button);

// import C++ equivelants
extern struct EventQueue_t * cppButton();
void cppPress(int i);

void cpress(int n) { happen(button);  if (events != n)  fails++, printf(" <<C FAIL>> "); }
void action1() { printf("\nC button press 1"); events++; }
void action2() { printf("\nC button press %i",events++); }

void test1C() {
    printf("\n\nBegin C++ local event, C action tests:");

    printf("Begin C only tests:");
    printf("\nTest1 no handler button press");
    cpress(events);
    once(button, action1);
    printf("\nTest2 with action1");
    cpress(events + 1);
    printf("\nTest3 no handler button press");
    cpress(events);
    printf("\nTest4 multiple (3) button presses");
    when(button, action2);
    cpress(events + 1);
    cpress(events + 1);
    cpress(events + 1);
    never(button);
    printf("\nTest5 never handler button press");
    cpress(events);
}

void test2() {
    printf("\nTest1 no handler button press");
    cppPress(events);
    once(cppButton(), action1);
    printf("\nTest2 with action1");
    cppPress(events + 1);
    printf("\nTest3 no handler button press");
    cppPress(events);
    printf("\nTest4 multiple (3) button presses");
    when(cppButton(), action2);
    cppPress(events + 1);
    cppPress(events + 1);
    cppPress(events + 1);
    never(cppButton());
    printf("\nTest5 never handler button press");
    cppPress(events);
}
