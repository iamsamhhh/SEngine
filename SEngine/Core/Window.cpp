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
    if (!Window::init){
        Window::init = Window::InitWindow();
        
    }
    Window::ID = glfwCreateWindow(width, height, title, NULL, NULL);
    
    printf("window init\n");
}
Window::~Window(){
    glfwDestroyWindow(ID);
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
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

void Window::SetUpUI(){
    ui = new UI(ID);
}
void Window::Text(const char *text, ...){
    va_list args;
    va_start(args, text);
    ui->Text(text, args);
    va_end(args);
    
}

void Window::Button(const char *lable){
    ui->Button(lable);
}


void Window::FrameStart(){
    ui->FrameStart();
    
}
void Window::FrameEnd(){
    ui->FrameEnd();
}

void Window::Begin(const char* name){
//    glfwMakeContextCurrent(ID);
    ui->Begin(name);
}
void Window::End(){
    ui->End();
}


}
