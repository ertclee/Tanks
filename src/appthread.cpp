#include "appthread.h"


AppThread::AppThread(SharedData *shared_data, CRITICAL_SECTION *critical_section)
{
    this->shared_data = shared_data;
    this->critical_section = critical_section;
}

void AppThread::saveEvent(Event *event)
{
    EnterCriticalSection(critical_section);
        shared_data->transmit_events.addEvent(event);
    LeaveCriticalSection(critical_section);
}

void AppThread::sendEventQueue()
{
    EnterCriticalSection(critical_section);
        shared_data->send_events = true;
    LeaveCriticalSection(critical_section);
}