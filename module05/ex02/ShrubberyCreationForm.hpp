#pragma once

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreation : public Form {
	private:
		std::string		target_;

	public:
		ShrubberyCreation();
		~ShrubberyCreation();

		ShrubberyCreation(const std::string &target);

		ShrubberyCreation(const ShrubberyCreation &other);

		ShrubberyCreation	&operator=(const ShrubberyCreation &other);

		void	executer() const;
};
