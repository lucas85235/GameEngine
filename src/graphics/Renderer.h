#ifndef RENDERER_H
#define RENDERER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Shader.h"

class Renderer {
public:
    Renderer();
    ~Renderer();

    void ClearScreen();
    void RenderTriangle();

private:
    GLuint VAO, VBO;
    Shader* shader;
};

#endif
