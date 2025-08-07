#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main() {
	int	qualified_grade = 1;
	std::string bureaucrat_name = "Anton";

	try {
		Bureaucrat				b(bureaucrat_name, qualified_grade);
		ShrubberyCreation		pres;

		Form *f = Intern::makeForm("RobotomyRequestForm", "Anton");
		f->beSigned(b);
		f->execute(b);
		delete f;
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
