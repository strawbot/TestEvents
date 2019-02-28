#include "event.hpp"

void whenEventQ(EventQueue *event, void *cpp_obj, void *cpp_method)
{
    event->push(cpp_obj, cpp_method, 1);
}

void onceEventQ(EventQueue *event, void *cpp_obj, void *cpp_method)
{
    event->push(cpp_obj, cpp_method, 0);
}

void stopEventQ(EventQueue *event, void *cpp_obj, void *cpp_method)
{
    event->stop(cpp_obj, cpp_method);
}

extern "C"
{
    void whenEventQ(struct  EventQueue_t *event, void (*c_handler)())
    {
        static_cast<EventQueue *>(event)->push((void *) c_handler, 1);
    }

    void onceEventQ(struct  EventQueue_t *event, void (*c_handler)())
    {
        static_cast<EventQueue *>(event)->push((void *) c_handler, 0);
    }

    void stopEventQ(struct  EventQueue_t *event, void (*c_handler)())
    {
        static_cast<EventQueue *>(event)->stop((void *) c_handler);
    }

    void never(struct  EventQueue_t *event)
    {
        static_cast<EventQueue *>(event)->clear();
    }

    void happen(struct  EventQueue_t *event)
    {
        static_cast<EventQueue *>(event)->happen();
    }
}
