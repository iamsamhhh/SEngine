//
//  EntryPoint.cpp
//  SEngine_Internal
//
//  Created by henry on 2021/8/20.
//

#include "EntryPoint.hpp"

void RunUI(SEngine_Internal::Window* window);


void Inspector_w(SEngine_Internal::Window* window);
void Project_w(SEngine_Internal::Window* window);
void EditorSettings_w(SEngine_Internal::Window* window);


void RunMenuBar(SEngine_Internal::Window* window);


int main(){
    
    SEngine_Internal::Window::InitWindow();
    SEngine_Internal::Window* window = new SEngine_Internal::Window(5000, 5000, "SEngine_Internal");
    window->SetToCurrent();
    SEngine_Internal::Window::SetUpRender();
    window->SetUpUI();
    auto app = SEngine::CreatApplication();
    unsigned int frameCount = 0;
    while (!glfwWindowShouldClose(window->GetWindow())) {
        
        SEngine_Internal::Render2D::Clear();
        
        app->Run();
        
        SEngine_Internal::Render2D::DrawAll();
//        SEngine_Internal::Render2D::DrawAllQuad();
        
        window->FrameStart();
        RunUI(window);
        window->MenuBarStart();
        RunMenuBar(window);
        window->MenuBarEnd();
        window->FrameEnd();
        
        frameCount++;
        glfwPollEvents();
        glfwSwapBuffers(window->GetWindow());
    }
    delete window;
    delete app;
    
    
    return 0;
}
bool InspectorIsOpen, ProjectIsOpen, EditorSettingsIsOpen;

void RunUI(SEngine_Internal::Window* window){
    if (InspectorIsOpen) Inspector_w(window);
    if (ProjectIsOpen) Project_w(window);
    if (EditorSettingsIsOpen) EditorSettings_w(window);
}


void Project_w(SEngine_Internal::Window* window){
    window->Begin("project", &ProjectIsOpen);
    ImGui::Text("this is a file");
    window->End();
}
char buffer[30];
void Inspector_w(SEngine_Internal::Window* window){
    window->Begin("Inspector", &InspectorIsOpen);
    if (ImGui::CollapsingHeader("Transform")){
        ImGui::Text("Position:");
        ImGui::Text("x:");
        ImGui::InputText("x", buffer, sizeof(buffer));
        ImGui::Text("y");
    }
    if (ImGui::Button("add behaviour")) {
        
    }
    window->End();
}
void EditorSettings_w(SEngine_Internal::Window* window){
    window->Begin("Editor Settings", &EditorSettingsIsOpen);
    ImGui::Text("color");
    window->End();
}


void RunMenuBar(SEngine_Internal::Window* window){
    ImGui::Text("SEngine_Internal");
    if (window->BeginMenu("Windows")) {
        if (window->MenuItem("Inspector", NULL, &InspectorIsOpen)){
            
        }
        if (window->MenuItem("Project", NULL, &ProjectIsOpen)){
            
        }
        if (window->MenuItem("EditorSettings", NULL, &EditorSettingsIsOpen)){
            
        }
        
        window->EndMenu();
        
    }
}
