#include <iostream>
#include "Utilities.h"

using namespace std;

int main()
{
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;


    try 
    {
        if (Utilities::fileExists(filename))
        {
            cout << "File exists. Reading content..." << endl;
            string content = Utilities::readFile(filename);

            cout << "File content:\n" << content << endl;
        }
        else 
        {
            cout << "File does not exist. Creating file and writing content..." << endl;

            string content = "This is a sample text written to the file.";
            Utilities::writeFile(filename, content);

            cout << "Content written to file." << endl;
        }
    }

    catch (const runtime_error& e) 
    {
        cout << e.what() << endl;
    }

    return 0;
}