
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

#include "AForm.hpp"

class AForm;

class Bureaucrat {

private:
	const std::string name;
	short grade;
	static const short highestGrade;
	static const short lowestGrade;

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

public:
	Bureaucrat();

	Bureaucrat(const std::string name, short grade);

	Bureaucrat(const Bureaucrat& other);

	Bureaucrat& operator=(const Bureaucrat& other);

	~Bureaucrat();

	void upgrade();

	void degrade();

	void signAForm(AForm& AForm);

	const std::string getName() const;

	short getGrade() const;

	static short getHighestGrade();

	static short getLowestGrade();

	void executeForm(AForm const& form);

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif //BUREAUCRAT_HPP
