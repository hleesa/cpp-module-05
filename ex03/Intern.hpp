
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {


private:
	class NoParameterException : public std::exception {
	private:
		const char* errorMessage;

	public:
		NoParameterException();

		const char* what() const throw();
	};

public:
	Intern();

	Intern(const Intern& other);

	Intern& operator=(const Intern& other);

	~Intern();

	AForm* makeForm(const std::string name, const std::string target);
};


#endif //INTERN_HPP
