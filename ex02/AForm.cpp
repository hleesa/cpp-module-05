
#include "AForm.hpp"

AForm::GradeTooHighException::GradeTooHighException() : errorMessage("The form's grade is too high") {
}

const char* AForm::GradeTooHighException::what() const throw() {
	return errorMessage;
}

AForm::GradeTooLowException::GradeTooLowException() : errorMessage("The form's grade is too low") {
}

const char* AForm::GradeTooLowException::what() const throw() {
	return errorMessage;
}

AForm::NoSignedFormException::NoSignedFormException() : errorMessage("The form is not signed") {
}

const char* AForm::NoSignedFormException::what() const throw() {
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

AForm::AForm(const std::string name, const std::string target, const short gradeForSign, const short gradeForExecute) :
		name(name), target(target), isSigned(false), gradeForSign(gradeForSign), gradeForExecute(gradeForExecute) {
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

bool AForm::isExecutable(const Bureaucrat& executor) const {
	if (isSigned) {
		if (executor.getGrade() > gradeForExecute) {
			throw GradeTooLowException();
		}
		return true;
	}
	throw NoSignedFormException();
}

const std::string AForm::getName() const {
	return name;
}

const std::string AForm::getTarget() const {
	return target;
}

bool AForm::getIsSigned() const {
	return isSigned;
}

short AForm::getGradeForSign() const {
	return gradeForSign;
}

short AForm::getGradeForExecute() const {
	return gradeForExecute;
}

std::ostream& operator<<(std::ostream& os, const AForm& obj) {
	os << "name: " << obj.getName() << ", target: " << obj.getTarget() << ", isSigned: " << obj.getIsSigned()
	   << ", gradeForSign: " << obj.getGradeForSign() << ", gradeForExecute: " << obj.getGradeForExecute() << '\n';
	return os;
}
