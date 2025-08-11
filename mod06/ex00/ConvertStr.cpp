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
		case Char:
            ConvertToChar(to_convert);
			break;
		case Float:
            ConvertToFloat(c_str);
			std::cout << "float";
			break;
		case Double:
            ConvertToDouble(c_str);
			std::cout << "double";
			break;
		case Int:
            ConvertToInt(c_str);
			std::cout << "int";
			break;
		case Unknown:
			std::cout << "unknown";
			break;
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
    std::cout << sign << ' ' << dot_pos << std::endl;
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

void		ConvertStr::ConvertToChar(const std::string &to_convert) {
    std::cout << '\n' << "char: " << to_convert[0] << '\n';
    std::cout << "int: " << static_cast<int>(to_convert[0]) << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(to_convert[0]) << 'f' << '\n';
    std::cout << "double: " << static_cast<double>(to_convert[0]) << std::endl;
}

void			ConvertStr::ConvertToInt(const char *to_convert) {
    long double parsed = std::strtold(to_convert, NULL);
    
    parsed = parsed > INT_MAX ? INT_MAX : parsed; 
    parsed = parsed < INT_MIN ? INT_MIN : parsed;

    if ()
    std::cout << '\n' << "char: " << to_convert[0] << '\n';
    std::cout << "int: " << static_cast<int>(to_convert[0]) << '\n';
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(to_convert[0]) << 'f' << '\n';
    std::cout << "double: " << static_cast<double>(to_convert[0]) << std::endl;
}

void		ConvertStr::ConvertToFloat(const char *to_convert) {}

void		ConvertStr::ConvertToDouble(const char *to_convert) {}