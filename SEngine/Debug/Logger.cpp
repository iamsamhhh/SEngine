//
//  Log.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "Logger.hpp"
namespace SEngine{
Logger::Logger(std::string name){
    spdlog::set_pattern("%^[%T] [%l] %n: %v%$");
    Logger::m_Logger = spdlog::stdout_color_mt(name);
    Logger::m_Logger->set_level(spdlog::level::trace);
}
Logger::~Logger(){
    
}

std::shared_ptr<spdlog::logger>& Logger::GetLogger(){
    return Logger::m_Logger;
}
}
