#include "RobotomyRequestForm.hpp"

RobotomyRequest::RobotomyRequest() : Form("Robotomy Request", 72, 45), target_("unknown") { std::cout << "RobotomyRequest constructor" << std::endl; }

RobotomyRequest::~RobotomyRequest() { std::cout << "RobotomyRequest destructor" << std::endl; }

RobotomyRequest::RobotomyRequest(const std::string &target) : Form("Robotomy Request", 72, 45), target_(target) {
	std::cout << "RobotomyRequest constructor" << std::endl;
}

RobotomyRequest::RobotomyRequest(const RobotomyRequest &other) : Form(other), target_(other.target_) {
	std::cout << "RobotomyRequest copy constructor" << std::endl;
}

RobotomyRequest		&RobotomyRequest::operator=(const RobotomyRequest &other) {
	std::cout << "RobotomyRequest assignment operator" << std::endl;
	Form::operator=(other);

	return *this;
}

void	RobotomyRequest::executer() const{
	std::cout << " 	VREEEEEEEEE...KRRRRSHHHHH...BZZZZZZZZZZZZZZZZT	—SKREEEEEEE!—	bzt... bzt...whirrr-click." << std::endl;
	std::srand(std::time(0));
	if (rand() % 2 == 0)
		std::cout << "The " << this->target_ << " has been robotomized successfully." << std::endl;
	else
		std::cout << "The robotomy failed." << std::endl;
}
