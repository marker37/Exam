//Створіть клас Vector, що представляє вектор в тривимірному просторі.
//Реалізуйте перевантаження операторів + , -, * (скалярний добуток), == та !=
//для цього класу.Наведіть приклади використання цих операторів.


#include <iostream>
using namespace std;

class Vector {
private:
    double x, y, z;

public:
   
    Vector() : x(0), y(0), z(0) {}

    
    Vector(double x, double y, double z) : x(x), y(y), z(z) {}

    
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

   
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    

    double operator*(const Vector& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    

    bool operator==(const Vector& other) const {
        return x == other.x && y == other.y && z == other.z;
    }

    

    bool operator!=(const Vector& other) const {
        return !(*this == other);
    }

   

    void print() const {
        cout << "(" << x << ", " << y << ", " << z << ")" << endl;
    }

};

void main() 
{
    Vector v1(1.0, 2.0, 3.0);
    Vector v2(4.0, 5.0, 6.0);

    

    Vector v3 = v1 + v2;
    cout << "v1 + v2 = ";
    v3.print();

    
    Vector v4 = v1 - v2;
    cout << "v1 - v2 = ";
    v4.print();

   
    double dotProduct = v1 * v2;
    cout << "v1 * v2 = " << dotProduct << endl;

    
    bool areEqual = (v1 == v2);
    cout << "v1 == v2: " << (areEqual ? "true" : "false") << endl;

    
    bool areNotEqual = (v1 != v2);
    cout << "v1 != v2: " << (areNotEqual ? "true" : "false") << endl;

   
}




