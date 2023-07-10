
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


void test10() {
	int lowGrade[][2] = {{151, 100},
						 {100, 151},
						 {151, 151},
						 {0,   1},
						 {1,   0},
						 {0,   0}};
	const int size = sizeof(lowGrade) / sizeof(lowGrade[0]);
	for (int i = 0; i < size; ++i) {
		try {
			Form diary("diary", lowGrade[i][0], lowGrade[i][1]);
		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
	}
	std::cout << "\n\n";
}

void test11() {
	for (int i = 0; i < 3; ++i) {
		try {
			Bureaucrat salee2("salee2", 99 + i);
			std::cout << salee2;
			Form diary("diary", 100, 100);
			std::cout << diary;
			salee2.signForm(diary);
			std::cout << diary;
		}
		catch (std::exception& e) {
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

	test10();
//	test11();

//	system("leaks form");
	std::cout << "#############################################" << std::endl;
	std::cout << "#############################################" << std::endl;

	return 0;
}