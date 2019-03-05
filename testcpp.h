#ifndef TESTCPP_H
#define TESTCPP_H

#include "event.h"
#include "test.h"
#include "timeEvent.h"
#include <stdio.h>

// from the accounting department
extern const char* file;
extern int lineno;

// import C equivelants
extern "C" {
void cpress(int);
extEvent(button);
void timeevent_IRQ();
void addTime(Long n);
}
#define cbutton ::button

class testcpp {
public:
    Event(button); // if renamed to buttonx tests still pass
    int i = 0; // for testing action access to instance

    // API
    void press(int n) {
        happen(button);
        eventTest(n);
    }

    static void action1(void* self) {
        (void)self;
        printf("\nC action 1 %i", ++events);
    }

    static void action2(void* obj) {
        testcpp* self = (testcpp*)obj;
        printf("\nC++ action 2 local:%i global %i", ++self->i, ++events);
        events++;
    }

    // Tests
    void test1Cpp() {
        printf("\n\nBegin C++ only event tests:");

        printf("\nTest1 no handler button press");
        press(events);
        once(button, action1);
        //        once(button, (void*)this, (void*)&action1);
        printf("\nTest2 with action1");
        press(events + 1);
        printf("\nTest3 no handler button press");
        press(events);
        printf("\nTest4 multiple (3) button presses");
        when(button, action2);
        press(events + 2);
        press(events + 2);
        press(events + 2);
        never(button);
        printf("\nTest5 never handler button press");
        press(events);
        once(button, action1);
        stop(button, action1);
        printf("\nTest6 stop action before button press");
        press(events);
        once(button, action1);
        when(button, action2);
        stop(button, action1);
        stop(button, action2);
    }
    void test2Cpp() {
        printf("\n\nBegin C local event C++ event tests:");

        printf("\nTest1 no handler button press");
        cpress(events);
        once(cbutton, action1);
        printf("\nTest2 with action1");
        cpress(events + 1);
        printf("\nTest3 no handler button press");
        cpress(events);
        printf("\nTest4 multiple (3) button presses");
        when(cbutton, action2);
        cpress(events + 2);
        cpress(events + 2);
        cpress(events + 2);
        never(cbutton);
        printf("\nTest5 never handler button press");
        cpress(events);
    }

#define predict(o, m) lineno = __LINE__, predictFunction(o, m)

    void test3Cpp() {
        printf("\n\nBegin C++ time event tests:");

        init_te();
        after(21, this, action1);
        predict(0, 0);
        predict(0, 20);
        predict(1, 1);
        predict(0, 1);
        after(22, this, action2);
        predict(0, 0);
        predict(0, 21);
        predict(2, 1);
        predict(0, 1);
        every(20, this, action1);
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
        stopTimeEvent(this, action1);
        predict(0, 20);
        TimeEvent* te = every(20, this, action1);
        stopTe(te);
        predict(0, 20);
    }
};

Event(cfbutton);

void cfpress(int n) {
    happen(cfbutton);
    eventTest(n);
}

static void action1() {
    printf("\nC action 1 %i", ++events);
}

static void action2() {
    printf("\nC++ action 2 %i", ++events);
    events++;
}

void action4() {
    printf("\nC++ button press 4 %i", events);
    events += 2;
}

void action3() {
    printf("\nC action 3 %i", ++events);
    whenEvent(cfbutton, (void*)&action4, (void*)jump);
}

extern "C" void testCppFunction() { // syntax is ugly but it works
    printf("\n\nTest C++ function events.");

    onceEvent(cfbutton, (void*)&action3, (void*)jump);
    cfpress(events + 1);
    cfpress(events + 2);
    cfpress(events + 2);
    stopEvent(cfbutton, (void*)&action4, (void*)jump);
    cfpress(events);

    // time events
    init_te();
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

extern "C" void testCppFunction();

#endif // TESTCPP_H
