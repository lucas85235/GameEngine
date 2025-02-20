#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>

// Constructor: Load, compile, and link shaders
Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    string vertexCode = ReadFile(vertexPath);
    string fragmentCode = ReadFile(fragmentPath);

    GLuint vertexShader = CompileShader(vertexCode.c_str(), GL_VERTEX_SHADER);
    GLuint fragmentShader = CompileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

    // Create the shader program
    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);
    glLinkProgram(ID);
    CheckCompileErrors(ID, "PROGRAM");

    // Delete the shaders after linking
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

// Destructor: Delete shader program
Shader::~Shader() {
    glDeleteProgram(ID);
}

// Activate the shader program
void Shader::Use() {
    glUseProgram(ID);
}

// Utility function to read shader file
string Shader::ReadFile(const char* filePath) {
    ifstream file;
    stringstream content;
    
    auto root = GetProjectRoot();
    cout << "-----> " << root << endl;
    cout << "-----> " << filePath << endl;
    cout << "-----> " << root / filePath << endl;
    file.open(filePath);
    if (!file.is_open()) {
        cerr << "ERROR::SHADER::FILE_NOT_FOUND: " << filePath << endl;
        return "";
    }
    content << file.rdbuf();
    file.close();
    
    return content.str();
}

// Compile shader function
GLuint Shader::CompileShader(const char* source, GLenum type) {
    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &source, nullptr);
    glCompileShader(shader);
    CheckCompileErrors(shader, (type == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT");
    return shader;
}

// Check for compilation errors
void Shader::CheckCompileErrors(GLuint shader, string type) {
    GLint success;
    GLchar infoLog[1024];

    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            cerr << "ERROR::SHADER::COMPILATION_ERROR of type: " << type << "\n" << infoLog << endl;
        }
    } else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            cerr << "ERROR::SHADER::PROGRAM_LINKING_ERROR\n" << infoLog << endl;
        }
    }
}

// Set Uniforms
void Shader::SetUniform1f(const string& name, float value) {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetUniform3f(const string& name, float x, float y, float z) {
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}

void Shader::SetUniformMatrix4fv(const string& name, const float* matrix) {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, matrix);
}

filesystem::path Shader::GetProjectRoot() {
    filesystem::path currentPath = filesystem::current_path();

    while (currentPath.has_parent_path()) {
        if (filesystem::exists(currentPath / "shaders")) { // Verifica se "shaders" existe na raiz do projeto
            return currentPath;
        }
        currentPath = currentPath.parent_path(); // Sobe um nível
    }

    cerr << "Error: can't find project root path!" << endl;
    return filesystem::current_path();
}
