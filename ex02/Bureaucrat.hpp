
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat {

private:
	const std::string name;
	int grade;
	static const int highestGrade;
	static const int lowestGrade;

public:
	class GradeTooHighException : public std::exception {

	private:
		const char* errorMessage;

	public:
		GradeTooHighException();

		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception {

	private:
		const char* errorMessage;

	public:
		GradeTooLowException();

		const char* what() const throw();
	};

	Bureaucrat();

	Bureaucrat(const std::string name, int grade);

	Bureaucrat(const Bureaucrat& other);

	Bureaucrat& operator=(const Bureaucrat& other);

	~Bureaucrat();

	void upgrade();

	void degrade();

	void signAForm(AForm& AForm);

	const std::string getName() const;

	int getGrade() const;

	static int getHighestGrade();

	static int getLowestGrade();

	void executeForm(AForm const& form);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif //BUREAUCRAT_HPP