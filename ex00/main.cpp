
#include "Bureaucrat.hpp"

void test1() {
	try {
		Bureaucrat salee2("salee2", 0);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	try {
		Bureaucrat salee2("salee2", 151);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void test2() {
	try {
		Bureaucrat salee2("salee2", 2);
		std::cout << salee2;
		salee2.upgrade();
		std::cout << salee2;
		salee2.upgrade();
		std::cout << salee2;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void test3() {
	try {
		Bureaucrat salee2("salee2", 149);
		std::cout << salee2;
		salee2.degrade();
		std::cout << salee2;
		salee2.degrade();
		std::cout << salee2;
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

int main() {

	std::cout << "#############################################" << std::endl;
	std::cout << "#############################################" << std::endl;
	std::cout << "\n\n";
	test1();
	std::cout << "\n\n";
	test2();
	std::cout <<"\n\n";
	test3();
	std::cout <<"\n\n";
	std::cout << "#############################################" << std::endl;
	std::cout << "#############################################" << std::endl;
	return 0;
}