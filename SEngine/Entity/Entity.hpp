//
//  Entity.hpp
//  SEngine
//
//  Created by Sam cyx on 2021/9/5.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "Core.h"

#define MAX_NUM_OF_VERTEX_IN_ONE_MESH 64
namespace SEngine{
class Transform{
public:
    Transform(Vector3 position);
    Vector3 position;
    Vector3 scale;
    Vector3 rotation;
private:
   
};
class Mesh{
public:
    Mesh(Vector3* vertexData, unsigned int* indices);
    Vector3 vertexData[MAX_NUM_OF_VERTEX_IN_ONE_MESH];
    unsigned int indices[MAX_NUM_OF_VERTEX_IN_ONE_MESH];
    unsigned int ID;
};

class Material{
public:
    Material(const char* vertexShaderPath, const char* fragmentShaderPath, SetUniformFunc func);
    Shader shader;
    SetUniformFunc func;
};

class Entity{
public:
    Entity(Material material, Mesh mesh, Transform transform);
    Transform transform;
    Material material;
    Mesh mesh;
};
}

#endif /* Entity_hpp */
