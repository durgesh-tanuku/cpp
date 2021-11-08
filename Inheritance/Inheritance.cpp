#include <iostream>

using namespace std;

class Base {
public:
    virtual void print() {
        cout << "print() of Base calss" << endl;
    }

    Base() {
        cout << "Constructor of Base" << endl; 
    }

    virtual ~Base() {
        cout << "Destructor of Base" << endl;
    }
};

class Derived : public Base {
public:
    virtual void print() {
        cout << "print() of Derived calss" << endl;
    }

    Derived() {
        cout << "Destructor of Derived" << endl;
    }

    ~Derived() {
        cout << "Destructor of Derived" << endl;
    }
};

int main() {
    Base* b1 = new Derived();
    b1->print();
    delete b1;
    return 0;
}

