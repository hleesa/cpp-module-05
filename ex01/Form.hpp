
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string name;
	bool isSigned;
	const int gradeForSign;
	const int gradeForExecute;

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

	void validateGrades();

	Form();

	Form(const std::string name, const int gradeForSign, const int gradeForExecute);

	Form(const Form& other);

	Form& operator=(const Form& other);

	~Form();

	void beSigned(const Bureaucrat& bureaucrat);

	const std::string getName() const;

	bool getIsSigned() const;

	int getGradeForSign() const;

	int getGradeForExecute() const;

};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif //FORM_HPP
