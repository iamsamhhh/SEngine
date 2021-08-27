//
//  UI.hpp
//  SEngine
//
//  Created by henry on 2021/8/23.
//

#ifndef UI_hpp
#define UI_hpp

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
namespace SEngine{

class UI{
public:
    UI(GLFWwindow* window);
    void FrameStart(const char* name);
    void Text(const char* text, ...);
    void Button(const char* lable);
    void FrameEnd();
private:
    GLFWwindow* m_window;
    static bool initialized;
};

}

//#include <imgui_internal.h>
#endif /* UI_hpp */
