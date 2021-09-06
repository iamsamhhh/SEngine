//
//  Entity.cpp
//  SEngine
//
//  Created by Sam cyx on 2021/9/5.
//

#include "Entity.hpp"

namespace SEngine {

Transform::Transform(Vector3 position){
    
}
Mesh::Mesh(Vector3* vertexData, unsigned int* indices){
    
}
Material::Material(const char* vertexShaderPath, const char* fragmentShaderPath, SetUniformFunc func) : shader(vertexShaderPath, fragmentShaderPath){
    Material::func = func;
}
Entity::Entity(Material material, Mesh mesh, Transform transform) : material(material), mesh(mesh), transform(transform){
    
}

}
