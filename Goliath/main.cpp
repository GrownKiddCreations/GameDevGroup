
#include <iostream>

#include "Game.h"

using namespace std;


int main(int argc, char** argv)
{
	cout << "Initializing.." << endl;

	Game theGame;

	TileType *air = new TileType("air", true);
	TileType *dirt = new TileType("dirt", false);
	World *theWorld =  new World(30, 22);
	
	for (int i = 0; i < theWorld->getWidth(); ++i)
	{
		for (int j = 0; j < theWorld->getHeight(); ++j)
		{
			//if (j < 3)
				//theWorld->setTile(new Tile(dirt), i, j);
			//else
				theWorld->setTile(new Tile(air), i, j);
		}
	}

	theWorld->setTile(new Tile(dirt), 10, 3);
	std::cout << theWorld->getTile(1,1)->getType()->getName() << std::endl;

	theGame.setWorld(theWorld);
	//delete theWorld;

    Vector2 dudeDim(150,150);
    Vector2 dudePos(0,0);
    Entity test("img/afroDude.png", dudeDim, dudePos, false);
    theGame.entityList.push_back(&test);

	return theGame.OnExecute();

}
