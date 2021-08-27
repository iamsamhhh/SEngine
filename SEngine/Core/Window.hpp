//
//  Window.hpp
//  SEngine
//
//  Created by henry on 2021/8/22.
//

#ifndef Window_hpp
#define Window_hpp

#include "Core.h"
#include "EntryPoint.hpp"
#include <GLFW/glfw3.h>


namespace SEngine{

// a window class manage all things about windows
class Window{
public:
    //initialize the window hints
    static bool InitWindow();
    
    
    Window(unsigned int width, unsigned int height, const char* title);
    ~Window();
    
    
    void SetToCurrent();
    GLFWwindow* GetWindow(){
        return ID;
    }
private:
    GLFWwindow* ID;
    static bool init;
    
};

}
#endif /* Window_hpp */
