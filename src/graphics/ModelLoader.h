
#ifndef MODELLOADER_H
#define MODELLOADER_H
 
#include "Mesh.h"
#include <string>
#include <filesystem>
 
class ModelLoader {
public:
    static Mesh* LoadOBJ(const std::string& path);
    static std::filesystem::path GetProjectRoot();
};
 
#endif