#ifndef TESTCPP_H
#define TESTCPP_H

#include "event.h"
#include <stdio.h>

// from the accounting department
extern int events, fails;

// import C equivelants
extern "C" void cpress(int);
extern "C" EventQueue button[];
#define cbutton ::button

class testcpp {
 public:
  int i = 0;       // for testing action access to instance
  QEvent(button);  // if renamed to buttonx tests still pass
  testcpp() { i = 0; };
  void press(int n) {
    happen(button);
    if (events != n)
      fails++, printf(" <<C++ FAIL>> ");
  }
  static void action1(testcpp* self) {
    (void)self;
    printf("\nC++ button press 1");
    events++;
  }
  static void action2(testcpp* self) {
    printf("\nC++ button press local:%i global %i", self->i++, events++);
  }
  void test1Cpp() {
    printf("\n\nBegin C++ only tests:");

    printf("\nTest1 no handler button press");
    press(events);
    once(button, action1);
    printf("\nTest2 with action1");
    press(events + 1);
    printf("\nTest3 no handler button press");
    press(events);
    printf("\nTest4 multiple (3) button presses");
    when(button, action2);
    press(events + 1);
    press(events + 1);
    press(events + 1);
    never(button);
    printf("\nTest5 never handler button press");
    press(events);
  }
  void test2Cpp() {
    printf("\n\nBegin C local event C++ action tests:");

    printf("\nTest1 no handler button press");
    cpress(events);
    once(cbutton, action1);
    printf("\nTest2 with action1");
    cpress(events + 1);
    printf("\nTest3 no handler button press");
    cpress(events);
    printf("\nTest4 multiple (3) button presses");
    when(cbutton, action2);
    cpress(events + 1);
    cpress(events + 1);
    cpress(events + 1);
    never(cbutton);
    printf("\nTest5 never handler button press");
    cpress(events);
  }
};

class testcpp2 {
  void press(int n) {
    happen(cbutton);
    if (events != n)
      fails++, printf(" <<C++ FAIL>> ");
  }
  static void action1(testcpp* self) {
    (void)self;
    printf("\nC++ button press 1");
    events++;
  }
  static void action2(testcpp* self) {
    printf("\nC++ button press %i", self->i++);
    events++;
  }
};

#endif  // TESTCPP_H
