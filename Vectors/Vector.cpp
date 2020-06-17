#include <iostream>
#include <vector>

int main() {
	std::vector<int> myVector;
	std::cout << "Size: " << myVector.size() << ", Capacity: "
			<< myVector.capacity() << "\n";
	unsigned int capacity = myVector.capacity();
	for (int count = 1; count <= 1000; count++) {
		if (capacity != myVector.capacity()) {
			capacity = myVector.capacity();
			std::cout << "Size: " << myVector.size() << ", Capacity: "
					<< myVector.capacity() << "\n";
		}
		myVector.push_back(count);
	}

	for (std::vector<int>::iterator it = myVector.begin(); it != myVector.end();
			it++) {
		/* Print multiples of 100 */
		if (*it % 100 == 0) {
			std::cout << *it << "\n";
		}
	}

	/* Two Dimentional Vector */
	std::vector<std::vector<int> > vec(3, std::vector<int>(4, 7));

	for (unsigned int row = 0; row < vec.size(); row++) {
		for (unsigned int col = 0; col < vec[row].size(); col++) {
			std::cout << vec[row][col] << "\t";
		}
		std::cout << "\n";
	}
	return 0;
}
