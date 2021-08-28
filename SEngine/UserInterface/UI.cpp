//
//  UI.cpp
//  SEngine
//
//  Created by henry on 2021/8/23.
//

#include "UI.hpp"
namespace SEngine{
bool UI::initialized = false;
void UI::Text(const char *text, ...){
    va_list args;
    va_start(args, text);
    ImGui::Text(text, args);
    va_end(args);
}

void UI::Button(const char *lable){
    ImGui::Button(lable);
}



UI::UI(GLFWwindow* window){
    ImGui::CreateContext(NULL);
    
    UI::m_window = window;
    if (!initialized) {
        IMGUI_CHECKVERSION();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
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

}
