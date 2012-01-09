/*
*
 * Author: Juliano Schroeder
 * Project: Text Based Simon Game
 * 5 Jan 2012


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

const int MAX_ITEMS = 27;

#define TERMINALCODE_CLEAR_SCREEN           "\033[2J"
#define TERMINALCODE_RESET_CURSOR_POSITION  "\033[H"

int main(int argc, char** argv)
{
	char itemBank[MAX_ITEMS] = "abcdefghijklmnopqrstuwvxyz";
	std::vector<char> generatedItems;
	int maxLevelItems = 3;
	int currentLevelTimeUSec = 2000000;
	bool guessingRight = true;

	 New random seed
	std::srand((unsigned)time(0));

	 Initial items
	int i;
	for (i = 0; i < maxLevelItems; i++)
	{
		int newItemIndex = (MAX_ITEMS - 1) * (std::rand()/(RAND_MAX + 1.0));
		generatedItems.push_back(itemBank[newItemIndex]);
	}

	while (guessingRight)
	{
		std::cout << TERMINALCODE_CLEAR_SCREEN << TERMINALCODE_RESET_CURSOR_POSITION << "Sitext Memory Game" << std::endl << std::flush;
		sleep(1);
		for (i = 0; i < maxLevelItems; i++)
		{
			std::cout << "\r" << generatedItems[i] << std::flush;
			usleep(currentLevelTimeUSec);
			std::cout << "\b\b" << std::flush;
		}

		std::cout << "\r " << std::flush;
		std::cout << std::endl << "Let's get it on!! Press enter after each character" << std::endl;

		for (i = 0; i < maxLevelItems && guessingRight; i++)
		{
			char typedItem;
			std::cin >> typedItem;
			std::cout << "\b\b" << std::flush;

			if (generatedItems[i] != typedItem)
			{
				std::cout << std::endl << "Bang! You're dead!" << std::endl;
				std::cout << std::endl << "Max Level Reached: " << maxLevelItems << std::endl;
				guessingRight = false;
			}
		}

		 Adding another item
		int newItemIndex = (MAX_ITEMS - 1) * (std::rand()/(RAND_MAX + 1.0));
		generatedItems.push_back(itemBank[newItemIndex]);
		maxLevelItems++;

		 Let's speed it up to half a second max
		currentLevelTimeUSec = (currentLevelTimeUSec <= 500000) ? 500000 : currentLevelTimeUSec - 200000;
	}

	return 0;
}
*/
