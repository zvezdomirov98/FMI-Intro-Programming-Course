/**
*

* Solution to homework task 4
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Zahari Zvezdomirov
* @idnumber 62216
* @task 4
* @compiler vc
*
*/

#include <iostream>
#include <iomanip>

int main()
{
	const short int ROWS = 25;
	char symbol = 0;
	std::cout << "Enter a symbol: " << std::endl;
	std::cin >> symbol;

	//Print the top half of the square
	for (int i = 1; i < ROWS/2; i++)
	{
		for (int space = 0; space < ROWS/2 - i; space++)
		{
			std::cout << "  ";
		}
		std::cout << std::setw(30);
		for (int j = i; j <= 2 * i - 1; j++)
			std::cout << symbol << " ";

		for (int j = 0; j < i - 1; j++)
			std::cout << symbol << " ";

		std::cout << std::endl;
	}

	//Print the bottom half of the square
	for (int i = ROWS/2; i >= 1; i--)
	{
		for (int space = 0; space < ROWS/2 - i; space++)
			std::cout << "  ";

		std::cout << std::setw(30);
		for (int j = i; j <= 2 * i - 1; j++)
			std::cout << symbol << " ";

		for (int j = 0; j < i - 1; j++)
			std::cout << symbol << " ";
			
		std::cout << std::endl;
	}
}