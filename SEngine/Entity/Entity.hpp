//
//  Entity.hpp
//  SEngine_Internal
//
//  Created by Sam cyx on 2021/9/5.
//

#ifndef Entity_hpp
#define Entity_hpp

#include "Render2D.hpp"

#define MAX_NUM_OF_VERTEX_IN_ONE_MESH 123
namespace SEngine{
class Transform{
public:
    Transform();
private:
   
};


enum EMeshType{
    empty,
    quad,
    triangle,
    custom
};

class Mesh{
public:
    Mesh(float *vertexData, GLuint *indices, EMeshType type);
    Mesh();
    static Mesh mesh_triangle;
    static Mesh mesh_quad;
    EMeshType meshType;
    float vertexData[MAX_NUM_OF_VERTEX_IN_ONE_MESH];
    GLuint indices[MAX_NUM_OF_VERTEX_IN_ONE_MESH + 2];
private:
};

class MeshRenderer{
public:
    MeshRenderer(Mesh mesh, SEngine::Material mat);
    MeshRenderer();
private:
    SEngine::Material p_material;
    Mesh p_mesh;
};



class Entity{
public:
    Entity(const char* name);
    Entity(Mesh mesh, Transform transform, SEngine::Material material, const char* name);
    MeshRenderer renderer;
    Transform transform;
    Mesh mesh;
    SEngine::Material material;
    const char* name;
};
}

#endif /* Entity_hpp */
