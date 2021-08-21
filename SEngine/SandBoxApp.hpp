//
//  SandBoxApp.hpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#ifndef SandBoxApp_hpp
#define SandBoxApp_hpp

#include "SEngine.h"

class SandBox: public SEngine::Application{
public:
    SandBox();
    virtual ~SandBox();
private:
    SEngine::Log* logger;
};

SEngine::Application* SEngine::CreatApplication();


#endif /* SandBoxApp_hpp */
