#include "Bureaucrat.hpp"

int main() {
	Bureaucrat b("Anton", 1);
	
	// try {
	// 	Bureaucrat b2("Canton", 0);
	// 	Bureaucrat b3("Danton", 151);
	// 	Bureaucrat b4("Eanton", 150.5); // fails but constructor = delete only after c++11
	// 	Bureaucrat b5("Fanton", -1);
	// } catch(std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// try {
	// 	b.IncrementGrade();
	// 	b.DecrementGrade();
	// 	b.DecrementGrade();
	// } catch(std::exception & e) {
	// 	std::cout << e.what() << std::endl;
	// }

	try {
		Bureaucrat b1("Banton", 100);
	
		Bureaucrat assigned;
		std::cout << assigned << std::endl;
		assigned = b1;
		std::cout << assigned << std::endl;
	} catch(std::exception & e) {
		std::cout << e.what() << std::endl;
	}
}
