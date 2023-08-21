
#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string name;
	bool isSigned;
	const short gradeForSign;
	const short gradeForExecute;

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
	void validateGrades();

	Form();

	Form(const std::string name, const short gradeForSign, const short gradeForExecute);

	Form(const Form& other);

	Form& operator=(const Form& other);

	~Form();

	void beSigned(const Bureaucrat& bureaucrat);

	const std::string getName() const;

	bool getIsSigned() const;

	short getGradeForSign() const;

	short getGradeForExecute() const;

};

std::ostream& operator<<(std::ostream& os, const Form& obj);

#endif //FORM_HPP
