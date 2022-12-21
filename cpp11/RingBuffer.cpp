#include <iostream>

using namespace std;

template <class T>
class Ring {
    T* arr;
    int idx;
    int max_sz;
public:
    Ring(int size) {
        //cout << "ctor" << endl;
        arr = new T[size];
        idx = 0;
        max_sz = size;
    }

    ~Ring() {
        delete [] arr;
    }

    void push(T val) {
        arr[idx++] = val;
        if (idx == max_sz) idx = 0;
    }

    void display() {
        for (int i=0; i<max_sz; i++) {
            cout << arr[i] << endl;
        }
        cout << endl;
    }
};

int main() {
    Ring<string> ring(3);
    ring.push("one");
    ring.push("two");
    ring.push("three");
    ring.push("four");

    ring.display();

    return 0;
}
