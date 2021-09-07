//
//  Entity.cpp
//  SEngine
//
//  Created by Sam cyx on 2021/9/5.
//

#include "Entity.hpp"

namespace SEngine {
float vertices_tri[] = {
    0.0,  0.9, 0.0,
    -0.5,  0.5, 0.0,
     0.5, 0.5, 0.0,
};
float vertices_quad[]{
    -0.5f,  0.5f, 0.0f,
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f
};
Transform::Transform()
{
    
}

Mesh Mesh::mesh_quad = Mesh(vertices_quad, nullptr, quad);
Mesh Mesh::mesh_triangle = Mesh(vertices_tri, nullptr, triangle);
Mesh::Mesh(float* vertexData, GLuint* indices, EMeshType type)
{
    for (int i = 0; i < MAX_NUM_OF_VERTEX_IN_ONE_MESH; i++) {
        if (vertexData[i] != EOF) {
            Mesh::vertexData[i] = vertexData[i];
        }
        else{
            break;
        }
    }
    Mesh::meshType = type;
    if (type == quad || type == triangle) {
        return;
    }
    for (int i = 0; i < MAX_NUM_OF_VERTEX_IN_ONE_MESH; i++) {
        if (indices[i] != EOF) {
            Mesh::indices[i] = indices[i];
        }
        else{
            break;
        }
    }
    
    
}

MeshRenderer::MeshRenderer(Mesh mesh, Material material) : p_material(material) {
    switch (mesh.meshType) {
        case triangle:
            Render2D::CreatTri(mesh.vertexData, p_material);
            break;
        case quad:
            Render2D::CreatQuad(mesh.vertexData, p_material);
            break;
        default:
            break;
    };
}

Entity::Entity(Mesh mesh, Transform transform, Material material, const char* name) : mesh(mesh), transform(transform), name(name), material(material), renderer(mesh, material)
{
    
}
}


