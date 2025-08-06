#pragma once

#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequest : public Form {
	private:
		std::string		target_;

	public:
		RobotomyRequest();
		~RobotomyRequest();

		RobotomyRequest(const std::string &target);

		RobotomyRequest(const RobotomyRequest &other);

		RobotomyRequest	&operator=(const RobotomyRequest &other);

		void	executer() const;
};
