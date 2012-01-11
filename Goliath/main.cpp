
#include <iostream>

#include "Game.h"

using namespace std;


int main(int argc, char** argv)
{
	cout << "Initializing.." << endl;


	Game theGame;


    Vector2 dudeDim(150,150);
    Vector2 dudePos(0,0);
    Entity test("img/afroDude.png", dudeDim, dudePos, false);
    theGame.entityList.push_back(&test);

	return theGame.OnExecute();

}
