#pragma once

#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>

#define DIGITS "0123456789"

enum DataType {
	Char,
	Int,
	Float,
	Double,
	Unknown,
};

class ConvertStr {
	public:
		ConvertStr();
		~ConvertStr();

		ConvertStr(const ConvertStr &other);

		ConvertStr &operator=(const ConvertStr &other);

		static void		ConvertThenPrint(const std::string &to_convert);

	private:
		static DataType	ClassifyString(const std::string &to_convert);
	
		// static char				ConvertToChar(const char *to_convert);

		// static int				ConvertToInt(const char *to_convert);

		// static float			ConvertToFloat(const char *to_convert);

		// static double			ConvertToDouble(const char *to_convert);

		static bool				is_a_digit(const char &c);

		static bool				IsChar(const std::string &to_convert);

		static bool				IsInt(const std::string &to_convert);

		static bool				IsFloat(const std::string &to_convert);

		static bool				IsDouble(const std::string &to_convert);
};
