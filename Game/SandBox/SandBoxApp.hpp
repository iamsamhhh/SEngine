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

namespace SEngine{


class SandBox: public Application{
public:
    SandBox();
    virtual ~SandBox();
    void Run() override;
private:
    SEngine::Logger* logger;
};

Application* CreatApplication();
}
#endif /* SandBoxApp_hpp */
