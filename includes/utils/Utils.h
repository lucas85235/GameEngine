#ifndef UTILS_H
#define UTILS_H

#include <filesystem>

using namespace std;

class Utils {
public:
    static filesystem::path GetProjectRoot();
    static string ReadFile(const char* filePath);
};

#endif //UTILS_H
