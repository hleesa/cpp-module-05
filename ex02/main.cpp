
#include "Bureaucrat.hpp"

void test1() {
	int grade[] = {0, 151, -1, 152, -42, 4242, 1, 150, 50, 100};
	int size = sizeof(grade) / sizeof(grade[0]);
	for (int i = 0; i < size; ++i) {
		try {
			Bureaucrat salee2("salee2", grade[i]);
			std::cout << salee2;
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << "\n\n";
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
	std::cout << "\n\n";
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
	std::cout << "\n\n";
}

#include "ShrubberyCreationForm.hpp"

void test20() {
	int grade[] = {146, 145, 144, 138, 137, 136};
	int size = sizeof(grade) / sizeof(grade[0]);
	for (int i = 0; i < size; ++i) {
		std::cout << i << '\n';
		AForm* scf;
		try {
			Bureaucrat salee2("salee2", grade[i]);
			std::cout << salee2;
			scf = new ShrubberyCreationForm("home");
			std::cout << *scf;
			salee2.signAForm(*scf);
			salee2.executeForm(*scf);
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		delete scf;
		std::cout << "\n\n";
	}
}

#include "RobotomyRequestForm.hpp"

void test21() {
	int grade[] = {73, 72, 71, 46, 45, 44};
	int size = sizeof(grade) / sizeof(grade[0]);
	for (int i = 0; i < size; ++i) {
		std::cout << i << '\n';
		AForm* rrf;
		try {
			Bureaucrat salee2("salee2", grade[i]);
			std::cout << salee2;
			rrf = new RobotomyRequestForm("housekeeper");
			std::cout << *rrf;
			salee2.signAForm(*rrf);
			salee2.executeForm(*rrf);
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		delete rrf;
		std::cout << "\n\n";
	}
}

void test22() {
	int size = 10;
	for (int i = 0; i < size; ++i) {
		std::cout << i << '\n';
		AForm* rrf;
		try {
			Bureaucrat salee2("salee2", 45);
			rrf = new RobotomyRequestForm("housekeeper");
			salee2.signAForm(*rrf);
			salee2.executeForm(*rrf);
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		delete rrf;
		std::cout << "\n\n";
	}
}

#include "PresidentialPardonForm.hpp"

void test23() {
	int grade[] = {26, 25, 24, 6, 5, 4};
	int size = sizeof(grade) / sizeof(grade[0]);
	for (int i = 0; i < size; ++i) {
		std::cout << i << '\n';
		AForm* ppf;
		try {
			Bureaucrat salee2("salee2", grade[i]);
			std::cout << salee2;
			ppf = new PresidentialPardonForm("bocal");
			std::cout << *ppf;
			salee2.signAForm(*ppf);
			salee2.executeForm(*ppf);
		} catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		delete ppf;
		std::cout << "\n\n";
	}
}


int main() {

	std::cout << "#############################################" << std::endl;
	std::cout << "#############################################" << std::endl;
	std::cout << "\n\n";

//	test1();
//	test2();
//	test3();

	test20();
//	test21();
//	test22();
//	test23();

//	system("leaks AForm28B");
	std::cout << "#############################################" << std::endl;
	std::cout << "#############################################" << std::endl;

	return 0;
}