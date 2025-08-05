#pragma once

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool				_isSigned;
		const unsigned int	_minSignGrade;
		const unsigned int	_minExecGrade;
	
	public:
		Form();
		Form(const std::string &name, const int &minSignGrade, const int &minExecGrade);
		virtual ~Form() {}

		Form(const Form &other);

		Form	&operator=(const Form &other);

		void	beSigned(const Bureaucrat &signer);

		const std::string	&getName() const;
		bool				getSigned() const;
		const unsigned int	&getMinSignGrade() const;
		const unsigned int	&getMinExecGrade() const;

		void				execute(const Bureaucrat &executor) const;

		virtual void		executer() const = 0;
};

std::ostream    &operator<<(std::ostream &stream, const Form &obj);

class FormNotSignedException : std::exception {
	const char *what() const throw();
};