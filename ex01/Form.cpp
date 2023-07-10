
#include "Form.hpp"

Form::GradeTooHighException::GradeTooHighException() : errorMessage("The form's grade is too high") {
}

const char* Form::GradeTooHighException::what() const throw() {
	return errorMessage;
}

Form::GradeTooLowException::GradeTooLowException() : errorMessage("The form's grade is too low") {
}

const char* Form::GradeTooLowException::what() const throw() {
	return errorMessage;
}

void Form::validateGrades() {
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

Form::Form() : name("none"), isSigned(false),
			   gradeForSign(Bureaucrat::getLowestGrade()), gradeForExecute(Bureaucrat::getLowestGrade()) {
}

Form::Form(const std::string name, const short gradeForSign, const short gradeForExecute) :
		name(name), isSigned(false), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute) {
	validateGrades();
}

Form::Form(const Form& other) : name(other.name), isSigned(other.isSigned),
								gradeForSign(other.gradeForSign), gradeForExecute(other.gradeForExecute) {
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

Form::~Form() {
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeForSign) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

const std::string Form::getName() const {
	return name;
}

bool Form::getIsSigned() const {
	return isSigned;
}

short Form::getGradeForSign() const {
	return gradeForSign;
}

short Form::getGradeForExecute() const {
	return gradeForExecute;
}

std::ostream& operator<<(std::ostream& os, const Form& obj) {
	os << obj.getName() << ", is signed: " << obj.getIsSigned() << ", grade for sign: " <<  obj.getGradeForSign() <<", grade for execute: " << obj.getGradeForExecute() << '\n';
	return os;
}
