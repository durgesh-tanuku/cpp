#include <iostream>
#include <vector>

int main() {
	std::vector<int> myVector;
	std::cout << "Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << "\n";
	myVector.push_back(1);
	std::cout << "Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << "\n";
	myVector.push_back(2);
	std::cout << "Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << "\n";
	myVector.push_back(3);
	std::cout << "Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << "\n";
	myVector.push_back(4);
	std::cout << "Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << "\n";
	myVector.push_back(5);
	std::cout << "Size: " << myVector.size() << ", Capacity: " << myVector.capacity() << "\n";
	return 0;
}
