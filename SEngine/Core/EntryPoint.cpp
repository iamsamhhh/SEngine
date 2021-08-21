//
//  EntryPoint.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "EntryPoint.hpp"

extern SEngine::Application* CreatApplication();

int main(){
    SEngine::Log* coreLog = new SEngine::Log("SEngine");
    coreLog->GetLogger()->info("Hello!");
    auto app = SEngine::CreatApplication();
    app->Run();
    delete app;
    
    return 0;
}

