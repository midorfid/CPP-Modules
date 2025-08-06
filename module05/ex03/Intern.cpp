#include "Intern.hpp"

Intern::Intern() { std::cout << "Intern constructor " << std::endl;}
Intern::~Intern() { std::cout << "Intern destructor " << std::endl;}

Intern::Intern(const Intern &other) {
	std::cout << "Intern copy constructor " << std::endl;
	(void)other;
}

Intern	&Intern::operator=(const Intern &other) {
	std::cout << "Intern assignment operator " << std::endl;
	(void)other;
	return *this;
}

Form *Intern::makeForm(const std::string &form_name, const std::string &target) {
	const std::string names[3] = {"PresidentalPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	int i = 0;
	for (; i < 3; ++i) {
		if (names[i] == form_name) { break; }
	}
	switch(i) {
		case 0:
			std::cout << "Intern creates " << form_name << std::endl;
			return makePresidentalPardonForm(target);
		case 1:
			std::cout << "Intern creates " << form_name << std::endl;
			return makeRobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << form_name << std::endl;
			return makeShrubberyCreationForm(target);
		default:
			throw FormNotFound();	
	}
}

Form *Intern::makePresidentalPardonForm(const std::string &target) {
	return new PresidentPardon(target);
}

Form *Intern::makeRobotomyRequestForm(const std::string &target) {
	return new RobotomyRequest(target);
}

Form *Intern::makeShrubberyCreationForm(const std::string &target) {
	return new ShrubberyCreation(target);
}

const char *FormNotFound::what() const throw() {
	return "Form not found!";
}
