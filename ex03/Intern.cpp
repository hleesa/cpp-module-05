
#include "Intern.hpp"

Intern::NoParameterException::NoParameterException() : errorMessage("The parameter does not exist.") {
}

const char* Intern::NoParameterException::what() const throw() {
	return errorMessage;
}

int nameToIndex(const std::string name) {
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int index = -1;
	for (int i = 0; i < 3; ++i) {
		if (name = formNames[i]){
			index = i;
		}
	}
	return index;
}

AForm* Intern::makeForm(const std::string name, const std::string target) {
	int nameIdx = nameToIndex(name);
	AForm* form;
	if (nameIdx == -1) {
		throw NoParameterException();
	}
	else {

	}
	std::cout << "Intern creates " << '\n';
	return form;
}