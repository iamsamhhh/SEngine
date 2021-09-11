//
//  EntryPoint.cpp
//  SEngine_Internal
//
//  Created by henry on 2021/8/20.
//

#include "EntryPoint.hpp"

int main(){
    
    SEngine_Internal::MainWindow::SetUpMainWindow();
    auto app = SEngine::CreatApplication();
    
    while (!SEngine_Internal::MainWindow::WindowShouldClose()) {
        SEngine_Internal::Render2D::Clear(0.3, 0.6, 0.4, 1.0);
        
        app->Run();
        
        SEngine_Internal::Render2D::DrawAll();
        
        SEngine_Internal::MainWindow::Update();
        
        glfwPollEvents();
        glfwSwapBuffers(SEngine_Internal::MainWindow::GetID());
    }
    delete app;
    SEngine_Internal::MainWindow::ShutDown();
    
    return 0;
}
