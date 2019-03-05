// test C events

#include "event.h"
#include "timeEvent.h"
#include "ttypes.h"
#include <stdio.h>
#include "test.h"

void timeevent_IRQ();
void addTime(Long n);

// from the accounting department
extern int events, fails;

const char* file = __FILE__;
int lineno = __LINE__;

// define an event in C
extEvent(button);
Event(button);

// import C++ equivelants
extern EventQueue* cppButton();
void cppPress(int i);

// define C API

void eventTest(int n) {
    if (events++ != n) {
        fails++;
        printf(RED" <<FAIL>> "NORMAL" expected:%i  %s line# %i", n, file, lineno);
    }
}

void cpress(int n) {
    happen(button);
    eventTest(n);
}

void action1() {
    printf("\nC action 1 %i", ++events);
}

void action2() {
    printf("\nC action 2 %i", ++events);
    events++;
}

// Tests
void test1C() {
    printf("\n\nBegin C only event tests:");

    printf("\nTest1 no handler button press");
    cpress(events);
    once(button, action1);
    printf("\nTest2 with action1");
    cpress(events + 1);
    printf("\nTest3 no handler button press");
    cpress(events);
    printf("\nTest4 multiple (3) button presses");
    when(button, action2);
    cpress(events + 2);
    cpress(events + 2);
    cpress(events + 2);
    never(button);
    printf("\nTest5 never handler button press");
    cpress(events);
    once(button, action1);
    stop(button, action1);
    printf("\nTest6 stop action before button press");
    cpress(events);

    once(button, action1);
    when(button, action2);
    stop(button, action1);
    stop(button, action2);
    printf("\nTest6 stop action before button press");
    cpress(events);
}

void test2C() {
    printf("\n\nBegin C++ local event, C local event tests:");

    printf("\nTest1 no handler button press");
    cppPress(events);
    once(cppButton(), action1);
    printf("\nTest2 with action1");
    cppPress(events + 1);
    printf("\nTest3 no handler button press");
    cppPress(events);
    printf("\nTest4 multiple (3) button presses");
    when(cppButton(), action2);
    cppPress(events + 2);
    cppPress(events + 2);
    cppPress(events + 2);
    never(cppButton());
    printf("\nTest5 never handler button press");
    cppPress(events);
}

void predictFunction(int offset, int msecs) {
    int i = events + offset;
    addTime(ta_msecs(msecs));
    timeevent_IRQ();
    eventTest(i);
}

#define predict(o, m) lineno = __LINE__, predictFunction(o, m)

void test3C() {
    printf("\n\nBegin C time event tests:");
    after(21, action1);
    predict(0, 0);
    predict(0, 20);
    predict(1, 1);
    predict(0, 1);
    after(22, action2);
    predict(0, 0);
    predict(0, 21);
    predict(2, 1);
    predict(0, 1);
    every(20, action1);
    predict(0, 0);
    predict(0, 19);
    predict(1, 1); // test time
    predict(0, 1);
    predict(0, 18);
    predict(1, 1); // test repeat
    predict(0, 1);
    predict(1, 40); // test missed one
    predict(1, 0); // should get both
    predict(0, 0);
    stopTimeEvent(action1);
    predict(0, 20);
    TimeEvent* te = every(20, action1);
    stopTe(te);
    predict(0, 20);
}
