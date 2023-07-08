
#include "Bureaucrat.hpp"

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

Bureaucrat::Bureaucrat() : name("none"), grade(42), highestGrade(1), lowestGrade(150) {
}

Bureaucrat::Bureaucrat(const std::string name, int grade)
		: name(name), grade(grade), highestGrade(1), lowestGrade(150) {
	if (grade < highestGrade) {
		throw Bureaucrat::GradeTooHighException();
	}
	else if (grade > lowestGrade) {
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& other)
		: name(other.name), grade(other.grade), highestGrade(other.highestGrade), lowestGrade(other.lowestGrade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
}

const std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
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

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << '\n';
	return os;
}
