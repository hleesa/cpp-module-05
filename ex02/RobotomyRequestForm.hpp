
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:
	static const std::string name;
	static const int gradeForSign;
	static const int gradeForExecute;

public:
	RobotomyRequestForm();

	RobotomyRequestForm(const RobotomyRequestForm& other);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	~RobotomyRequestForm();

	void execute(Bureaucrat const& executor) const;

};


#endif //ROBOTOMYREQUESTFORM_HPP
