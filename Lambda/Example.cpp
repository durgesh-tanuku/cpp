#include <iostream>

void test(void (*fp)(void)) {
    fp();
}

int main()
{
    auto func = [](){std::cout << "Test message\n";};
    func();
    test([](){std::cout << "Test message1\n";});

    auto pDivide =
    [](double a, double b) -> double {
        if (b == 0.0) {
            return 0;
        }
        return a/b;
    };

    std::cout << pDivide(10.0, 5.0) << std::endl;
    std::cout << pDivide(10.0, 0.0) << std::endl;
    return 0;
}