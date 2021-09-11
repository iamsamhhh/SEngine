//
//  Entity.cpp
//  SEngine_Internal
//
//  Created by Sam cyx on 2021/9/5.
//

#include "Entity.hpp"

namespace SEngine {
float vertices_tri[] = {
    0.0,  0.5, 0.0,
    -0.5, -0.5, 0.0,
     0.5, -0.5, 0.0,
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
    Mesh::meshType = type;
    if (type == empty) return;
    for (int i = 0; i < MAX_NUM_OF_VERTEX_IN_ONE_MESH; i++) {
        if (vertexData[i] != EOF) {
            Mesh::vertexData[i] = vertexData[i];
        }
        else{
            break;
        }
    }
    if (type != custom) return;
    for (int i = 0; i < MAX_NUM_OF_VERTEX_IN_ONE_MESH; i++) {
        if (indices[i] != EOF) {
            Mesh::indices[i] = indices[i];
        }
        else{
            break;
        }
    }
}


Mesh::Mesh() : meshType(empty)
{
    
}


MeshRenderer::MeshRenderer(Mesh mesh, SEngine::Material material) : p_material(material), p_mesh(mesh) {
    switch (mesh.meshType) {
        case triangle:
            SEngine_Internal::Render2D::CreatTri(mesh.vertexData, p_material);
            break;
        case quad:
            SEngine_Internal::Render2D::CreatQuad(mesh.vertexData, p_material);
            break;
        default:
            break;
    };
}

MeshRenderer::MeshRenderer() : p_material(), p_mesh()
{
    
}

Entity::Entity(Mesh mesh, Transform transform, SEngine::Material material, const char* name) : mesh(mesh), transform(transform), name(name), material(material), renderer(mesh, material)
{
    
}

Entity::Entity(const char* name) : mesh(), renderer(), transform(), name(name){}
}


