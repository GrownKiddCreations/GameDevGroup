/*
 * SimpleWorldBuilder.cpp
 *
 *  Created on: Jan 21, 2012
 *      Author: Martin
 */

#include "SimpleWorldBuilder.h"

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

	theWorld->setTile(new Tile(dirt), 5, 6);
	theWorld->setTile(new Tile(dirt), 6, 6);
	theWorld->setTile(new Tile(dirt), 7, 6);
	theWorld->setTile(new Tile(dirt), 8, 6);
	theWorld->setTile(new Tile(dirt), 9, 6);

	theWorld->setTile(new Tile(dirt), 12, 9);
	theWorld->setTile(new Tile(dirt), 13, 9);
	theWorld->setTile(new Tile(dirt), 14, 9);
	theWorld->setTile(new Tile(dirt), 15, 9);
	theWorld->setTile(new Tile(dirt), 16, 9);

	theWorld->setTile(new Tile(dirt), 19, 12);
	theWorld->setTile(new Tile(dirt), 20, 12);
	theWorld->setTile(new Tile(dirt), 21, 12);
	theWorld->setTile(new Tile(dirt), 22, 12);
	theWorld->setTile(new Tile(dirt), 23, 12);

	// Init player character
	Entity *pc = new Entity("player","", Vector2(25, 45), Vector2(200, 300), 100.0, false);
	theWorld->addEntity(pc);
	theWorld->setPlayerEntity(pc);

	//init random enemy
	Entity *enemy = new Entity("enemy","", Vector2(10,10), Vector2(200, 400), 10.0, false);
	theWorld->addEntity(enemy);

	return theWorld;
}

void SimpleWorldBuilder::setSize(int width, int height)
{
	mWidth = width;
	mHeight = height;
}

