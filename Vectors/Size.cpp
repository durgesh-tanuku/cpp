#include <iostream>
#include <vector>
#include <exception>

using namespace std;

int i = 0;

class Test {
public:
    Test() {
        cout << "ctor" << endl;
        if (++i == 2) {
            throw 1;
        }
    }

    ~Test() {
        cout << "dtor" << endl;
    }
};

int main() {
    vector<Test> vec;

    cout << "size of vec: " << vec.size() << endl;

    try {
        vec.resize(10);
    }
    catch(...) {
        cout << "Exception caught" << endl;
    }

    cout << "size of vec: " << vec.size() << endl;

    return 0;
}