#pragma once

#include <string>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:

		Intern();
		~Intern();

		Intern(const Intern &other);
		
		Intern	&operator=(const Intern &other);

		static Form *makeForm(const std::string &form_name, const std::string &target);

		static Form *makePresidentalPardonForm(const std::string &target);
		
		static Form *makeRobotomyRequestForm(const std::string &target);

		static Form *makeShrubberyCreationForm(const std::string &target);
};

class FormNotFound : public std::exception {
	const char *what() const throw();
};