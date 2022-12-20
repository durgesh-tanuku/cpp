#include <iostream>

int main()
{
    int one = 1;
    int two = 2;
    int three = 3;

    // Capture one by value (variable captured by value is not modifiable in lambda)
    [one](){ /* one = 10*/ std::cout << one << std::endl;}();

    // Capture one, two and three by value
    [one, two, three](){ std::cout << one << ", " << two << ", " << three << std::endl;}();

    // Capture one and two by reference
    [&one, &two](){ one = 10; std::cout << one << ", " << two << std::endl;}();

    // Capture all by value and two by reference
    [=, &two](){}();

    // Capture all by reference and three by value
    [&, three](){}();
    
    return 0;
}