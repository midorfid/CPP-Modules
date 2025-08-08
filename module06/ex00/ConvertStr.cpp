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
	if (IsFloat(str))
		return Float;
	if (IsDouble(str))
		return Double;
	if (IsChar(str))
		return Char;
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
	if (std::isdigit(to_convert[to_convert.length() - 1]) == 0)
		return false;
	return true;
}

bool				ConvertStr::is_a_digit(const char &c) {
	return std::isdigit(c);
}

bool				ConvertStr::IsFloat(const std::string &to_convert) {
	if (to_convert.length() < 3)
		return false;
	if (to_convert == "nanf" || to_convert == "-inff" || to_convert == "+inff")
		return true;
	if (to_convert.find('.') == std::string::npos || to_convert[to_convert.length() - 1] != 'f')
		return false;
	std::string::const_iterator start = to_convert.begin() + std::string::npos + 1;
	std::string::const_iterator end = to_convert.end() - 1;
	switch (std::string::npos) {
		case 0:
			if (std::find_if(start, end, is_a_digit) == end)
				return true;
			break;
		default:
			if (std::find_if(start, end, is_a_digit) == end)
				return true;
			break;
	}
	return false;
}

bool				ConvertStr::IsDouble(const std::string &to_convert) {
	if (to_convert == "nanf" || to_convert == "-inff" || to_convert == "+inff")
		return true;
	if (to_convert.find('.') == std::string::npos)
		return false;
	std::string::const_iterator start = to_convert.begin() + std::string::npos + 1;
	std::string::const_iterator end = to_convert.end();
	switch (std::string::npos) {
		case 0:
			if (std::find_if(start, end, is_a_digit) == end)
				return true;
			break;
		default:
			if (std::find_if(start, end, is_a_digit) == end)
				return true;
			break;
	}
	return false;
}

// char		ConvertStr::ConvertToChar(const char *to_convert) {

// }

// int			ConvertStr::ConvertToInt(const char *to_convert);

// float		ConvertStr::ConvertToFloat(const char *to_convert);

// double		ConvertStr::ConvertToDouble(const char *to_convert);