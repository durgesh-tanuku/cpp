#include <iostream>
#include <algorithm>
#include <vector>

class Check{
public:
    bool operator()(std::string& str) {
        return str.length() == 3;
    }
}check;

int main() {
    int size = 5;
    std::vector<std::string> vec{"one", "two", "three"};

    std::function<bool(std::string)> func = [=](std::string str){return str.length()==size;};
    int count = std::count_if(vec.begin(), vec.end(), func);
    std::cout << "count: " << count << std::endl;

    count = std::count_if(vec.begin(), vec.end(), check);
    std::cout << "count: " << count << std::endl;
}