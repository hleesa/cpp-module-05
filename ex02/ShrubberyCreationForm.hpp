
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

private:
	static const std::string name;
	static const int gradeForSign;
	static const int gradeForExecute;

public:
	ShrubberyCreationForm();

	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

	~ShrubberyCreationForm();

	void execute(const Bureaucrat& executor) const;
};


#endif //SHRUBBERYCREATIONFORM_HPP
