//
//  SandBoxApp.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "SandBoxApp.hpp"


void SetUniformFori(Shader* shader){
    shader->setVec3("position", 0, 0, 0);
    shader->setVec3("color", 0.3, 0.7, 0.2);
}
void SetUniformForq(Shader* shader){
    shader->setVec3("position", 0, 0, 0);
    shader->setVec3("color", 0.2, 0.5, 0.3);
}
void SetUniformForw(Shader* shader){
    shader->setVec3("position", 0, -0.2, 0);
    shader->setVec3("color", 0.5, 0.4, 0.3);
}
float vertices_q[] = {
    0.5, -0.5, 0.0,
    -0.5,  0.5, 0.0,
    -0.5, -0.5, 0.5
};
float vertices_i[] = {
    0.5,  0.5, 0.0,
    -0.5,  0.5, 0.0,
     0.5, -0.5, 0.0,
};
float vertices_w[] = {
    0.0,  0.9, 0.0,
    -0.5,  0.5, 0.0,
     0.5, 0.5, 0.0,
};
unsigned int i, q, w;
SEngine::SandBox::SandBox(){
    
    SandBox::logger = new SEngine::Logger("SandBox");
    logger->GetLogger()->info("app initialized");
    scrHeight = 800;
    scrWidth = 1300;
    Shader shader(oneColor_vertexShaderPath, oneColor_fragmentShaderPath);
    
    q = Render2D::CreatTri(vertices_q, shader, 0);
    w = Render2D::CreatTri(vertices_w, shader, 0);
    i = Render2D::CreatTri(vertices_i, shader, 0);
    
}

SEngine::SandBox::~SandBox()
{
    logger->GetLogger()->info("bye");
}


void SEngine::SandBox::Run(){
    Render2D::SetUniformFuncFor(0, i, SetUniformFori);
    Render2D::SetUniformFuncFor(0, q, SetUniformForq);
    Render2D::SetUniformFuncFor(0, w, SetUniformForw);
}

SEngine::Application* SEngine::CreatApplication(){
    return new SandBox();
}

