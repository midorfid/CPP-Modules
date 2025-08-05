#include "PresidentialPardonForm.hpp"

PresidentPardon::PresidentPardon() : Form("President Pardon", 25, 5), target_("unknown") { std::cout << "PresidentPardon constructor" << std::endl; }

PresidentPardon::~PresidentPardon() { std::cout << "PresidentPardon destructor" << std::endl; }

PresidentPardon::PresidentPardon(const std::string &target) : Form("President Pardon", 25, 5), target_(target) {
	std::cout << "PresidentPardon constructor" << std::endl;
}

PresidentPardon::PresidentPardon(const PresidentPardon &other) : Form(other), target_(other.target_) {
	std::cout << "PresidentPardon copy constructor" << std::endl;
}

PresidentPardon		&PresidentPardon::operator=(const PresidentPardon &other) {
	std::cout << "PresidentPardon assignment operator" << std::endl;
	Form::operator=(other);

	return *this;
}

void	PresidentPardon::executer() const{
	std::cout << "The " << this->target_ << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
