//
//  UI.cpp
//  SEngine
//
//  Created by henry on 2021/8/23.
//

#include "UI.hpp"
namespace SEngine{
bool UI::initialized = false;

UI::UI(GLFWwindow* window){
    ImGui::CreateContext(NULL);
    
    UI::m_window = window;
    if (!initialized) {
        IMGUI_CHECKVERSION();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigWindowsMoveFromTitleBarOnly = true;
        ImGui::StyleColorsDark();
        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init("#version 330");
        initialized = true;
    }
    
}
void UI::FrameStart(){
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
    
}
void UI::Begin(const char* name){
    ImGui::Begin(name);
}
void UI::End(){
    ImGui::End();
}
void UI::FrameEnd(){
    
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
void UI::MenuBarStart(){
    ImGui::BeginMainMenuBar();
}
bool UI::BeginMenu(const char* name){
    return ImGui::BeginMenu(name);
}
bool UI::MenuItem(const char* name, const char* shortCut, bool* selected){
    return ImGui::MenuItem(name, shortCut, selected);
}
void UI::EndMenu(){
    ImGui::EndMenu();
}
void UI::MenuBarEnd(){
    ImGui::EndMainMenuBar();
}


}
