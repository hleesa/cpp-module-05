
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

public:
	PresidentialPardonForm();

	PresidentialPardonForm(const PresidentialPardonForm& other);

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	~PresidentialPardonForm();

	void execute(Bureaucrat const& executor) const;
};


#endif //PRESIDENTIALPARDONFORM_HPP
