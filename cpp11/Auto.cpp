#include <iostream>

using namespace std;

template <class T>
auto value(T val) -> decltype(val) {
    return val;
}

int get() {
    return 999;
}

auto val() -> decltype(get()) {
    return get();
}

int main() {
    auto i = 10;
    auto s = "Hello";
    cout << value(i) << endl;
    cout << value(s) << endl;
    cout << val() << endl;
    return 0;
}