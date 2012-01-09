/*
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>

using namespace std;

const int ROUNDS = 5;

int main(int argc, char** argv)
{

	string pattern;
	srand (time(NULL));	

	int i = 0;
	while (i < ROUNDS)
	{		
		stringstream ss;
		int rand_int = rand() % 10;

		ss << rand_int;
		cout << rand_int << " ";

		pattern += ss.str();

		string input;
		getline(cin, input);

		if (input != pattern)
		{
			cout << endl << "you lost!" << endl;
			break;
		}

		++i;	
	}

	if (i == ROUNDS)
		cout << "you won!" << endl;

	return 0;

}

*/
