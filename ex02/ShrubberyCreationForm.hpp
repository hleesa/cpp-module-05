
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
	ShrubberyCreationForm();

public:
	ShrubberyCreationForm(const std::string target);

	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	~ShrubberyCreationForm();

	void execute(const Bureaucrat& executor) const;
};


#endif //SHRUBBERYCREATIONFORM_HPP
