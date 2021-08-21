//
//  Application.hpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#ifndef Application_hpp
#define Application_hpp

#include "Core.h"

namespace SEngine{
class Application{
public:
    Application();
    virtual ~Application();
    void Run();
};

Application* CreatApplication();
}
#endif /* Application_hpp */
