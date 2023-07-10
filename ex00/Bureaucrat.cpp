
#include "Bureaucrat.hpp"

const short Bureaucrat::highestGrade = 1;
const short Bureaucrat::lowestGrade = 150;

Bureaucrat::GradeTooHighException::GradeTooHighException() : errorMessage("The bureaucrat's grade is too high") {
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
	return errorMessage;
}

Bureaucrat::GradeTooLowException::GradeTooLowException() : errorMessage("The bureaucrat's grade is too low") {
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
	return errorMessage;
}

Bureaucrat::Bureaucrat() : name("none"), grade(lowestGrade) {
}

Bureaucrat::Bureaucrat(const std::string name, short grade) : name(name), grade(grade) {
	if (grade < highestGrade) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > lowestGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : name(other.name), grade(other.grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

void Bureaucrat::upgrade() {
	if (grade <= highestGrade) {
		throw Bureaucrat::GradeTooHighException();
	}
	--grade;
}

void Bureaucrat::degrade() {
	if (grade >= lowestGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
	++grade;
}

const std::string Bureaucrat::getName() const {
	return name;
}

short Bureaucrat::getGrade() const {
	return grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << '\n';
	return os;
}
