
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <cstdlib>
#include <ctime>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

private:
	RobotomyRequestForm();

public:
	RobotomyRequestForm(const std::string target);

	RobotomyRequestForm(const RobotomyRequestForm& other);

	RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

	~RobotomyRequestForm();

	void execute(Bureaucrat const& executor) const;

};


#endif //ROBOTOMYREQUESTFORM_HPP
