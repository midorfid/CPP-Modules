#include "ShrubberyCreationForm.hpp"

ShrubberyCreation::ShrubberyCreation() : Form("Shrubbery Creation", 72, 45), target_("unknown") { std::cout << "ShrubberyCreation constructor" << std::endl; }

ShrubberyCreation::~ShrubberyCreation() { std::cout << "ShrubberyCreation destructor" << std::endl; }

ShrubberyCreation::ShrubberyCreation(const std::string &target) : Form("Shrubbery Creation", 72, 45), target_(target) {
	std::cout << "ShrubberyCreation constructor" << std::endl;
}

ShrubberyCreation::ShrubberyCreation(const ShrubberyCreation &other) : Form(other), target_(other.target_) {
	std::cout << "ShrubberyCreation copy constructor" << std::endl;
}

ShrubberyCreation		&ShrubberyCreation::operator=(const ShrubberyCreation &other) {
	std::cout << "ShrubberyCreation assignment operator" << std::endl;
	Form::operator=(other);

	return *this;
}

void	ShrubberyCreation::executer() const{
	std::ofstream outputFile((this->target_ + "_shrubbery").c_str());
	if (!outputFile.is_open()) {
		throw 1;
	}
	for (int i = 0; i < 3;++i) {
		outputFile << "\\...._/\n";
		outputFile << ".\\../\n";
		outputFile << "..\\|./\n" ;
		outputFile << "...|/\n";
		outputFile << "...|\n";
	}
}
