// fn62216_d2_3_vc_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int matrixNumOccurrence(int[6][6], int);

int main()
{
	int matrix[6][6] = {
	{5, 4, 3, 8, 0, 6},
	{9, 4, 5, 1, 0, 2},
	{8, 5, 8, 0, 6, 1},
	{0, 9, 6, 8, 4, 2},
	{6, 1, 0, 2, 6, 1},
	{2, 1, 8, 4, 2, 6}
	};
	int num;
	std::cout << "Enter an integer" << std::endl;
	std::cin >> num;
	if (std::cin.fail())
	{
		std::cout << "Wrong input!" << std::endl;
		return -1;
	}

	std::cout << matrixNumOccurrence(matrix, num);
	return 0;
}

int matrixNumOccurrence(int matrix[6][6], int num)
{
	const int matrixSize = 6;
	int numLength = log10(num) + 1;

	int* digits = new int[numLength];
	int tempNum = num;

	for (int i = numLength - 1; i >= 0; i--)
	{
		digits[i] = tempNum % 10;
		tempNum /= 10;
	}

	//check if the matrix is simplified

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			if ((matrix[i][j] / 10) != 0)
			{
				std::cout << "The matrix is not simplified!" << std::endl;
				return -1;
			}
		}
	}

	//count the occurrences
	int tempRow, tempCol;
	int digitCount = 0;
	int occurrences = 0;

	for (int i = 0; i < matrixSize; i++)
	{
		for (int j = 0; j < matrixSize; j++)
		{
			tempRow = i, tempCol = j, digitCount = 0;

			if (matrix[tempRow][tempCol] == digits[digitCount])
			{
				if (numLength == 1)
				{
					occurrences++;
					continue;
				}

				for (digitCount = 0, tempRow = i, tempCol = j;
					tempRow < matrixSize && 
					digitCount < numLength &&
					matrix[tempRow][tempCol] == digits[digitCount];
					tempRow++, digitCount++);

				if (digitCount == numLength)
				{
					occurrences++;
				}

				for (digitCount = 0, tempRow = i, tempCol = j;
					tempRow >= 0 &&
					digitCount < numLength &&
					matrix[tempRow][tempCol] == digits[digitCount];
					tempRow--, digitCount++);

				if (digitCount == numLength)
				{
					occurrences++;
				}

				for (digitCount = 0, tempRow = i, tempCol = j;
					tempCol < matrixSize &&
					digitCount < numLength &&
					matrix[tempRow][tempCol] == digits[digitCount];
					tempCol++, digitCount++);

				if (digitCount == numLength)
				{
					occurrences++;
				}

				for (digitCount = 0, tempRow = i, tempCol = j;
					tempCol >= 0 &&
					digitCount < numLength &&
					matrix[tempRow][tempCol] == digits[digitCount];
					tempCol--, digitCount++);

				if (digitCount == numLength)
				{
					occurrences++;
				}
			}
		}
	}

	delete[] digits;
	return occurrences;
}

