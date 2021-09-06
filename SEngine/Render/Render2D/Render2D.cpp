//
//  Render2D.cpp
//  SEngine
//
//  Created by Sam cyx on 2021/8/28.
//

#include "Render2D.hpp"

namespace SEngine {

bool Render2D::inited = false;
SetUniformFunc Render2D::funcs[3][2187/3]{};
float Render2D::vertices[3][2187]{};
Shader Render2D::shaders[3]{};
unsigned int Render2D::count = 0;
//unsigned int shaderID = 0;

GLuint Render2D::CreatTri(float vertices[9], Shader shader, unsigned int shaderID){
    for (int i = 0; i < 9; i++) {
        Render2D::vertices[shaderID][count + i] = vertices[i];
        std::cout << "count + i:" << count + i << "   i:" << i << std::endl;
    }
    count += 9;
    std::cout << count << "after" << std::endl;
    Render2D::shaders[shaderID] = shader;
    return count/9-1;
}



void Render2D::SetUniformFuncFor(unsigned int ID, SetUniformFunc setUniformFor){
    funcs[0][ID] = setUniformFor;
}

void Render2D::DrawAllTri(){
    for (int i = 0; i < 3; i++) {
        GLuint VAO, VBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[i]), Render2D::vertices[i], GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindVertexArray(VAO);
        for (int j = 0; j < 2187; j+=3) {
            shaders[i].use();
            
            if (funcs[i][j/3] != nullptr)
                funcs[i][j/3](&shaders[i]);
            
            glDrawArrays(GL_TRIANGLES, j, 3);
        }
    }
}

}
