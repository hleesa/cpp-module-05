
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) {
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

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (this->getIsSigned()) {
		if (executor.getGrade() > this->getGradeForExecute()) {
			throw GradeTooLowException();
		}
		//exec
	}
}