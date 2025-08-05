#include "AForm.hpp"

Form::Form() : _name("Nameless"), _isSigned(false), _minSignGrade(1), _minExecGrade(1) {
	std::cout << "Form standard constructor " << this->getName() << std::endl;
}

Form::Form(const std::string &name, const int &minSignGrade, const int &minExecGrade) : _name(name), _isSigned(false), 
			_minSignGrade(minSignGrade), _minExecGrade(minExecGrade)
{
	std::cout << "Form constructor " << this->getName() << std::endl;
	if (minSignGrade > LowestGrade || minExecGrade > LowestGrade)
		throw GradeTooLowException();
	if (minSignGrade < HighestGrade || _minExecGrade < HighestGrade)
		throw GradeTooLowException();
}

Form::~Form() { 
	std::cout << "~Form destructor " << this->getName() << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), 
		_minSignGrade(other._minSignGrade), _minExecGrade(other._minExecGrade)
{
	std::cout << "Form copy constructor " << this->getName() << std::endl;
}

Form	&Form::operator=(const Form &other) {
	std::cout << "Form copy assignment operator " << this->getName() << std::endl;
	if (this == &other)
		return *this;
	_isSigned = other._isSigned;
	return *this;
}

const std::string &Form::getName() const{ return this->_name; }

bool				Form::getSigned() const { return this->_isSigned; }

const unsigned int	&Form::getMinSignGrade() const { return this->_minSignGrade; }

const unsigned int	&Form::getMinExecGrade() const { return this->_minExecGrade; }

void				Form::beSigned(const Bureaucrat &signer) {
	if (signer.getGrade() > this->_minSignGrade)
		throw GradeTooLowException();
	this->_isSigned = true;
}

std::ostream &operator<<(std::ostream &stream, const Form &obj) {
	stream << obj.getName() << ", form min sign grade " << obj.getMinSignGrade() << ".";
	stream << " Form min exec grade " << obj.getMinExecGrade() << ".";
	if (obj.getSigned() == false)
		stream << " It's not signed." << std::endl;
	else
		stream << " It's signed." << std::endl;

	return stream;
}

const char *FormNotSignedException::what() const throw() {
	return "The form is not signed!";
}

void	Form::execute(const Bureaucrat &executor) const {
	if (this->getSigned == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getMinExecGrade())
		throw GradeTooLowException();
	this->executer();
}
