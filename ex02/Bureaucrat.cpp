
#include "Bureaucrat.hpp"

const int Bureaucrat::highestGrade = 1;
const int Bureaucrat::lowestGrade = 150;

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

Bureaucrat::Bureaucrat(const std::string name, int grade) : name(name), grade(grade) {
	if (grade < highestGrade) {
		throw GradeTooHighException();
	}
	else if (grade > lowestGrade) {
		throw GradeTooLowException();
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

void Bureaucrat::signAForm(AForm& AForm) {
	if (grade <= AForm.getGradeForSign()) {
		AForm.beSigned(*this);
		std::cout << name << " signed " << AForm.getName() << '\n';
	}
	else {
		std::cout << name << " couldn't sign " << AForm.getName() << " because grade to low\n";
	}
}

const std::string Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

int Bureaucrat::getHighestGrade() {
	return highestGrade;
}

int Bureaucrat::getLowestGrade() {
	return lowestGrade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << '\n';
	return os;
}
