//
//  Render2D.cpp
//  SEngine_Internal
//
//  Created by Sam cyx on 2021/8/28.
//

#include "Render2D.hpp"

namespace SEngine_Internal {

float Render2D::vertices[MAX_NUM_OF_MATERIAL][MAX_NUM_OF_VERTICES_PER_SHADER]{};
unsigned int Render2D::count = 0;
SEngine::Material Render2D::materials[MAX_NUM_OF_MATERIAL]{};


GLuint matCount = 0;

void Render2D::CreatTri(float vertices[9], SEngine::Material material){
    for (int i = 0; i < matCount; i++) {
        if (materials[i].ID == material.ID) {
            for (int j = 0; j < 9; j++) {
                Render2D::vertices[i][count + j] = vertices[j];
                std::cout << "count + j:" << count + j << "   j:" << j << std::endl;
            }
            count += 9;
            std::cout << count << "after" << std::endl;
        }
    }
    materials[matCount] = material;
    for (int j = 0; j < 9; j++) {
        Render2D::vertices[matCount][count + j] = vertices[j];
        std::cout << "count + j:" << count + j << "   j:" << j << std::endl;
    }
    count += 9;
    matCount++;
    std::cout << count << "after" << std::endl;
}

void Render2D::DrawAll(){
    for (int i = 0; i < MAX_NUM_OF_MATERIAL; i++) {
        GLuint VAO, VBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[i]), Render2D::vertices[i], GL_STATIC_DRAW);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        glBindVertexArray(VAO);
        for (int j = 0; j < MAX_NUM_OF_VERTICES_PER_SHADER; j+=3) {
            materials[i].Use();
            glDrawArrays(GL_TRIANGLES, j, 3);
        }
    }
}

void Render2D::CreatQuad(float vertices[12], SEngine::Material material) { 
    float ver1[9]{
        vertices[3], vertices[4], vertices[5],
        vertices[0], vertices[1], vertices[2],
        vertices[6], vertices[7], vertices[8]
    };
    
    float ver2[9]{
        vertices[0], vertices[1], vertices[2],
        vertices[9], vertices[10], vertices[11],
        vertices[6], vertices[7], vertices[8]
    };
    CreatTri(ver1, material);
    CreatTri(ver2, material);
}


}
