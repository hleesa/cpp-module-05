
#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

private:
	static const std::string name;
	static const int gradeForSign;
	static const int gradeForExecute;

public:
	PresidentialPardonForm();

	PresidentialPardonForm(const PresidentialPardonForm& other);

	PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

	~PresidentialPardonForm();

	void execute(Bureaucrat const& executor) const;
};


#endif //PRESIDENTIALPARDONFORM_HPP
