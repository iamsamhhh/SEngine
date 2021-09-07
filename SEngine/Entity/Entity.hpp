//
//  Entity.hpp
//  SEngine
//
//  Created by Sam cyx on 2021/9/5.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "Core.h"
#include "Render2D.hpp"

#define MAX_NUM_OF_VERTEX_IN_ONE_MESH 123
namespace SEngine{
class Transform{
public:
    Transform();
    Vector3 position;
    Vector3 scale;
    Vector3 rotation;
private:
   
};


enum EMeshType{
    quad,
    triangle,
    custom
};

class Mesh{
public:
    Mesh(float *vertexData, GLuint *indices, EMeshType type);
    static Mesh mesh_triangle;
    static Mesh mesh_quad;
    EMeshType meshType;
    float vertexData[MAX_NUM_OF_VERTEX_IN_ONE_MESH];
    GLuint indices[MAX_NUM_OF_VERTEX_IN_ONE_MESH + 2];
private:
};

class MeshRenderer{
public:
    MeshRenderer(Mesh mesh, Material mat);
    
private:
    Material p_material;
};



class Entity{
public:
    Entity(Mesh mesh, Transform transform, Material material, const char* name);
    MeshRenderer renderer;
    Transform transform;
    Mesh mesh;
    Material material;
    const char* name;
};
}

#endif /* Entity_hpp */
