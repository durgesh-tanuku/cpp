/*Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.

An integer m is a divisor of n if there exists an integer k such that n = k * m.

Ex1: Input: n = 2
Output: false
Explantion: 2 has only two divisors: 1 and 2.

Ex2: Input: n = 4
Output: true
Explantion: 4 has three divisors: 1, 2, and 4.*/

#include <iostream>

class Solution {
public:
    bool isThree(int n) {
        int count = 0;
        for (int i=1; i<=n; i++) {
            if (n%i == 0) ++count;
        }
        if (count == 3) return true;
        else return false;
    }
};

int main() {
    Solution s1;
    std::cout << s1.isThree(12) << std::endl;
    return 0;
}

