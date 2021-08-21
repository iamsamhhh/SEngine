//
//  Log.hpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#ifndef Log_hpp
#define Log_hpp

#include <stdio.h>
#include <string.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace SEngine {
class Log{
public:
    Log(std::string name);
    virtual ~Log();
    std::shared_ptr<spdlog::logger>& GetLogger();
    
private:
    std::shared_ptr<spdlog::logger> m_Logger;
};
}

#endif /* Log_hpp */
