#include <iostream>
#include <list>

int main() {
	std::list<int> numbers;
	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);
	std::cout << "size : " << numbers.size() << "\n";

	std::list<int>::iterator it = numbers.begin();
	it++;
	numbers.insert(it, 100);
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << "\n";
	}

	std::cout << "===== After erase =======\n";	

	std::list<int>::iterator eraseIt = numbers.begin();
	eraseIt++;
	/* eraseIt will be invalidated inside erase. Use iterator returned by erase */
	std::list<int>::iterator new_it = numbers.erase(eraseIt);
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << "\n";
	}

	std::cout << "======== List erase in loop ========\n";

	/* NOTE: When erase is used inside loops, no need to increment iterator 
     * in increment expression of for loop */
	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end();) {
		if (*it == 2) {
			numbers.insert(it, 1234);
		}

		if (*it == 1) {
			it = numbers.erase(it);
		} else {
			it++;
		}
	}

	for (std::list<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		std::cout << *it << "\n";
	}
	return 0;
}
