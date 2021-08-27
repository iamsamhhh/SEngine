//
//  Log.hpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#ifndef Logger_hpp
#define Logger_hpp

#include <stdio.h>
#include <string.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace SEngine {
class Logger{
public:
    Logger(std::string name);
    virtual ~Logger();
    std::shared_ptr<spdlog::logger>& GetLogger();
    
private:
    std::shared_ptr<spdlog::logger> m_Logger;
};
}

#endif /* Logger_hpp */
