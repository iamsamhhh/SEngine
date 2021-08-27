//
//  EntryPoint.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "EntryPoint.hpp"

int main(){
    
    auto app = SEngine::CreatApplication();
    SEngine::Window::InitWindow();
    SEngine::Window* window = new SEngine::Window(5000, 5000, "SEngine");
    window->SetToCurrent();
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        return -1;
    }
    window->SetUpUI();
    
    while (!glfwWindowShouldClose(window->GetWindow())) {
        glClearColor(0.5, 0.5, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        
        window->FrameStart();
        
        window->Begin("A");
        window->Text("Hello A!");
        window->End();
        window->Begin("B");
        window->Text("Hello B!");
        window->End();
        window->FrameEnd();
        
        
        glfwPollEvents();
        glfwSwapBuffers(window->GetWindow());
    }
    delete window;
    delete app;
    
    
    return 0;
}

