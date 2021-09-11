//
//  Window.hpp
//  SEngine_Internal
//
//  Created by henry on 2021/8/22.
//

#ifndef Window_hpp
#define Window_hpp

#include "EntryPoint.hpp"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "UI.hpp"
#include "Entity.hpp"


namespace SEngine_Internal{

// a window class manage all things about windows
class Window{
public:
    //initialize the window hints
    static bool InitWindow();
    
    Window(unsigned int width, unsigned int height, const char* title);
    ~Window();
    
    
    void SetToCurrent();
    void SetUpUI();
    static bool SetUpRender(){
        if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
            return false;
        }
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        return true;
    }
    bool WindowShouldClose(){
        return glfwWindowShouldClose(ID);
    }
    void Begin(const char* name, bool* isOpen);
    void End();
    void FrameStart();
    void MenuBarStart();
    bool BeginMenu(const char* name);
    bool MenuItem(const char* name, const char* shortCut, bool* selected);
    void EndMenu();
    void MenuBarEnd();
    void FrameEnd();
    GLFWwindow* GetID(){
        return ID;
    }
private:
    GLFWwindow* ID;
    UI* ui;
    static bool init;
};

class MainWindow {
public:
    static void SetUpMainWindow();
    static void Update(){
        window->FrameStart();
        
        RunUI(window);
        window->MenuBarStart();
        RunMenuBar(window);
        window->MenuBarEnd();
        
        window->FrameEnd();
    }
    static bool WindowShouldClose(){
        return window->WindowShouldClose();
    }
    static GLFWwindow* GetID(){
        return window->GetID();
    }
    static void ShutDown(){
        delete window;
    }
private:
    static SEngine::Material mat;
    static bool InspectorIsOpen, ProjectIsOpen, EditorSettingsIsOpen, HeirachyIsOpen;
    static char buffer[30];
    static void gray(SEngine::Shader* shader);
    static void RunUI(SEngine_Internal::Window* window);
    static void Project_w(SEngine_Internal::Window* window);
    static void Inspector_w(SEngine_Internal::Window* window);
    static void EditorSettings_w(SEngine_Internal::Window* window);
    static void Heirachy_w(SEngine_Internal::Window* window);
    static void RunMenuBar(SEngine_Internal::Window* window);

    MainWindow();
    
    static Window* window;
};


}
#endif /* Window_hpp */
