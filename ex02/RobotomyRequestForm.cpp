
#include "RobotomyRequestForm.hpp"

const std::string RobotomyRequestForm::name = "RobotomyRequestForm";
const int RobotomyRequestForm::gradeForSign = 72;
const int RobotomyRequestForm::gradeForExecute = 45;

RobotomyRequestForm::RobotomyRequestForm() : AForm(name, gradeForSign, gradeForExecute) {
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

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	if (this->getIsSigned()) {
		if (executor.getGrade() > gradeForExecute) {
			throw GradeTooLowException();
		}
		//exec
	}
}