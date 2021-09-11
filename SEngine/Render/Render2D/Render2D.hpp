//
//  Render2D.hpp
//  SEngine_Internal
//
//  Created by Sam cyx on 2021/8/28.
//

#ifndef Render2D_hpp
#define Render2D_hpp

#include <stdio.h>
#include "Material.hpp"
#include "Shader.h"

#define MAX_NUM_OF_VERTICES_PER_SHADER 2187

namespace SEngine_Internal {

class Render2D{
public:
    static void CreatTri(float vertices[9], SEngine::Material material);
    static void CreatQuad(float vertices[12], SEngine::Material material);
    static void DrawAll();
    static void Clear(float r, float g, float b, float a){
        glClearColor(r, g, b, a);
        glClear(GL_COLOR_BUFFER_BIT);
    }
private:
    static SEngine::Material materials[MAX_NUM_OF_MATERIAL];
    static float vertices[MAX_NUM_OF_MATERIAL][MAX_NUM_OF_VERTICES_PER_SHADER];
    static unsigned int count;
};

}



#endif /* Render2D_hpp */
