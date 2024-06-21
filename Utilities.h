#pragma once
#include <string>

namespace Utilities 
{
    bool fileExists(const std::string& filename);
    std::string readFile(const std::string& filename);

    void writeFile(const std::string& filename, const std::string& content);
}



