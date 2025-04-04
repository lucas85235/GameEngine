#ifndef MESH_H
#define MESH_H
 
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
 
struct Vertex {
    glm::vec3 Position;
    glm::vec3 Normal;
    glm::vec2 TexCoords;
    glm::vec3 Color;
};
 
class Mesh {
public:
    Mesh(const std::vector<Vertex>& vertices);
    ~Mesh();
 
    void Draw();
 
private:
    GLuint VAO, VBO;
    std::vector<Vertex> vertices;
 
    void SetupMesh();
};
 
#endif