#include <iostream>
#include <cmath> 
using namespace std;




const double PI = 3.14;

class Shape 
{
public:
    virtual double area() const = 0;
    virtual ~Shape() = default;
};



class Triangle : public Shape 
{
private:
    double base;
    double height;
public:

    Triangle(double base, double height)
        : base(base), height(height) {}


    double area() const override {
        return 0.5 * base * height;
    }
};



class Square : public Shape
{
private:
    double side;
public:

    Square(double side)
        : side(side) {}

    double area() const override 
    {
        return side * side;
    }

};



class Circle : public Shape 
{
private:

    double radius;
public:

    Circle(double radius)
        : radius(radius) {}

    double area() const override 
    {
        return PI * radius * radius;
    }
};




void main() {
   

    Shape* triangle = new Triangle(3.0, 4.0);
    Shape* square = new Square(5.0);
    Shape* circle = new Circle(2.0);

    

    cout << "Area of Triangle: " << triangle->area() << endl;
    cout << "Area of Square: " << square->area() << endl;
    cout << "Area of Circle: " << circle->area() << endl;

    

    delete triangle;
    delete square;
    delete circle;

   

}


