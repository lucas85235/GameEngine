#include "utils/Utils.h"
#include <iostream>
#include <fstream>

filesystem::path Utils::GetProjectRoot() {
    filesystem::path currentPath = filesystem::current_path();

    while (currentPath.has_parent_path()) {
        if (filesystem::exists(currentPath / "shaders")) {
            return currentPath;
        }
        currentPath = currentPath.parent_path();
    }

    cerr << "Error: can't find project root path!" << endl;
    return filesystem::current_path();
}

string Utils::ReadFile(const char* filePath) {
    ifstream file;
    stringstream content;

    auto root = GetProjectRoot();
    file.open(root / filePath);
    if (!file.is_open()) {
        cerr << "ERROR::SHADER::FILE_NOT_FOUND: " << filePath << endl;
        return "";
    }
    content << file.rdbuf();
    file.close();

    return content.str();
}
