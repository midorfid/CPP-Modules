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

DataType	&ConvertStr::ClassifyString(const std::string &str) {
	if (IsFloat(str))
		return DataType::Float;
	if (IsDouble(str))
		return DataType::Double;
	if (IsChar(str))
		return DataType::Char;
	if (IsInt(str))
		return DataType::Int;

	return DataType::Unknown;
}

void		ConvertStr::ConvertThenPrint(const std::string &to_convert) {
	DataType type = ClassifyString(to_convert);

	switch(type) {
		case DataType::Char:
			break;
		case DataType::Int:
			break;
		case DataType::Float:
			break;
		case DataType::Double:
			break;
		case DataType::Unknown:
			break;
	}
}

bool				IsChar(const std::string &to_convert) {
	if (to_convert.length() > 1 && std::isdigit(to_convert[0]) == 0)
		return false;
}

bool				IsInt(const char *to_convert);

bool				IsFloat(const std::string &to_convert) {
	const char *c_str = to_convert.c_str();
	const size_t dot_idx = to_convert.find('.');
	if (dot_idx == std::string::npos)
		return false;
	
	long double parsed = std::strtold(c_str);
}

bool				IsDouble(const char *to_convert);

// char		ConvertStr::ConvertToChar(const char *to_convert) {

// }

// int			ConvertStr::ConvertToInt(const char *to_convert);

// float		ConvertStr::ConvertToFloat(const char *to_convert);

// double		ConvertStr::ConvertToDouble(const char *to_convert);