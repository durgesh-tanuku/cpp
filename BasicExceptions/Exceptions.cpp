#include <iostream>
#include <exception>

void mightGoWrong() {
	bool error1 = false;
	bool error2 = false;
	bool error3 = true;

	if (error1) {
		throw 8;
	}
	if (error2) {
		throw "Exception";
	}
	if (error3) {
		throw std::string("String Exception");
	}
}

class CanGoWrong {
public:
	char* ptr;
	CanGoWrong() {
		ptr = new char[10000000000000000];
	}
};

class MyCustomException : public std::exception {
public:
	virtual const char* what() const throw(){
		return "my exception\n";
	}
};

class Test {
public:
	void goesWrong(){
		throw MyCustomException();
	}
};

int main() {
	std::cout << "Hello World\n";

	try {
		mightGoWrong();
	} catch (int e) {
		std::cout << "Error Code: " << e << "\n";
	} catch (const char* str) {
		std::cout << "Exception: " << str << "\n";
	} catch (std::string& str) {
		std::cout << "String Exception: " << str << "\n";
	}

	try {
		CanGoWrong cw;
	} catch (std::exception& exe) {
		std::cout << exe.what() << "\n";
	}

	try {
		Test t;
		t.goesWrong();
	} catch (std::exception& exe) {
		std::cout << "custom exception: "<<exe.what()<<"\n";
	}
	std::cout << "Still running\n";
	return 0;
}
