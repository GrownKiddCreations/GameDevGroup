/*
 * SimpleWorldBuilder.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: Martin
 */

#include "SimpleWorldBuilder.h"

#include <stdlib.h>

SimpleWorldBuilder::SimpleWorldBuilder(int width, int height)
{
	setSize(width, height);
}

SimpleWorldBuilder::~SimpleWorldBuilder(void)
{

}

World* SimpleWorldBuilder::build(void)
{
	std::vector<TileType *> tileTypes;

	// create set of tile types used in this world
	TileType* air = new TileType("AIR", true, false);
	TileType* dirt = new TileType("DIRT", false, false);
	TileType* cloud = new TileType("CLOUD", true, true);

	tileTypes.push_back(air);
	tileTypes.push_back(dirt);
	tileTypes.push_back(cloud);

	World *theWorld =  new World(mWidth, mHeight, tileTypes);

	// ground
	for (int i = 0; i < theWorld->getWidth(); ++i)
	{
		for (int j = 0; j < theWorld->getHeight(); ++j)
		{
			if (j < 3)
				theWorld->setTile(new Tile(dirt), i, j);
			else
				theWorld->setTile(new Tile(air), i, j);
		}
	}

	// generate some clouds
	for (int i = 0; i < mWidth / 16; ++i)
	{
		if (i % 2 == 0)
		{
			int base = i * 16;
			int height = (rand() % 5) + 5;

			int length = (rand() % 4) + 8;

			theWorld->setTile(new Tile(cloud), base , height);

			for (int j = 0; j < length; ++j)
			{
				theWorld->setTile(new Tile(cloud), base + j , height);
			}
		}
	}

	// create player character
	Entity *pc = new Entity("player","", 50.0, 60.0, 30.0, 30.0, 100.0, false);
	theWorld->addEntity(pc);
	theWorld->setPlayerEntity(pc);

	//init random enemy
	//Entity *enemy = new Entity("enemy","", 10, 10, 200, 400, 10.0, false);
	//theWorld->addEntity(enemy);

	return theWorld;
}

void SimpleWorldBuilder::setSize(int width, int height)
{
	mWidth = width;
	mHeight = height;
}

