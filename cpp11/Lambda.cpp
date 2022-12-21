#include <iostream>

using namespace std;

void test(void (*pFunc)(void)) {
    pFunc();
}

int main() {
    auto func = [](){cout << "Lambda" << endl;};
    func();
    test(func);
}