#include <iostream>
#include <fstream>
#include <stdexcept>
#include <string>

using namespace std;

void readNumberFromFile(const string& filename)
{

    ifstream file(filename);

    if (!file.is_open()) {
        throw runtime_error("Error: File not found");
    }


    int number;
    file >> number;


    if (file.fail() || !file.eof()) {
        throw runtime_error("Error: Invalid number in file");
    }


    cout << "The number read from the file is: " << number << endl;
}

void main() 
{

    string filename;


    cout << "Enter the filename: ";
    cin >> filename;


    try 
    {
        readNumberFromFile(filename);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

   
}