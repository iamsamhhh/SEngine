//
//  Material.hpp
//  SEngine_Internal
//
//  Created by Sam cyx on 2021/9/7.
//

#ifndef Material_hpp
#define Material_hpp

#include "Shader.h"

#define MAX_NUM_OF_MATERIAL 4

namespace SEngine {
typedef void (* SetUniformFunc)(Shader* shader);

class Material{
public:
    Material(const char* vertexShaderPath, const char* fragmentShaderPath, SetUniformFunc func);
    Material(Shader shader, SetUniformFunc func);
    Material(){}
    void Use();
    Shader shader;
    SetUniformFunc func;
    unsigned int ID;
    
private:
    static GLuint count;
};

}

#endif /* Material_SEngine::SEngine::Material:MaterialSEngine::MaterialSEngine::Material*/
