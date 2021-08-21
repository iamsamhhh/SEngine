//
//  SandBoxApp.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "SandBoxApp.hpp"

SandBox::SandBox(){
    SandBox::logger = new SEngine::Log("SandBox");
    logger->GetLogger()->warn("succedeed");
}
SandBox::~SandBox()
{
    
}

SEngine::Application* SEngine::CreatApplication(){
    return new SandBox();
}
