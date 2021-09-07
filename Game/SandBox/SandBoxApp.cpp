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

SEngine::SandBox::SandBox(){
    
    SandBox::logger = new SEngine::Logger("SandBox");
    logger->GetLogger()->info("app initialized");
    scrHeight = 800;
    scrWidth = 1300;
    Shader oneColor_shader(oneColor_vertexShaderPath, oneColor_fragmentShaderPath);
    Material matForQuad = Material(oneColor_shader, SetUniformForTri);
    Entity quad = Entity(Mesh::mesh_quad, Transform(), matForQuad, "quad");
    
    Material matForTri = Material(oneColor_shader, SetUniformForQuad);
    Entity tri = Entity(Mesh::mesh_triangle, Transform(), matForTri, "tri");
//    Render2D::CreatTri(vertices_tri, matForTri);
//    Render2D::CreatQuad(vertices_quad, matForQuad);
    
}

SEngine::SandBox::~SandBox()
{
    logger->GetLogger()->info("bye");
}


void SEngine::SandBox::Run(){
}

SEngine::Application* SEngine::CreatApplication(){
    return new SandBox();
}

