#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
	int	qualified_grade = 1;
	std::string bureaucrat_name = "Anton";

	try {
		Bureaucrat			b(bureaucrat_name, qualified_grade);
		ShrubberyCreation		pres;
		Form				&f = static_cast<Form&>(pres);
		ShrubberyCreation		&pres2 = dynamic_cast<ShrubberyCreation&>(f);

		pres2.beSigned(b);
		pres2.execute(b);
	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
