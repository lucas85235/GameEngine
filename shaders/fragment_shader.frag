#version 410 core

in vec3 vertexColor;
in vec2 texCoord;
in vec3 normal;

out vec4 FragColor;
 
void main() {
    FragColor = vec4(vertexColor, 1.0);
}
