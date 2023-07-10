
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
		if (name == formNames[i]) {
			index = i;
		}
	}
	return index;
}

AForm* Intern::makeForm(const std::string name, const std::string target) {
	typedef AForm* (* FormCreator)(const std::string);
	const FormCreator creators[] = {
			&AForm::createShrubberyCreationForm,
			&AForm::createRobotomyRequestForm,
			&AForm::createPresidentialPardonForm
	};
	const int numCreators = sizeof(creators) / sizeof(creators[0]);
	int nameIdx = nameToIndex(name);
	if (nameIdx < 0 || nameIdx >= numCreators) {
		throw NoParameterException();
	}
	AForm* form = creators[nameIdx](target);
	std::cout << "Intern creates " << *form;
	return form;
}
