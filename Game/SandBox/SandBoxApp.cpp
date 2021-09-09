//
//  SandBoxApp.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "SandBoxApp.hpp"


void SetUniformForTri(Shader* shader){
//    shader->setVec3("position", 0, 0, 0);
    shader->setVec3("color", 0.2, 0.5, 0.3);
}
void SetUniformForQuad(Shader* shader){
//    shader->setVec3("position", 0, 0, 0);
    shader->setVec3("color", 0.5, 0.4, 0.3);
}
SandBox::SandBox(){
    
    SandBox::logger = new Logger("SandBox");
    logger->GetLogger()->info("app initialized");
    scrHeight = 800;
    scrWidth = 1300;
    Shader oneColor_shader(oneColor_vertexShaderPath, oneColor_fragmentShaderPath);
    SEngine::Material matForQuad = SEngine::Material(oneColor_shader, SetUniformForTri);
    Entity quad = Entity(Mesh::mesh_quad, Transform(), matForQuad, "quad");
    SEngine::Material matForTri = SEngine::Material(oneColor_shader, SetUniformForQuad);
    Entity tri = Entity(Mesh::mesh_triangle, Transform(), matForTri, "tri");
    
}

SandBox::~SandBox()
{
    logger->GetLogger()->info("bye");
}


void SandBox::Run(){
}

Application* SEngine::CreatApplication(){
    return new SandBox();
}

