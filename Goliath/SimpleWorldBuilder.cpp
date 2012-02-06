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

	TileType* air = new TileType("AIR", true);
	TileType* dirt = new TileType("DIRT", false);

	tileTypes.push_back(air);
	tileTypes.push_back(dirt);

	World *theWorld =  new World(mWidth, mHeight, tileTypes);

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

	for (int i = 0; i < mWidth / 8; ++i)
	{
		if (i % 2 == 0)
		{
			int base = i * 8;
			int height = (rand() % 3) + 5;

			int length = (rand() % 3) + 4;

			for (int j = 0; j < length; ++j)
			{
				theWorld->setTile(new Tile(dirt), base + j , height);
			}
		}
	}

	for (int i = 0; i < mWidth / 12; ++i)
	{
		if (i % 2 == 0)
		{
			int base = i * 12;
			int height = (rand() % 3) + 10;

			int length = (rand() % 3) + 4;

			for (int j = 0; j < length; ++j)
			{
				theWorld->setTile(new Tile(dirt), base + j , height);
			}
		}
	}

	// Init player character
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

