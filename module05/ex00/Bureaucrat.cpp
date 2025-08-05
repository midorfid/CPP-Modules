#include "Bureaucrat.hpp"
#define nullptr NULL

Bureaucrat::Bureaucrat() : _name("Nameless"), _grade(150) {
	std::cout << "Bureaucrat()" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade) : _name(name) {
	std::cout << "Bureaucrat constructor " << this->getName() << std::endl;
	if (grade > LowestGrade)
		throw GradeTooLowException();
	if (grade < HighestGrade)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "~Bureaucrat() " << this->getName() << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other) {
	std::cout << "Bureaucrat copy assignment" << std::endl;
	if (this == &other)
		return *this;
	_grade = other._grade;
	return *this;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	std::cout << "Bureaucrat copy constructor" << std::endl;
}

const std::string &Bureaucrat::getName() const{
	return _name;
}

const unsigned int	&Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::IncrementGrade() {
	if (this->_grade - 1 < 1)
		throw GradeTooHighException();
	--this->_grade;
}

void Bureaucrat::DecrementGrade() {
	if (this->_grade + 1 > 150)
		throw GradeTooLowException();
	++this->_grade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw(){
	return "Grade too high!";
}

const char *Bureaucrat::GradeTooLowException::what() const throw(){
	return "Grade too low!";
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &obj) {
	stream << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;

	return stream;
}