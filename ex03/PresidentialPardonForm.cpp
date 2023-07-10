
#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", "none", 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
		: AForm("PresidentialPardonForm", target, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void pardon(std::string target) {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	if (isExecutable(executor)) {
		pardon(getTarget());
	}
}