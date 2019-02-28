/*
 * File:   events.h
 * Author: paul
 *
 * Created on February 26, 2019, 6:54 AM
 */

#ifndef EVENTS_H
#define EVENTS_H

#include <string.h>
#include <stdio.h>

struct queue_type {
    void *object, *method;
    char persist;
};

struct EventQueue_t {
    int _size, _head, _tail;
    struct queue_type *_queue;
};

#ifdef __cplusplus

class EventQueue : public EventQueue_t {
public:
    void push(void *cpp_obj, void *cpp_method, char persist)
    {
        _queue[_head++]={cpp_obj, cpp_method, persist};
        _head %= _size;
    }

    int stop(void *cpp_obj, void *cpp_method)
    {
        int total = count();

        for (int i=0; i<total; i++)
        {
            queue_type e;

            if (pop(&e) < 0) return -1;

            if (e.object != cpp_obj && e.method != cpp_method)
            {
                push(e.object, e.method, e.persist);
            }
        }
        return 0;
    }

    int stop(void *c_handler)
    {
        int total = count();

        for (int i=0; i<total; i++)
        {
            queue_type e;

            if (pop(&e) < 0) return -1;

            if (e.method != c_handler)
            {
                push(nullptr, e.method, e.persist);
            }
        }
        return 0;
    }

    void happen()
    {
        int total = count();

        for (int i=0; i<total; i++)
        {
            queue_type e;

            if (pop(&e) == 0)
            {
                if (e.persist)
                    push(e.object, e.method, e.persist);

                if (e.object == nullptr)
                {
                    void (*callback)() = (void (*)()) e.method;
                    callback();
                }
                else
                {
                    void (*method)(void *) = (void (*)(void *)) e.method;
                    method(e.object);
                }
            }
        }
    }

    int pop(queue_type *entry)
    {
        if (_head == _tail) return -1;

        memcpy(entry, &_queue[_tail], sizeof(queue_type));
        _tail = (_tail + 1) % _size;

        return 0;
    }

    int count()
    {
        return (_head + _size - _tail) % _size;
    }

    void clear()
    {
        _head = _tail = 0;
    }
};

void stopEventQ(EventQueue *event, void *cpp_obj, void *cpp_method);

#endif

#define QEvent(e)   struct queue_type e##qt[3]; struct EventQueue_t e[1] = {{3, 0, 0, e##qt}}

#ifdef __cplusplus
extern "C"
{
#endif
//      void whenEventQ(struct EventQueue_t *event, void (*c_handler)());
    void whenEventQ(struct EventQueue_t *event, void *cpp_obj, void *cpp_method);
    void onceEventQ(struct EventQueue_t *event, void *cpp_obj, void *cpp_method);
    void stopEventQ(struct EventQueue_t *event, void (*c_handler)());
    void never(struct EventQueue_t *event);
    void happen(struct EventQueue_t *event);

#define QEvent(e)   struct queue_type e##qt[3]; struct EventQueue_t e[1] = {{3, 0, 0, e##qt}}

//#define when(e, h)  whenEventQ(e, (void *)&h)
#define once(e, h)  onceEventQ(e, (void *)this, (void *)&h)
#define when(e, h)  whenEventQ(e, (void *)this, (void *)&h)

#ifdef __cplusplus
}
#endif

#endif /* EVENTS_H */
