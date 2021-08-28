//
//  Window.hpp
//  SEngine
//
//  Created by henry on 2021/8/22.
//

#ifndef Window_hpp
#define Window_hpp

#include "EntryPoint.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "UI.hpp"

namespace SEngine{

// a window class manage all things about windows
class Window{
public:
    //initialize the window hints
    static bool InitWindow();
    
    
    Window(unsigned int width, unsigned int height, const char* title);
    ~Window();
    
    
    void SetToCurrent();
    void SetUpUI();
    static bool SetUpRender(){
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            return false;
        }
        
        return true;
    }
    
    void Begin(const char* name);
    void End();
    void FrameStart();
    void Text(const char* text, ...);
    void Button(const char* lable);
    void FrameEnd();
    
    
    UI* GetUI(){
        return ui;
    }
    GLFWwindow* GetWindow(){
        return ID;
    }
private:
    GLFWwindow* ID;
    UI* ui;
    static bool init;
};

}
#endif /* Window_hpp */
