#version 410 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aNormal;
layout (location = 2) in vec2 aTexCoords;
layout (location = 3) in vec3 aColor;
 
out vec3 vertexColor;
out vec2 texCoord;
out vec3 normal;
 
uniform mat4 view;
uniform mat4 projection;
 
void main() {
    gl_Position = projection * view * vec4(aPos, 1.0);
    vertexColor = aColor;
    texCoord = aTexCoords;
    normal = aNormal;
}
 