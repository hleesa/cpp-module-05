
#include "Intern.hpp"

Intern::NoParameterException::NoParameterException() : errorMessage("The parameter does not exist.") {
}

const char* Intern::NoParameterException::what() const throw() {
	return errorMessage;
}

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void) other;
}

Intern& Intern::operator=(const Intern& other) {
	if (this != &other) {
		(void) other;
	}
	return *this;
}

Intern::~Intern() {
}

int nameToIndex(const std::string name) {
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int index = -1;
	for (int i = 0; i < 3; ++i) {
		if (name == formNames[i]){
			index = i;
		}
	}
	return index;
}

AForm* Intern::makeForm(const std::string name, const std::string target) {
	int nameIdx = nameToIndex(name);
	AForm* form = NULL;
	switch (nameIdx) {
		case 0:
			form = new ShrubberyCreationForm(target);
			break;
		case 1:
			form = new RobotomyRequestForm(target);
			break;
		case 2:
			form = new PresidentialPardonForm(target);
			break;
		default:
			throw NoParameterException();
	}
	std::cout << "Intern creates " << *form << '\n';
	return form;
}
