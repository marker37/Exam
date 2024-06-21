#include <iostream>
#include <stdexcept>
using namespace std;


class Base {
public:
    virtual ~Base() = default;
    virtual void show() const {
        cout << "Base class" << endl;
    }
};




class Derived : public Base {
public:
    void show() const override {
        cout << "Derived class" << endl;
    }

    void derivedMethod() const {
        cout << "Method specific to Derived class" << endl;
    }
};




Derived* convertToDerived(Base* basePtr) {
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);
    if (derivedPtr == nullptr) {
        throw runtime_error("Conversion to Derived* failed");
    }
    return derivedPtr;
}



void main()
{
    try
    {
        Base* basePtr = new Derived();




        Derived* derivedPtr = convertToDerived(basePtr);

        derivedPtr->show();
        derivedPtr->derivedMethod();


        delete basePtr;

    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }



    try {
        Base* basePtr = new Base();




        Derived* derivedPtr = convertToDerived(basePtr);

        derivedPtr->show();
        derivedPtr->derivedMethod();

        delete basePtr;

    }
    catch (const runtime_error& e) {
        cerr << e.what() << endl;
    }

}



// dynamic_cast корисний для  приведення типів  класів, коли потрібна робота з різними типами об'єктів через вказівники. 



