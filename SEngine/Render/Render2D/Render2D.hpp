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

namespace SEngine {

typedef void (* SetUniformFunc)(Shader* shader);
class Render2D{
public:
    static GLuint CreatTri(float vertices[9], Shader shader, unsigned int shaderID);
    static void SetUniformFuncFor(unsigned int ID, SetUniformFunc setUniformFor);
    static void DrawAllTri();
    static void Clear(){
        glClearColor(0.5, 0.5, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
private:
    static float vertices[3][2187];
    static Shader shaders[3];
    static ::SEngine::SetUniformFunc funcs[3][2187/3];
    static unsigned int count;
    static bool inited;
};


}



#endif /* Render2D_hpp */
