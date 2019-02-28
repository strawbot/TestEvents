#include "event.hpp"

extern "C" void whenEventQ(struct EventQueue_t *event, void *cpp_obj, void *cpp_method)
{
    static_cast<EventQueue *>(event)->push(cpp_obj, cpp_method, 1);
}

extern "C" void onceEventQ(struct EventQueue_t *event, void *cpp_obj, void *cpp_method)
{
    static_cast<EventQueue *>(event)->push(cpp_obj, cpp_method, 0);
}

void stopEventQ(EventQueue *event, void *cpp_obj, void *cpp_method)
{
    event->stop(cpp_obj, cpp_method);
}

extern "C"
{
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
