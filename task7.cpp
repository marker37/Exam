#include <iostream>
#include <vector>
#include <string>
using namespace std;



class Vehicle {
protected:
    string make;
    string model;
    int year;

public:

    Vehicle(const string& make, const string& model, int year)
        : make(make), model(model), year(year) {}

    virtual void display() const 
    {
        cout << "Vehicle: " << year << " " << make << " " << model << endl;
    }

    virtual ~Vehicle() = default;
};



class Car : public Vehicle {
public:

    Car(const string& make, const string& model, int year)
        : Vehicle(make, model, year) {}


    void display() const override {
        cout << "Car: " << year << " " << make << " " << model << endl;
    }

};




class Truck : public Vehicle 
{
public:

    Truck(const string& make, const string& model, int year)
        : Vehicle(make, model, year) {}



    void display() const override {
        cout << "Truck: " << year << " " << make << " " << model << endl;
    }
};



class Fleet 
{
private:

    vector<Vehicle*> vehicles; 


public:
    


    void addVehicle(Vehicle* vehicle) {
        vehicles.push_back(vehicle);
    }

    

    void displayFleet() const {
        for (const auto& vehicle : vehicles) {
            vehicle->display();
        }
    }


    ~Fleet() {
        for (auto& vehicle : vehicles) {
            delete vehicle;
        }
    }

};

void main() 
{
   

    Vehicle* car1 = new Car("Toyota", "Corolla", 2020);
    Vehicle* car2 = new Car("Deo", "Lanus", 2007);
    Vehicle* truck1 = new Truck("Lada", "Samara", 1994);

   

    Fleet fleet;
    fleet.addVehicle(car1);
    fleet.addVehicle(car2);
    fleet.addVehicle(truck1);

    

    cout << "Fleet of vehicles:" << endl;
    fleet.displayFleet();

   

}
