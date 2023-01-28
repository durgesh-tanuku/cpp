#include <iostream>

int main() {
    int a = 5;
    /* Arguments captured by value aren't modifiable inside lambda without
       mutable keyword*/
    [=]() mutable {
        a = 8;
        std::cout << a << std::endl;
    }();
    std::cout << a << std::endl;
    return 0;
}