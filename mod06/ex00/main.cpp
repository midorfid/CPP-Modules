#include <string>
#include <iostream>
#include "ConvertStr.hpp"

int main(int argc, char **argv) {
	if (argc != 2)
		return EXIT_FAILURE;
	const std::string to_convert(argv[1]);

	ConvertStr::ConvertThenPrint(to_convert);

	return EXIT_SUCCESS;
}
