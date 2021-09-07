//
//  Material.cpp
//  SEngine
//
//  Created by Sam cyx on 2021/9/7.
//

#include "Material.hpp"
namespace SEngine{
GLuint Material::count = 0;
Material::Material(const char* vertexShaderPath, const char* fragmentShaderPath, SetUniformFunc func) : shader(vertexShaderPath, fragmentShaderPath), ID(count), func(func)
{
    if (count != MAX_NUM_OF_MATERIAL - 1) {
        count++;
    }
}

void Material::Use(){
    shader.use();
    if (func != nullptr) func(&shader);
    
}

Material::Material(Shader shader, SEngine::SetUniformFunc func) : shader(shader), func(func)
{ 
    if (count != MAX_NUM_OF_MATERIAL - 1) {
        count++;
    };
}

}
