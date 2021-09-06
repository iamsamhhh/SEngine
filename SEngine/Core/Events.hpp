//
//  Events.hpp
//  SEngine
//
//  Created by Sam cyx on 2021/8/28.
//

#ifndef Events_hpp
#define Events_hpp

#include <stdio.h>

namespace SEngine {
#define MAX_EVENT_COUNT 20
enum EventType{
    OnMouseDown
};


class Events{
public:
    typedef void (* m_event)();
    Events(EventType type);
    void Subscribe(m_event evt);
    void BroadCast();
private:
    m_event m_events[MAX_EVENT_COUNT];
    EventType m_type;
};


}

#endif /* Events_hpp */
