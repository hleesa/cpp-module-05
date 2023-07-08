
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

Form::Form() : name("none"), isSigned(false), gradeForSign(150), gradeForExecute(150) {
}

Form::Form(const std::string name, bool isSigned, const int gradeForSign, const int gradeForExecute) :
		name(name), isSigned(isSigned), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute) {
}

Form::Form(const Form& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
}

Form::~Form() {

}