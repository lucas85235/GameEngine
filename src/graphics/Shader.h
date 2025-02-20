#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <filesystem>
#include <glad/glad.h>

using namespace std;

class Shader {
public:
    GLuint ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    void Use();
    void SetUniform1f(const string& name, float value);
    void SetUniform3f(const string& name, float x, float y, float z);
    void SetUniformMatrix4fv(const string& name, const float* matrix);

private:
    GLuint CompileShader(const char* source, GLenum type);
    string ReadFile(const char* filePath);
    void CheckCompileErrors(GLuint shader, string type);
    filesystem::path GetProjectRoot();
};

#endif
