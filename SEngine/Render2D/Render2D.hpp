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

namespace SEngine {

class Render2D{
public:
    Shader shader =
    Shader("/Users/chenyuxuansam/dev/SEngine/SEngine/shaders/OneColor.vs",
           "/Users/chenyuxuansam/dev/SEngine/SEngine/shaders/OneColor.fs");
    Render2D();
    void DrawTri(float vertices[9]);
    void DrawQuad();
    void DrawQuad(float vertices[12]);
    void Clear(){
        glClearColor(0.5, 0.5, 0.5, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
    }
private:
    
    
};

}



#endif /* Render2D_hpp */
