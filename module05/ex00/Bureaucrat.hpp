#pragma once

#include <string>
#include <iostream> 
#include <exception> 

#define HighestGrade 1
#define LowestGrade 150

class Bureaucrat {
    private:
        const std::string   _name;
        unsigned int		_grade;

    public:
        Bureaucrat();
        Bureaucrat(const std::string &name, const int &grade);
        ~Bureaucrat();

		Bureaucrat(const Bureaucrat &other);

		Bureaucrat &operator=(const Bureaucrat &other);

        const std::string       &getName() const;
        const  unsigned int     &getGrade() const;

		void				IncrementGrade();
		void				DecrementGrade();

        class GradeTooHighException : public std::exception {
            const char *what() const throw();
        };

        class GradeTooLowException : public std::exception {
            const char *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &stream, const Bureaucrat &obj);
