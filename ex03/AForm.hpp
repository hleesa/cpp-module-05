
#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {

private:
	const std::string name;
	const std::string target;
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

	class NoSignedFormException : public std::exception {
	private:
		const char* errorMessage;

	public:
		NoSignedFormException();

		const char* what() const throw();
	};

	void validateGrades();

	AForm();

	AForm(const std::string name, const std::string target, const int gradeForSign, const int gradeForExecute);

	AForm(const AForm& other);

	AForm& operator=(const AForm& other);

	virtual ~AForm();

	void beSigned(const Bureaucrat& bureaucrat);

	bool isExecutable(Bureaucrat const& executor) const;

	static AForm* createShrubberyCreationForm(const std::string target);

	static AForm* createRobotomyRequestForm(const std::string target);

	static AForm* createPresidentialPardonForm(const std::string target);

	virtual void execute(Bureaucrat const& executor) const = 0;

	const std::string getName() const;

	const std::string getTarget() const;

	bool getIsSigned() const;

	int getGradeForSign() const;

	int getGradeForExecute() const;
};

std::ostream& operator<<(std::ostream& os, const AForm& obj);

#endif //AForm_HPP
