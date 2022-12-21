#include <iostream>

using namespace std;

class Foo {
private:
    int* arr;
    int size;

public:
    Foo(int size) : size(size) {
        cout << "ctor invoked" << endl;
        arr = new int[size];
    }

    /* Copy constructor */
    Foo(const Foo& rhs) {
        cout << "copy ctor invoked" << endl;
        size = rhs.size;
        arr = new int[size];
        for (int i=0; i<size; i++) {
            arr[i] = rhs.arr[i];
        }
    }

    /* Move constructor */
    Foo(Foo&& rhs) noexcept {
        cout << "Move ctor invoked" << endl;
        arr = rhs.arr;
        size = rhs.size;
        rhs.arr = nullptr;
    }

    /* Copy assignment operator */
    Foo& operator=(const Foo& rhs) {
        cout << "copy assignment operator invoked" << endl;
        if (this == &rhs) {
            return *this;
        }

        if (arr) delete[] arr;

        size = rhs.size;
        arr = new int[size];
        for (int i=0; i<size; i++) {
            arr[i] = rhs.arr[i];
        }
        return *this;        
    }

    /* Move assignment operator */
    Foo& operator=(Foo&& rhs) {
        cout << "Move assignment operator invoked" << endl;
        arr = rhs.arr;
        size = rhs.size;
        rhs.arr = nullptr;

        return *this;
    }

    ~Foo() {
        if (arr)
            delete[] arr;
    }

    int length() {
        return size;
    }

    int& operator[](int i) {
        return arr[i];
    }

    friend ostream& operator<<(std::ostream& os, const Foo& rhs) {
        for(int i=0; i<rhs.size; i++) {
            os << rhs.arr[i] << " ";
        }
        return os;
    }

    Foo operator+(const Foo& rhs) {
        Foo tmp(size+rhs.size);

        int j=0;
        for(; j<size; j++) tmp[j] = arr[j];
        for(int i=0; i<rhs.size; i++, j++) tmp[j] = rhs.arr[i];

        return tmp;
    }
};

int main() {
    Foo f(5);
    for(int i=0; i<f.length(); i++) {
        f[i] = 3 *i;
    }
    cout << f << endl;

    Foo g = f;
    cout << g << endl;

    Foo h(3);
    cout << h << endl;
    
    h = f+g;
    cout << h << endl;

    return 0;
}