//
//  Application.hpp
//  SEngine_Internal
//
//  Created by henry on 2021/8/20.
//

#ifndef Application_hpp
#define Application_hpp


namespace SEngine {
class Application{
public:
    Application();
    virtual ~Application();
    virtual void Run(){}
    unsigned int scrWidth = 800, scrHeight = 720;
};

Application* CreatApplication();
}
#endif /* Application_hpp */
