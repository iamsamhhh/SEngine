//
//  UI.hpp
//  SEngine_Internal
//
//  Created by henry on 2021/8/23.
//

#ifndef UI_hpp
#define UI_hpp

#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>
#include <imgui_internal.h>
#include <iostream>

namespace SEngine_Internal{

class UI{
public:
    UI(GLFWwindow* window);
    void FrameStart();
    void Begin(const char* name);
    void End();
    void FrameEnd();
    void MenuBarStart();
    bool BeginMenu(const char* name);
    bool MenuItem(const char* name, const char* shortCut, bool* selected);
    void EndMenu();
    void MenuBarEnd();
private:
    GLFWwindow* m_window;
    static bool initialized;
    
};

}

//#include <imgui_internal.h>
#endif /* UI_hpp */
