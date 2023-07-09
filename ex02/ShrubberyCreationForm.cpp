
#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::name = "ShrubberyCreationForm";
const int ShrubberyCreationForm::gradeForSign = 145;
const int ShrubberyCreationForm::gradeForExecute = 137;

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(name, gradeForSign, gradeForExecute) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (this->getIsSigned()) {
		if (executor.getGrade() > gradeForExecute) {
			throw GradeTooLowException();
		}
		//exec
	}
}