//
//  Log.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "Log.hpp"
namespace SEngine{
Log::Log(std::string name){
    spdlog::set_pattern("%^[%T] [%l] %n: %v%$");
    Log::m_Logger = spdlog::stdout_color_mt(name);
    Log::m_Logger->set_level(spdlog::level::trace);
}
Log::~Log(){
    
}
std::shared_ptr<spdlog::logger>& Log::GetLogger(){
    return Log::m_Logger;
}
}
