//
//  Window.cpp
//  SEngine
//
//  Created by henry on 2021/8/22.
//

#include "Window.hpp"
namespace SEngine {
bool Window::init = false;

Window::Window(unsigned int width, unsigned int height, const char* title){
    if (!Window::init) Window::init = Window::InitWindow();
    
    Window::ID = glfwCreateWindow(width, height, title, NULL, NULL);
}
Window::~Window(){
    glfwDestroyWindow(ID);
}

bool Window::InitWindow(){
    if(!glfwInit()){
        Window::init = false;
        return false;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    return true;
}

void Window::SetToCurrent(){
    glfwMakeContextCurrent(Window::ID);
}

}
