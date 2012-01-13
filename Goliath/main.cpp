
#include <iostream>

#include "Game.h"

using namespace std;


int main(int argc, char** argv)
{
	cout << "Initializing.." << endl;

	Game theGame;
	int WORLD_WIDTH = 30;
	int WORLD_HEIGHT = 22;

	TileType *air = new TileType("air", true);
	TileType *dirt = new TileType("dirt", false);
	World *theWorld =  new World(WORLD_WIDTH, WORLD_HEIGHT);
	
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

	theWorld->setTile(new Tile(dirt), 3, 3);

	theGame.setWorld(theWorld);
	//delete theWorld;

    Vector2 dudeDim(150,150);
    Vector2 dudePos(WORLD_WIDTH/2, WORLD_HEIGHT/2);
    Entity *test = new Entity("img/afroDude.png", dudeDim, dudePos, false);
    theGame.entityList.push_back(test);

    theWorld->setEntities(theGame.entityList);

	return theGame.onExecute();

}
