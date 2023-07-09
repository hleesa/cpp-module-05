
#include "PresidentialPardonForm.hpp"

const std::string PresidentialPardonForm::name = "PresidentialPardonForm";
const int PresidentialPardonForm::gradeForSign = 25;
const int PresidentialPardonForm::gradeForExecute = 5;

PresidentialPardonForm::PresidentialPardonForm() : AForm(name, gradeForSign, gradeForExecute) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const{
	if (this->getIsSigned()){
		if (executor.getGrade() > gradeForExecute) {
			throw GradeTooLowException();
		}
		//exec
	}
}