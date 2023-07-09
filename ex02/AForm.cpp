
#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException() : errorMessage("The AForm's grade is too high") {
}

const char* AForm::GradeTooHighException::what() const throw() {
	return errorMessage;
}

AForm::GradeTooLowException::GradeTooLowException() : errorMessage("The AForm's grade is too low") {
}

const char* AForm::GradeTooLowException::what() const throw() {
	return errorMessage;
}

void AForm::validateGrades() {
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

AForm::AForm() : name("none"), isSigned(false),
			   gradeForSign(Bureaucrat::getLowestGrade()), gradeForExecute(Bureaucrat::getLowestGrade()) {
}

AForm::AForm(const std::string name, const int gradeForSign, const int gradeForExecute) :
		name(name), isSigned(false), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute) {
	validateGrades();
}

AForm::AForm(const AForm& other) : name(other.name), isSigned(other.isSigned),
								gradeForSign(other.gradeForSign), gradeForExecute(other.gradeForExecute) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		isSigned = other.isSigned;
	}
	return *this;
}

AForm::~AForm() {
}

void AForm::beSigned(const Bureaucrat& bureaucrat) {
	if (bureaucrat.getGrade() > gradeForSign) {
		throw GradeTooLowException();
	}
	isSigned = true;
}

const std::string AForm::getName() const {
	return name;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

int AForm::getGradeForSign() const {
	return gradeForSign;
}

int AForm::getGradeForExecute() const {
	return gradeForExecute;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << obj.getName() << ", is signed: " << obj.getIsSigned() << ", grade for sign: " <<  obj.getGradeForSign() <<", grade for execute: " << obj.getGradeForExecute() << '\n';
	return os;
}
