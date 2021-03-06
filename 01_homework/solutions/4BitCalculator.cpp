/**
*

* Solution to homework task 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Zahari Zvezdomirov
* @idnumber 62216
* @task 3
* @compiler vc
*
*/

#include <iostream>
#include <climits>
#include <cmath>
#include <bitset>

int main()
{
	const unsigned short int CALCULATOR_NUM_OF_BITS = 4,
		RANGE_LOWER_LIMIT = 0,
		/*Don't change the lower limit, it has to be zero.
						 I defined it just for a better code readability*/
		RANGE_UPPER_LIMIT = pow(2, CALCULATOR_NUM_OF_BITS) - 1,
		NUMBER_OF_DEFINED_OPERATIONS = 3;

	unsigned short int a = 0, b = 0,
		operation = 0;
	short int result = 0;

	bool inputIsValid = false;

	//initializing the variables and checking if the input is correct
	do
	{
		std::cout << "Enter two 4-bit non-negative integers and an operation" << std::endl;
		std::cin >> a;
		std::cin >> b;
		std::cin >> operation;

		if (std::cin.fail() ||
			(a < RANGE_LOWER_LIMIT || a > RANGE_UPPER_LIMIT) ||
			(b < RANGE_LOWER_LIMIT || b > RANGE_UPPER_LIMIT) ||
			(operation < 0 || operation > NUMBER_OF_DEFINED_OPERATIONS))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong input!" << std::endl;
			continue;
		}

		inputIsValid = true;

	} while (!inputIsValid);

	//do the desired operation
	switch (operation)
	{
	case 0:
		result = a + b;
		if (result > 15)
		{
			result -= 16;
		}
		break;

	case 1:
		result = a - b;
		if (result < 0)
		{
			result += 16;
		}
		break;

	case 2:
		result = a * b;
		if (result > 15)
		{
			result %= 16;
		}
		break;

	case 3:
		if (b == 0)
		{
			std::cout << "Can't divide by zero!" << std::endl;
			return -1;
		}
		result = a / b;
		break;

	default:
		break;
	}

	/*The variable is unsigned short int, but the input is verified
	so that the decimalResult won't overflow. It's casted to ulong,
	because there is no ushort cast function. */

	std::cout << result << std::endl;

	return 0;
}