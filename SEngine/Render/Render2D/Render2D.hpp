//
//  Render2D.hpp
//  SEngine
//
//  Created by Sam cyx on 2021/8/28.
//

#ifndef Render2D_hpp
#define Render2D_hpp

#include <stdio.h>
#include "Shader.h"
#include "Vectors.hpp"
#define MAX_NUM_OF_VERTICES_PER_SHADER 2187
#define MAX_NUM_OF_SHADER 5
namespace SEngine {

typedef void (* SetUniformFunc)(Shader* shader);
class Render2D{
public:
    static GLuint CreatTri(float vertices[9], Shader shader, unsigned int shaderID);
    static void SetUniformFuncFor(unsigned int shaderID, unsigned int verticesID, SetUniformFunc setUniformFor);
    static void DrawAllTri();
    static void Clear(){
        glClearColor(0.5, 0.5, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
private:
    static float vertices[MAX_NUM_OF_SHADER][MAX_NUM_OF_VERTICES_PER_SHADER];
    static Shader shaders[MAX_NUM_OF_SHADER];
    static ::SEngine::SetUniformFunc funcs[MAX_NUM_OF_SHADER][MAX_NUM_OF_VERTICES_PER_SHADER/3];
    static unsigned int count;
    static bool inited;
};


}



#endif /* Render2D_hpp */
