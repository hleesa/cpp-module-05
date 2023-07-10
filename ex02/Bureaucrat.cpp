
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

void Bureaucrat::signAForm(AForm& form) {
	if (grade <= form.getGradeForSign()) {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << '\n';
	}
	else {
		std::cout << name << " couldn't sign " << form.getName() << " because grade too low\n";
	}
}

void Bureaucrat::executeForm(const AForm& form) {
	if (grade <= form.getGradeForExecute()) {
		std::cout << name << " executed " << form.getName() << '\n';
		form.execute(*this);
	}
	else {
		std::cout << name << " couldn't execute " << form.getName() << " because grade too low\n";
	}
}

const std::string Bureaucrat::getName() const {
	return name;
}

short Bureaucrat::getGrade() const {
	return grade;
}

short Bureaucrat::getHighestGrade() {
	return highestGrade;
}

short Bureaucrat::getLowestGrade() {
	return lowestGrade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj) {
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << '\n';
	return os;
}
