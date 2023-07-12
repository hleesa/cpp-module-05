
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", "none", 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target)
		: AForm("ShrubberyCreationForm", target, 145, 137) {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		AForm::operator=(other);
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void writeASCIITrees(std::string target) {
	std::string fileName = target + "_shrubbery";
	std::ofstream outputFile(fileName.c_str());

	if (outputFile.is_open()) {
		outputFile << "         *" << std::endl;
		outputFile << "        ***" << std::endl;
		outputFile << "       *****" << std::endl;
		outputFile << "      *******" << std::endl;
		outputFile << "     *********" << std::endl;
		outputFile << "    ***********" << std::endl;
		outputFile << "   *************" << std::endl;
		outputFile << "  ***************" << std::endl;
		outputFile << " *****************" << std::endl;
		outputFile << "*******************" << std::endl;
		outputFile << "        |||" << std::endl;

		outputFile.close();
		std::cout << "Tree shape has been written to the file " << fileName << std::endl;
	}
	else {
		std::cout << "Unable to open the file." << std::endl;
	}
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
	if (isExecutable(executor)) {
		writeASCIITrees(getTarget());
	}
}