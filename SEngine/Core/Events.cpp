//
//  Events.cpp
//  SEngine_Internal
//
//  Created by Sam cyx on 2021/8/28.
//

#include "Events.hpp"
namespace SEngine_Internal{

Events::Events(EventType type){
    m_type = type;
    for (int i = 0; i < MAX_EVENT_COUNT; i++) {
        m_events[i] = NULL;
    }
}

void Events::Subscribe(m_event evt){
    for(int i = 0; i < MAX_EVENT_COUNT; i++){
        if (m_events[i]==NULL) {
            m_events[i] = evt;
            return;
        }
    }
}
void Events::BroadCast(){
    for(int i = 0; i < MAX_EVENT_COUNT; i++){
        if (m_events[i]!=NULL) {
            m_events[i]();
        }
    }
}


}
