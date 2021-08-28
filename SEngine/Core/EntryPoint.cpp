//
//  EntryPoint.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "EntryPoint.hpp"


float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};
unsigned int indices[] = {
    0, 2, 1
};
float quadVertices[] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f
};
int main(){
    
    auto app = SEngine::CreatApplication();
    SEngine::Window::InitWindow();
    SEngine::Window* window = new SEngine::Window(5000, 5000, "SEngine");
    window->SetToCurrent();
    SEngine::Window::SetUpRender();
    window->SetUpUI();
    SEngine::Render2D render = SEngine::Render2D();
    
    while (!glfwWindowShouldClose(window->GetWindow())) {
        render.Clear();
        
        render.DrawQuad(quadVertices);
//        render.DrawTri(vertices);
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

