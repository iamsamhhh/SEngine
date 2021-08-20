//
//  SandBoxApp.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "SandBoxApp.hpp"

class SandBox: public SEngine::Application{
public:
    SandBox()
    {
        printf("Hello SEngine!\n");
    }
    ~SandBox()
    {
        printf("bye SEngine!\n");
    }
};

SEngine::Application* SEngine::CreatApplication(){
    return new SandBox();
}
