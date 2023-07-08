
#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException() : errorMessage("too high") {
}

const char* Form::GradeTooHighException::what() const throw() {
	return errorMessage;
}

Form::GradeTooLowException::GradeTooLowException() : errorMessage("too low") {
}

const char* Form::GradeTooLowException::what() const throw() {
	return errorMessage;
}

Form::Form() : name("none"), isSigned(false),
			   gradeForSign(Bureaucrat::getLowestGrade()), gradeForExecute(Bureaucrat::getLowestGrade()) {
}

Form::Form(const std::string name, bool isSigned, const int gradeForSign, const int gradeForExecute) :
		name(name), isSigned(isSigned), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute) {
	if (gradeForSign < Bureaucrat::getHighestGrade()) {
		throw GradeTooHighException();
	}
	else if (gradeForSign > Bureaucrat::getLowestGrade()) {
		throw GradeTooLowException();
	}
	else if (gradeForExecute < Bureaucrat::getHighestGrade()) {
		throw GradeTooHighException();
	}
	else if (gradeForExecute > Bureaucrat::getLowestGrade()) {
		throw GradeTooLowException();
	}
}

Form::Form(const Form& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
}

Form::~Form() {

}