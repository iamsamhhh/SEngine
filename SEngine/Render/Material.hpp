//
//  Material.hpp
//  SEngine_Internal
//
//  Created by Sam cyx on 2021/9/7.
//

#ifndef Material_hpp
#define Material_hpp

#include "Shader.h"

#define MAX_NUM_OF_MATERIAL 50
#define DEFAULT_SHADER_PATH_V "/Users/samcyx/dev/SEngine/SEngine/shaders/OneColor.vs"
#define DEFAULT_SHADER_PATH_F "/Users/samcyx/dev/SEngine/SEngine/shaders/OneColor.fs"

namespace SEngine_Internal {
void WhiteColor(SEngine::Shader* shader);
}

namespace SEngine {
typedef void (* SetUniformFunc)(Shader* shader);

class Material{
public:
    Material(const char* vertexShaderPath, const char* fragmentShaderPath, SetUniformFunc func);
    Material(Shader shader, SetUniformFunc func);
    Material(SetUniformFunc func);
    Material();
    void Use();
    static void GenerateDefaults();
    
    Shader shader;
    SetUniformFunc func;
    static Material defaultMat;
    unsigned int ID;
    static GLuint count;
private:
    
    static bool defaultsGenerated;
    static Shader defaultShader;
    static SetUniformFunc defaultFunc;
};

}

#endif /* Material_SEngine::SEngine::Material:MaterialSEngine::MaterialSEngine::Material*/
