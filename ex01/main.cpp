
#include "Bureaucrat.hpp"

void test1() {
	try {
		Bureaucrat salee2("salee2", 0);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void test2() {
	try {
		Bureaucrat salee2("salee2", 151);
	} catch (std::exception& e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}

void test3() {
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

void test4() {
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
	test1();
	std::cout << "=============================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	test2();
	std::cout << "=============================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	test3();
	std::cout << "=============================================" << std::endl;
	std::cout << "=============================================" << std::endl;
	test4();
	std::cout << "#############################################" << std::endl;
	std::cout << "#############################################" << std::endl;

	return 0;
}