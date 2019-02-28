#ifndef EVENTC_H
#define EVENTC_H

#include "event.hpp"

#define once(e, h)  onceEventQ(e, (void *)&h)
#define when(e, h)  whenEventQ(e, (void *)&h)

#define QEvent(e)   struct queue_type e##qt[3]; struct EventQueue_t e[1] = {{3, 0, 0, e##qt}}

#endif // EVENTC_H
