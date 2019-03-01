#include "event.h"

extern "C" {

void whenEvent(struct EventQueue_t* event, void* cpp_obj, void* cpp_method) {
  static_cast<EventQueue*>(event)->push(cpp_obj, cpp_method, 1);
}

void onceEvent(struct EventQueue_t* event, void* cpp_obj, void* cpp_method) {
  static_cast<EventQueue*>(event)->push(cpp_obj, cpp_method, 0);
}

void stopEvent(struct EventQueue_t* event, void* cpp_obj, void* cpp_method) {
  static_cast<EventQueue*>(event)->remove(cpp_obj, cpp_method);
}

void never(struct EventQueue_t* event) {
  static_cast<EventQueue*>(event)->clear();
}

void happen(struct EventQueue_t* event) {
  static_cast<EventQueue*>(event)->happen();
}
}
