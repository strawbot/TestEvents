// test C events

#include <stdio.h>
#include "eventc.h"

QEvent(cbutton);
extern struct EventQueue_t * cppButton();

void press() { happen(cbutton); }
void action1() { printf("\nButton press 1"); }
void action2() { static int i = 2; printf("\nButton press %i",i++); }

void test1C() {
    printf("\nTest1 no handler button press");
    press();
    once(cbutton, action1);
    printf("\nTest2 with action1");
    press();
    printf("\nTest3 no handler button press");
    press();
    printf("\nTest4 multiple (3) button presses");
    when(cbutton, action2);
    press();
    press();
    press();
    never(cbutton);
    printf("\nTest5 never handler button press");
    press();
}

void test2() {
    printf("\nTest1 no handler button press");
    press();
    onceEventQ(cppButton(), action1);
    printf("\nTest2 with action1");
    press();
    printf("\nTest3 no handler button press");
    press();
    printf("\nTest4 multiple (3) button presses");
    whenEventQ(cppButton(), action2);
    press();
    press();
    press();
    clearEventQ(cppButton());
    printf("\nTest5 never handler button press");
    press();
}
