
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
	int size = 6;
	for (int i = 0; i < size; ++i) {
		try{
			Bureaucrat salee2("salee2", grade[i]);
			std::cout << salee2;
			AForm* scf = new ShrubberyCreationForm("home");
			std::cout << *scf;
			scf->execute(salee2);
			salee2.signAForm(*scf);
			std::cout << *scf;
			salee2.executeForm(*scf);
		} catch (std::exception& e ) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "\n\n";
	}
}

#include "RobotomyRequestForm.hpp"

void test21() {
	int grade[] = {73, 72, 71, 46, 45, 44};
	int size = 6;
	for (int i = 0; i < size; ++i) {
		try{
			Bureaucrat salee2("salee2", grade[i]);
			std::cout << salee2;
			AForm* rrf = new RobotomyRequestForm();
			std::cout << *rrf;
			rrf->execute(salee2);
			salee2.signAForm(*rrf);
			std::cout << *rrf;
			salee2.executeForm(*rrf);
		} catch (std::exception& e ) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "\n\n";
	}
}

void test22() {
	int size = 10;
	for (int i = 0; i < size; ++i) {
		try{
			std::cout << i << '\n';
			Bureaucrat salee2("salee2", 45);
			AForm* rrf = new RobotomyRequestForm();
			salee2.signAForm(*rrf);
			salee2.executeForm(*rrf);
		} catch (std::exception& e ) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		std::cout << "\n\n";
	}
}

#include "PresidentialPardonForm.hpp"

void test23() {
	int grade[] = {26, 25, 24, 6, 5, 4};
	int size = 6;
	for (int i = 0; i < size; ++i) {
		try{
			Bureaucrat salee2("salee2", grade[i]);
			std::cout << salee2;
			AForm* ppf = new PresidentialPardonForm();
			std::cout << *ppf;
			ppf->execute(salee2);
			salee2.signAForm(*ppf);
			std::cout << *ppf;
			salee2.executeForm(*ppf);
		} catch (std::exception& e ) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
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
	test21();
	test22();
	test23();

	std::cout << "#############################################" << std::endl;
	std::cout << "#############################################" << std::endl;

	return 0;
}