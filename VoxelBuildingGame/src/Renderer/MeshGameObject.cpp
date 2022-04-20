#include "Renderer/MeshGameObject.h"
#include <glad/glad.h>
#include <cstddef>

MeshGameObject::MeshGameObject() {

}
void MeshGameObject::uploadDataMeshToGPU() {
    if (vertices.size() == 0) {
        return;
    }

    m_vao.bind();
    //glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int),
        &indices[0], GL_STATIC_DRAW);

    // vertex positions
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
    // vertex normals
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
    // vertex texture coords
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

    m_vao.unbind();
    //glBindVertexArray(0);
}
void MeshGameObject::setupGL() {
    m_vao.setupGL();
    //glGenVertexArrays(1, &VAO);//Vertex Array Object

    glGenBuffers(1, &VBO);//Vertex Buffer Object
    glGenBuffers(1, &EBO);//element Buffer Object
}
void MeshGameObject::render() {
    // draw mesh
    m_vao.bind();
    //glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    m_vao.unbind();
    //glBindVertexArray(0);
}