//
//  EntryPoint.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "EntryPoint.hpp"
extern SEngine::Application* SEngine::CreatApplication();
int main(){
    auto app = SEngine::CreatApplication();
    app->Run();
    delete app;
    
    return 0;
}
