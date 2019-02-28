#ifndef EVENTC_H
#define EVENTC_H

#include "eventcpp.h"

#define once(e, h)  onceEventQ(&e, (void *)&h)
#define when(e, h)  whenEventQ(&e, (void *)&h)
#define never(e)    clearEventQ(&e)
#define happen(e)   happenEventQ(&e)

#define QEvent(e)   struct queue_type e##qt[3]; struct EventQueue_t e = {3, 0, 0, e##qt}

#endif // EVENTC_H
