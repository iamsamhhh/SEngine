//
//  SandBoxApp.hpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#ifndef SandBoxApp_hpp
#define SandBoxApp_hpp

#include "SEngine.h"
#include "SEngine_internal.h"
using namespace SEngine;
using namespace SEngine_Internal;

class SandBox: public Application{
public:
    SandBox();
    virtual ~SandBox();
    void Run() override;
private:
    Logger* logger;
};

Application* SEngine::CreatApplication();

#endif /* SandBoxApp_hpp */
