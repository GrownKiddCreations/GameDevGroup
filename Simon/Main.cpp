/*
 * Main.cpp
 *
 *  Created on: Jan 5, 2012
 *      Author: thakidd
 *     Project: Simon (text based)
 */

#include <ctime>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string.h>
#include <iostream>
using namespace std;

const int MAX_GUESS = 50;

#define TERMINALCODE_CLEAR_SCREEN           "\033[2J"
#define TERMINALCODE_RESET_CURSOR_POSITION  "\033[H"

int main(int argc, char **argv)
{
	string value = "";//game string
	string guess = "";//player guess
	bool quit = false;//condition for continuing

	//seed random
	srand(time(NULL));

	int i = 0;
	//main game loop
	while(!quit)
	{
		cout << TERMINALCODE_CLEAR_SCREEN << TERMINALCODE_RESET_CURSOR_POSITION<<"Test\n";
		//create random number and append to string
		int number = rand()%10;

		stringstream out;
		out << number ;
		value += out.str();

		i++;

		for(uint x = 0; x < strlen(value.c_str()); x++)
		{
			cout << value[x] << flush;
		}
		getline(cin,guess);
		sleep(1);

		for(uint y = 0; y < strlen(guess.c_str()); y++)
		{
			if(guess[y]!=value[y])
			{
				cout << "Sorry that guess was incorrect, you lose\n";
				quit = true;
				break;
			}
		}

		if(i >= MAX_GUESS)
		{
			cout << "\nYOU WIN!!!!!" << "\nPress any key to continue";
			cin.get();
		}
	}

	return 0;
}

