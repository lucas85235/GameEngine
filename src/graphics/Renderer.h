#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"
#include "Camera.h"
#include "Mesh.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void ClearScreen();
    void RenderMesh(Mesh& mesh, Camera& camera, float aspectRatio);

private:
    Shader* shader;
};

#endif
