#pragma once

#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdlib.h>
#include <limits.h>

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
	
		static void				ConvertToChar(const std::string &to_convert);

		static void				ConvertToInt(const char *to_convert);

		static void			ConvertToFloat(const char *to_convert);

		static void			ConvertToDouble(const char *to_convert);


		static bool				IsChar(const std::string &to_convert);

		static bool				IsInt(const std::string &to_convert);

		static bool				IsFloat(const std::string &to_convert);

		static bool				IsDouble(const std::string &to_convert);
};