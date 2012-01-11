
#include <iostream>

#include "Game.h"

using namespace std;


int main(int argc, char** argv)
{
	cout << "Initializing.." << endl;

	Game theGame;

	World theWorld(10, 10);

    Number2D dudeDim(150,150);
    Number2D dudePos(0,0);
    Entity test("img/afroDude.png", dudeDim, dudePos, false);
    theGame.entityList.push_back(&test);

	return theGame.OnExecute();

}
