//
//  Material.cpp
//  SEngine_Internal
//
//  Created by Sam cyx on 2021/9/7.
//

#include "Material.hpp"

namespace SEngine_Internal {
void WhiteColor(SEngine::Shader* shader){
    shader->setVec3("color", 1, 1, 1);
}
}

namespace SEngine{
GLuint Material::count = 0;
Shader Material::defaultShader = Shader();
SetUniformFunc Material::defaultFunc = SEngine_Internal::WhiteColor;
Material Material::defaultMat = Material();
bool Material::defaultsGenerated = false;

Material::Material(const char* vertexShaderPath, const char* fragmentShaderPath, SetUniformFunc func) : shader(vertexShaderPath, fragmentShaderPath), ID(count), func(func)
{
    if (count != MAX_NUM_OF_MATERIAL - 1) {
        count++;
    }
}

Material::Material(Shader shader, SetUniformFunc func) : shader(shader), func(func)
{
    if (count != MAX_NUM_OF_MATERIAL - 1) {
        count++;
    }
}

Material::Material(SEngine::SetUniformFunc func) : shader(Material::defaultShader), func(func)
{
    printf("hello\n");
    if (count != MAX_NUM_OF_MATERIAL - 1) {
        count++;
    }
}

Material::Material() : shader(), func()
{
    
}


void Material::Use(){
    shader.use();
    if (func != nullptr) func(&shader);
    
}

void Material::GenerateDefaults() {
    if (Material::defaultsGenerated) return;
    
    Material::defaultShader = Shader(DEFAULT_SHADER_PATH_V, DEFAULT_SHADER_PATH_F);
    Material::defaultsGenerated = true;
    Material::defaultMat = Material(defaultShader, defaultFunc);
}

}
