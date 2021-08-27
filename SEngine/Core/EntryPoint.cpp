//
//  EntryPoint.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "EntryPoint.hpp"

int main(){
    
    auto app = SEngine::CreatApplication();
    SEngine::Window* window = new SEngine::Window(5000, 5000, "SEngine");
    window->SetToCurrent();
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        return -1;
    }
    SEngine::UI* ui = new SEngine::UI(window->GetWindow());
    while (!glfwWindowShouldClose(window->GetWindow())) {
        glClearColor(0.5, 0.5, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        ui->FrameStart("A window");
        ui->Text("Hello!");
        ui->FrameEnd();
//        ui2->FrameStart("B window");
//        ui2->FrameEnd();
        glfwPollEvents();
        glfwSwapBuffers(window->GetWindow());
    }
    delete window;
    delete app;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    
    return 0;
}

