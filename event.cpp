#include "event.hpp"

extern "C" {

void whenEventQ(struct EventQueue_t* event, void* cpp_obj, void* cpp_method) {
  static_cast<EventQueue*>(event)->push(cpp_obj, cpp_method, 1);
}

void onceEventQ(struct EventQueue_t* event, void* cpp_obj, void* cpp_method) {
  static_cast<EventQueue*>(event)->push(cpp_obj, cpp_method, 0);
}

void stopEventQ(struct EventQueue_t* event, void* cpp_obj, void* cpp_method) {
  static_cast<EventQueue*>(event)->stop(cpp_obj, cpp_method);
}

void never(struct EventQueue_t* event) {
  static_cast<EventQueue*>(event)->clear();
}

void happen(struct EventQueue_t* event) {
  static_cast<EventQueue*>(event)->happen();
}
}
