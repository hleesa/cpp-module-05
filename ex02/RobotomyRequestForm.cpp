
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", "none", 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", target, 72, 45) {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void makeDrillingNoise() {
	std::cout << "Vrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr\n";
}

void robotomized(std::string target) {
	makeDrillingNoise();
	std::srand(static_cast<unsigned int>(std::time(NULL)));
	int probability = rand() & 1;
	std::cout << target;
	if (probability) {
		std::cout << " has been robotomized successfully\n";
	}
	else {
		std::cout << " has been robotomized failed\n";
	}
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (isExecutable(executor)) {
		robotomized(getTarget());
	}
}