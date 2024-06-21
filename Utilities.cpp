#include "Utilities.h"
#include <fstream>
#include <stdexcept>

namespace Utilities 
{
    bool fileExists(const std::string& filename) 
    {
        std::ifstream file(filename);
        return file.is_open();
    }


    std::string readFile(const std::string& filename) 
    {
        std::ifstream file(filename);
        if (!file.is_open()) 
        {
            throw std::runtime_error("Error: File not found");
        }


        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        return content;
    }


    void writeFile(const std::string& filename, const std::string& content) 
    {
        std::ofstream file(filename);
        if (!file.is_open()) 
        {
            throw std::runtime_error("Error: Could not open file for writing");
        }

        file << content;
    }

}