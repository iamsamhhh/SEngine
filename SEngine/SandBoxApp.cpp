//
//  SandBoxApp.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "SandBoxApp.hpp"

SandBox::SandBox(){
    SandBox::logger = new SEngine::Logger("SandBox");
    logger->GetLogger()->info("app initialized");
    scrHeight = 800;
    scrWidth = 1300;
}
SandBox::~SandBox()
{
    logger->GetLogger()->info("bye");
}

SEngine::Application* SEngine::CreatApplication(){
    return new SandBox();
}
