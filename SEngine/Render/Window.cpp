//
//  Window.cpp
//  SEngine_Internal
//
//  Created by henry on 2021/8/22.
//

#include "Window.hpp"
namespace SEngine_Internal {
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

void Window::FrameStart(){
    ui->FrameStart();
    
}
void Window::FrameEnd(){
    ui->FrameEnd();
}

void Window::Begin(const char* name, bool* isOpen){
//    glfwMakeContextCurrent(ID);
    ui->Begin(name);
    if (ImGui::Button("Close")){
        *isOpen = false;
    }
}
void Window::End(){
    ui->End();
}
void Window::MenuBarStart(){
    ui->MenuBarStart();
}
bool Window::BeginMenu(const char* name){
    return ui->BeginMenu(name);
}
bool Window::MenuItem(const char* name, const char* shortCut, bool* selected){
    return ui->MenuItem(name, shortCut, selected);
}
void Window::EndMenu(){
    ui->EndMenu();
}
void Window::MenuBarEnd(){
    ui->MenuBarEnd();
}


//--------------------------------------MainWindow-------------------------------------------------

SEngine::Material MainWindow::mat = SEngine::Material();
char MainWindow::buffer[30];
Window* MainWindow::window;
bool MainWindow::InspectorIsOpen = false, MainWindow::ProjectIsOpen = false,
     MainWindow::EditorSettingsIsOpen = false, MainWindow::HeirachyIsOpen = false;

void MainWindow::gray(SEngine::Shader* shader){
    shader->setVec3("color", 0.6, 0.6, 0.6);
}
void MainWindow::SetUpMainWindow(){
    Window::InitWindow();
    window = new Window(10000, 10000, "SEngine");
    window->SetToCurrent();
    Window::SetUpRender();
    window->SetUpUI();
    SEngine::Material::GenerateDefaults();
    mat = SEngine::Material(gray);
}
void MainWindow::RunUI(SEngine_Internal::Window* window){
    if (InspectorIsOpen) Inspector_w(window);
    if (ProjectIsOpen) Project_w(window);
    if (EditorSettingsIsOpen) EditorSettings_w(window);
    if (HeirachyIsOpen) Heirachy_w(window);
}

void MainWindow::RunMenuBar(SEngine_Internal::Window* window){
    
    ImGui::Text("SEngine");
    if (window->BeginMenu("Windows")) {
        if (window->MenuItem("Inspector", NULL, &InspectorIsOpen)){
            
        }
        if (window->MenuItem("Project", NULL, &ProjectIsOpen)){
            
        }
        if (window->MenuItem("EditorSettings", NULL, &EditorSettingsIsOpen)){
            
        }
        if (window->MenuItem("Heirachy", NULL, &HeirachyIsOpen)){
            
        }
        window->EndMenu();
    }
    
    if (window->BeginMenu("Creat Entity")) {
        
        if (window->MenuItem("Rectangle", NULL, NULL)){
            SEngine::Entity(SEngine::Mesh::mesh_quad, SEngine::Transform(), mat, "hello quad");
        }
        if (window->MenuItem("Tirangle", NULL, NULL)){
            SEngine::Entity(SEngine::Mesh::mesh_triangle, SEngine::Transform(), mat, "hello tri");
        }
        if (window->MenuItem("Empty", NULL, NULL)){
            SEngine::Entity("hello empty");
        }
        
        window->EndMenu();
        
    }
}
void MainWindow::Project_w(SEngine_Internal::Window* window){
    window->Begin("project", &ProjectIsOpen);
    ImGui::Text("this is a file");
    window->End();
}
void MainWindow::Inspector_w(SEngine_Internal::Window* window){
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
void MainWindow::Heirachy_w(SEngine_Internal::Window* window){
    window->Begin("Heiracht", &HeirachyIsOpen);
    if (ImGui::CollapsingHeader("Scene")) {
        ImGui::Text("GameObject");
    }
    window->End();
}
void MainWindow::EditorSettings_w(SEngine_Internal::Window* window){
    window->Begin("Editor Settings", &EditorSettingsIsOpen);
    ImGui::Text("color");
    window->End();
}

MainWindow::MainWindow(){}



}



