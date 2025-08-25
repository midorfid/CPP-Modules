#pragma once

#include <string>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <ios>
#include <stdlib.h>
#include <limits>

#define DIGITS "0123456789"
#define FLOAT_MAX 1 << 24
#define FLOAT_MIN std::numeric_limits<float>::min()
#define INT_MAX std::numeric_limits<int>::max()
#define INT_MIN std::numeric_limits<int>::min()
#define DOUBLE_MAX std::numeric_limits<double>::max()
#define DOUBLE_MIN std::numeric_limits<double>::min()
#define POS_INF_D std::numeric_limits<double>::infinity()
#define NEG_INF_D -std::numeric_limits<double>::infinity()
#define POS_INF_F std::numeric_limits<float>::infinity()
#define NEG_INF_F -std::numeric_limits<float>::infinity()

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
	
		static void				printConverted(const char *to_convert);

		static bool				IsChar(const std::string &to_convert);

		static bool				IsInt(const std::string &to_convert);

		static bool				IsFloat(const std::string &to_convert);

		static bool				IsDouble(const std::string &to_convert);
};