#include "Bureaucrat.hpp"

int main() {
	int	expected_grade = 102;
	int	qualified_grade = 101;
	std::string form_name = "request";
	std::string bureaucrat_name = "Anton";

	try {
		Bureaucrat	b(bureaucrat_name, qualified_grade);
		Form		f(form_name, expected_grade, expected_grade);


		// f.beSigned(b);
		b.signForm(f);

	} catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
