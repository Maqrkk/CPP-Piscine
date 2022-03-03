#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>
#include <cfloat>

enum		eInputType
{
	inputChar,
	inputInt,
	inputFloat,
	inputDouble,
	inputSpecial,
	inputOther
};

int			getPrintPrecision(std::string value)
{
	// Helper function to determine the precision with which to print
	// floats and doubles.
	int		precision;

	precision = value.length() - value.find(".") - 1;
	if (value[value.length() - 1] == 'f')
		precision -= 1;
	return precision;
}

void		printChar(double num)
{
	// This function will convert a double to a char and see if it is
	// printable.
	char		c;

	std::cout << "char: ";
	if (num < 0 || num > 127)
	{
		std::cout << "impossible" << std::endl;
		return ;
	}
	c = static_cast<char>(num);
	if (isprint(c))
		std::cout << c << std::endl;
	else
		std::cout << "Non displayable" << std::endl;
}

void		printInt(double num)
{
	// This will simply print a number as an integer, if it is within
	// the range of an int.
	std::cout << "int: ";
	if (num < INT_MIN || num > INT_MAX)
		std::cout << "impossible" << std::endl;
	else
		std::cout << static_cast<int>(num) << std::endl;
}

void		printDoubles(double num, int precision)
{
	// This will print a number as a float and a double.
	std::cout << "float: ";
	if (num < -FLT_MAX || num > FLT_MAX)
	{
		std::cout << "impossible" << std::endl;
	}
	else
	{
		std::cout << std::fixed << std::setprecision(precision);
		std::cout << static_cast<float>(num) << "f" << std::endl;
	}
	std::cout << "double: " << std::fixed << std::setprecision(precision);
	std::cout << num << std::endl;
}

void		printNumber(std::string originalValue, eInputType inputType)
{
	std::stringstream	original(originalValue);
	int					floatPrecision;
	double				num;

	if (inputType == inputChar || inputType == inputInt)
		floatPrecision = 1;
	else
		floatPrecision = getPrintPrecision(originalValue);
	if (inputType == inputChar)
	{
		char	c = originalValue[0];
		num = static_cast<double>(c);
	}
	else
		original >> num;
	printChar(num);
	printInt(num);
	printDoubles(num, floatPrecision);
}

void		printSpecial(std::string originalValue)
{
	// This function simply handles the 'special' cases of inf and nan and
	// their variations.
	std::string		testValue;

	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (originalValue[0] == '+')
		originalValue = originalValue.substr(1);
	testValue = originalValue;
	if (testValue[0] == '-')
		testValue = testValue.substr(1);
	if (testValue == "nanf" || testValue == "inff")
	{
		std::cout << "float: " << originalValue << std::endl;
		std::cout << "double: " << originalValue.substr(0, originalValue.length() - 1) << std::endl;
	}
	else
	{
		std::cout << "Float: " << originalValue << "f" << std::endl;
		std::cout << "double: " << originalValue << std::endl;
	}
}

void		printOther()
{
	std::cout << "Input not recognized as a valid type." << std::endl;
}

eInputType	checkInputType(std::string value)
{
	bool	sign;
	int		numPeriods;
	bool	allDecimals;
	bool	endsWithF;

	numPeriods = 0;
	allDecimals = true;
	sign = false;
	// First check if our input is one of these special types.
	if (value == "nanf" || value == "nan")
		return inputSpecial;
	if (value == "inf" || value == "inff" || value == "-inf" || value == "-inff" || value == "+inf" || value == "+inff")
		return inputSpecial;
	// Check if the input is 'signed'.
	if (value[0] == '-' || value[0] == '+')
	{
		// Special case: if the input is ONLY - or +, we're dealing with a char.
		if (value.length() == 1)
			return inputChar;
		sign = true;
		value = value.substr(1);
	}
	// This loop will set a few variables from which we can determine the type
	// of input given.
	for (size_t i = 0; i < value.length(); i++)
	{
		if (value[i] == '.')
			numPeriods++;
		if (i == value.length() - 1)
			endsWithF = (value[i] == 'f');
		if (!std::isdigit(value[i]) && value[i] != '.' &&
				!(i == value.length() - 1 && value[i] == 'f'))
			allDecimals = false;
	}
	if (allDecimals && !endsWithF && numPeriods == 0)
		return inputInt;
	else if (value.length() == 1 && sign == false)
		return inputChar;
	else if (allDecimals && numPeriods == 1 && endsWithF)
		return inputFloat;
	else if (allDecimals && numPeriods == 1)
		return inputDouble;
	return inputOther;
}

int			main(int argc, char **argv)
{
	std::string		originalValue;
	eInputType		inputType;

	// Quick error check to see if the amount of arguments is correct.
	if (argc != 2)
	{
		std::cout << "Please provide one (and only one) parameter to the program." << std::endl;
		return 0;
	}

	// Cast the string from char** to std::string.
	originalValue = static_cast<std::string>(argv[1]);
	// Check the type of input we've gotten.
	inputType = checkInputType(originalValue);
	// Call the correct function for printing the type of input given.
	if (inputType == inputSpecial)
		printSpecial(originalValue);
	else if (inputType == inputOther)
		printOther();
	else
	{
		// If the input has a trailing f (for double), we cut it off, because
		// we do not need it.
		if (originalValue[originalValue.length() - 1] == 'f' && inputType != inputChar)
			originalValue = originalValue.substr(0, originalValue.length() - 1);
		printNumber(originalValue, inputType);
	}
}
