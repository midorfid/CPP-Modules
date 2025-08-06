#pragma once

#include "AForm.hpp"

class PresidentPardon : public Form {
	private:
		std::string		target_;

	public:
		PresidentPardon();
		~PresidentPardon();

		PresidentPardon(const std::string &target);

		PresidentPardon(const PresidentPardon &other);

		PresidentPardon	&operator=(const PresidentPardon &other);

		void	executer() const;
};
