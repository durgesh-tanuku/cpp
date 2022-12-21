#include <iostream>
#include <vector>

using namespace std;

int main() {
    const char* list[] = {"Hi", "Hello", "World"};

    for (auto l: list) {
        cout << l << endl;
    }

    vector<int> vec{1, 2, 3, 4};
    for (auto v: vec) {
        cout << v << endl;
    }
    return 0;
}