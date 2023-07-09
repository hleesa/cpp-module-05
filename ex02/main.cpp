
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


//void test10() {
//	int lowGrade[6][2] = {{151, 100},
//						  {100, 151},
//						  {151, 151},
//						  {0,   1},
//						  {1,   0},
//						  {0,   0}};
//	for (int i = 0; i < 6; ++i) {
//		try {
//			AForm diary("diary", lowGrade[i][0], lowGrade[i][1]);
//		}
//		catch (std::exception& e) {
//			std::cout << "Exception: " << e.what() << std::endl;
//		}
//	}
//	std::cout << "\n\n";
//}

void test11() {
	for (int i = 0; i < 3; ++i) {
		try {
			Bureaucrat salee2("salee2", 99 + i);
			std::cout << salee2;
//			AForm diary("diary", 100, 100);
//			std::cout << diary;
//			salee2.signAForm(diary);
//			std::cout << diary;
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
//	test10();
//	test11();

	std::cout << "#############################################" << std::endl;
	std::cout << "#############################################" << std::endl;

	return 0;
}