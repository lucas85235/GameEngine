
#include "ModelLoader.h"
#include <tiny_obj_loader.h>
#include <iostream>
#include <string>

Mesh* ModelLoader::LoadOBJ(const std::string& path) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    auto root = GetProjectRoot() / path;
    std::string parentString = root.parent_path().c_str();
    std::string parentPath = parentString + "/";

    bool success = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, root.c_str(), parentPath.c_str());

    if (!err.empty()) {
        std::cerr << "ERROR: " << err << std::endl;
    }
 
    if (!success) {
        std::cerr << "Failed to load OBJ file: " << root << std::endl;
        return nullptr;
    }
 
    std::vector<Vertex> vertices;

    // Itera sobre as formas e extrai os dados de vértices
    for (const auto& shape : shapes) {
        for (const auto& index : shape.mesh.indices) {
            Vertex vertex;
 
            // Posição
            vertex.Position = {
                attrib.vertices[3 * index.vertex_index + 0],
                attrib.vertices[3 * index.vertex_index + 1],
                attrib.vertices[3 * index.vertex_index + 2]
            };
 
            // Normais (se existirem)
            if (!attrib.normals.empty()) {
                vertex.Normal = {
                    attrib.normals[3 * index.normal_index + 0],
                    attrib.normals[3 * index.normal_index + 1],
                    attrib.normals[3 * index.normal_index + 2]
                };
            } else {
                vertex.Normal = {0.0f, 0.0f, 1.0f}; // Normal padrão
            }
 
            // UVs (se existirem)
            if (!attrib.texcoords.empty()) {
                vertex.TexCoords = {
                    attrib.texcoords[2 * index.texcoord_index + 0],
                    attrib.texcoords[2 * index.texcoord_index + 1]
                };
            } else {
                vertex.TexCoords = {0.0f, 0.0f}; // UV padrão
            }
 
            // Cor padrão (rosa)
            vertex.Color = {1.0f, 0.0f, 1.0f};
 
            // Se houver materiais, use a cor difusa do material
            if (!materials.empty() && index.vertex_index < shape.mesh.material_ids.size()) {
                int matID = shape.mesh.material_ids[index.vertex_index];
                if (matID >= 0 && matID < materials.size()) {
                    vertex.Color = {
                        materials[matID].diffuse[0],
                        materials[matID].diffuse[1],
                        materials[matID].diffuse[2]
                    };
                }
            }
 
            vertices.push_back(vertex);
        }
    }

    std::cout << "✅ Successfully loaded OBJ file: " << path << " with " << vertices.size() << " vertices." << std::endl;
    return new Mesh(vertices);
}

std::filesystem::path ModelLoader::GetProjectRoot() {
    std::filesystem::path currentPath = std::filesystem::current_path();

    while (currentPath.has_parent_path()) {
        if (std::filesystem::exists(currentPath / "assets")) {
            return currentPath;
        }
        currentPath = currentPath.parent_path();
    }

    std::cerr << "Error: can't find project root path!" << std::endl;
    return std::filesystem::current_path();
}
