//
//  SandBoxApp.cpp
//  SEngine
//
//  Created by henry on 2021/8/20.
//

#include "SandBoxApp.hpp"

float vertices_tri[] = {
    0.0,  0.9, 0.0,
    -0.5,  0.5, 0.0,
     0.5, 0.5, 0.0,
};
//void SetUniformForTri(Shader* shader){
//    shader->setVec3("color", 0.2, 0.5, 0.3);
//}
//void SetUniformForQuad(Shader* shader){
//    shader->setVec3("color", 0.5, 0.4, 0.3);
//}

SandBox::SandBox(){
    
    SandBox::logger = new Logger("SandBox");
    logger->GetLogger()->info("app initialized");
    scrHeight = 800;
    scrWidth = 1300;
    
//    Material matForQuad = Material(SetUniformForTri);
//    Material matForTri = Material(SetUniformForQuad);
    
//    Entity(Mesh::mesh_quad, Transform(), matForQuad, "quad");
//    Entity(Mesh(vertices_tri, nullptr, triangle), Transform(), matForTri, "tri");
    
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

