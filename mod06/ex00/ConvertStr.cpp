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

	switch(type) {
		case Char:
			std::cout << "char";
			break;
		case Float:
			std::cout << "float";
			break;
		case Double:
			std::cout << "double";
			break;
		case Int:
			std::cout << "int";
			break;
		case Unknown:
			std::cout << "unknown";
			break;
	}
}

bool				ConvertStr::IsChar(const std::string &to_convert) {
	if (to_convert.length() == 1 && std::isdigit(to_convert[0]) != 0)
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
            if (to_convert.find_first_not_of(DIGITS, dot_pos + sign) == to_convert.length() - 1)
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
            if (to_convert.length() > dot_pos + sign && to_convert.find_first_not_of(DIGITS, dot_pos + sign) == std::string::npos)
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

// char		ConvertStr::ConvertToChar(const char *to_convert) {

// }

// int			ConvertStr::ConvertToInt(const char *to_convert);

// float		ConvertStr::ConvertToFloat(const char *to_convert);

// double		ConvertStr::ConvertToDouble(const char *to_convert);