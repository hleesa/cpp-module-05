
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

class Bureaucrat {

private:
	const std::string name;
	int grade;
	const int highestGrade;
	const int lowestGrade;

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

	const std::string getName() const;

	int getGrade() const;

	void upgrade();

	void degrade();

};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& obj);

#endif //BUREAUCRAT_HPP
