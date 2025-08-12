#include "ConvertStr.hpp"

ConvertStr::ConvertStr() {}

ConvertStr::~ConvertStr() {}

ConvertStr::ConvertStr(const ConvertStr &other) {
	(void)other;
}

ConvertStr &ConvertStr::operator=(const ConvertStr &other) {
	(void)other;
	return *this;
}

DataType	ConvertStr::ClassifyString(const std::string &str) {
    if (IsChar(str))
		return Char;
    if (IsFloat(str))
		return Float;
	if (IsDouble(str))
		return Double;
	if (IsInt(str))
		return Int;

	return Unknown;
}

void		ConvertStr::ConvertThenPrint(const std::string &to_convert) {
	DataType type = ClassifyString(to_convert);
    const char *c_str = to_convert.c_str();

	switch(type) {
		case Unknown:
			std::cout << "unknown";
			break;
		default:
			printConverted(c_str);
	}
}

bool				ConvertStr::IsChar(const std::string &to_convert) {
	if (to_convert.length() == 1 && std::isprint(to_convert[0]) != 0)
		return true;
	return false;
}

bool				ConvertStr::IsInt(const std::string &to_convert) {
    if (to_convert.find_first_not_of(DIGITS) == std::string::npos)
	    return true;
    return false;
}


bool				ConvertStr::IsFloat(const std::string &to_convert) {
	if (to_convert.length() < 3)
		return false;
	if (to_convert == "nanf" || to_convert == "-inff" || to_convert == "+inff")
		return true;
	size_t dot_pos = to_convert.find('.');
    if (dot_pos == std::string::npos || to_convert[to_convert.length() - 1] != 'f')
		return false;
    if (to_convert.find_first_of(DIGITS) == std::string::npos)
        return false;
    size_t sign = (to_convert.find_first_of("+-") == std::string::npos) ? 0 : 1;
    switch (dot_pos - sign) {
		case 0:
            if (to_convert.find_first_not_of(DIGITS, 1 + sign) == to_convert.length() - 1)
				return true;
			break;
		default:
            if (to_convert.find_first_not_of(DIGITS, sign) == dot_pos) {
                if (to_convert.find_first_not_of(DIGITS, dot_pos + 1) == to_convert.length() - 1) {
    				return true;
                }
            }
			break;
	}
	return false;
}

bool				ConvertStr::IsDouble(const std::string &to_convert) {
	if (to_convert == "nan" || to_convert == "-inf" || to_convert == "+inf")
		return true;
	size_t dot_pos = to_convert.find('.');
        if (dot_pos == std::string::npos)
		return false;
    size_t sign = (to_convert.find_first_of("+-") == std::string::npos) ? 0 : 1;
    switch (dot_pos - sign) {
		case 0:
            if (to_convert.length() > dot_pos + sign && to_convert.find_first_not_of(DIGITS, 1 + sign) == std::string::npos)
				return true;
			break;
		default:
            if (to_convert.find_first_not_of(DIGITS, sign) == dot_pos) {
                if (to_convert.find_first_not_of(DIGITS, dot_pos + 1) == std::string::npos) {
    				return true;
                }
            }
			break;
	}
	return false;
}

void		ConvertStr::printConverted(const char *to_convert) {
	long double parsed = std::strtold(to_convert, NULL);

	if (std::isprint(static_cast<unsigned char>(parsed))) 
		std::cout << "char: " << static_cast<char>(parsed) << '\n';
	else
		std::cout << "char: impossible" << '\n';	
	if (parsed > INT_MAX || parsed < INT_MIN || parsed != parsed)
		std::cout << "int: impossible" << '\n';
	else
		std::cout << "int: " << static_cast<int>(parsed) << '\n';
    std::cout << std::fixed << std::setprecision(1);
	if ((parsed != POS_INF_F && parsed != NEG_INF_F) && parsed == parsed && (parsed > FLOAT_MAX || parsed < FLOAT_MIN))
		std::cout << "float: impossible" << '\n';
	else
		std::cout << "float: " << static_cast<float>(parsed) << 'f' << '\n';
	if ((parsed != POS_INF_D && parsed != NEG_INF_D) && parsed == parsed && (parsed > DOUBLE_MAX || parsed < DOUBLE_MIN))
		std::cout << "double: impossible" << '\n';
	else
    	std::cout << "double: " << static_cast<double>(parsed) << std::endl;
}
