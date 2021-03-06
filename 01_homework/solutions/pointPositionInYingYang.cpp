/**
*

* Solution to homework task 5
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Zahari Zvezdomirov
* @idnumber 62216
* @task 5
* @compiler vc
*
*/

#include <iostream>
#include <cmath>

int main()
{
	const short int BIG_CIRCLE_RADIUS = 6, 
		MIDDLE_HALF_CIRCLE_RADIUS = 3,
		SMALL_CIRCLE_RADIUS = 1;

	double x = 0, y = 0;
	bool inputIsCorrect = false;

	//Take and validate the input
	do
	{
		std::cout << "Enter X and Y coordinates: " << std::endl;
		std::cin >> x;
		std::cin >> y;

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Wrong input!" << std::endl;
			continue;
		}
		
		inputIsCorrect = true;
	} while (!inputIsCorrect);

	/*The concept is that I first determine whether the
	point is in the big circle, then I have two logically
	identical cases for whether the point is in the top or the 
	bottom half. For both of them I use kind of a "new" coordinate system,
	beggining from the center of the small upper(lower) circle.
	Thats why I have different coordinate and radius values*/

	double distanceFromCenter = sqrt(x*x +y*y);

	double yFromSmallCircle = y - MIDDLE_HALF_CIRCLE_RADIUS;
	double xFromSmallCircle = x;
	double distanceFromSmallCenter = sqrt(
		xFromSmallCircle * xFromSmallCircle 
		+ yFromSmallCircle * yFromSmallCircle
		);

	if (distanceFromCenter < 6)
	{
		if (y >= 0)
		{
			//We handle the case where the dot is in the top half of the circle

			if (xFromSmallCircle >= 0)
			{
				/*That means we are in the right half with more chance for the point
				to be in a black space*/
				if (distanceFromSmallCenter > 3)
				{
					std::cout << "Black" << std::endl;
				}
				else if (distanceFromSmallCenter == 3)
				{
					std::cout << "Undefined" << std::endl;
				}
				else
				{
					if (distanceFromSmallCenter > 1)
					{
						std::cout << "White" << std::endl;
					}
					else if (distanceFromSmallCenter == 1)
					{
						std::cout << "Undefined" << std::endl;
					}
					else
					{
						std::cout << "Black" << std::endl;
					}
				}
			}
			else if (xFromSmallCircle < 0)
			{
				//Now let's look at the top-left half
				if (distanceFromSmallCenter > 1)
				{
					std::cout << "White" << std::endl;
				}
				else if (distanceFromSmallCenter == 1)
				{
					std::cout << "Undefined" << std::endl;
				}
				else
				{
					std::cout << "Black" << std::endl;
				}
			}
		}

		/*The next fragment is logically identical to the one above,
		just reversed for the bottom half where the colors are 
		exchanged (look at the picture again if
		you are confused)*/

		else if (y < 0)
		{
			if (xFromSmallCircle < 0)
			{
				if (distanceFromSmallCenter > 3)
				{
					std::cout << "White" << std::endl;
				}
				else if (distanceFromSmallCenter == 3)
				{
					std::cout << "Undefined" << std::endl;
				}
				else
				{
					if (distanceFromSmallCenter > 1)
					{
						std::cout << "Black" << std::endl;
					}
					else if (distanceFromSmallCenter == 1)
					{
						std::cout << "Undefined" << std::endl;
					}
					else
					{
						std::cout << "White" << std::endl;
					}
				}
			}
			else if (xFromSmallCircle >= 0)
			{
				//Now let's look at the top-left half
				if (distanceFromSmallCenter > 1)
				{
					std::cout << "Black" << std::endl;
				}
				else if (distanceFromSmallCenter == 1)
				{
					std::cout << "Undefined" << std::endl;
				}
				else
				{
					std::cout << "White" << std::endl;
				}
			}
		}
	} 
	else if (distanceFromCenter == 6)
	{
	std::cout << "Undefined" << std::endl;
	}
	else
	{
	std::cout << "Outside" << std::endl;
	}
	return 0;

}
