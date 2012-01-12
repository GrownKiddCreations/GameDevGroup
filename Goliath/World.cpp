#include "World.h"


World::World(int width, int height)
{
    mWidth = width;
	mHeight = height;

	mMatrix = new std::vector< std::vector< Tile* > *>();
	for (int i = 0; i < mWidth; ++i)
	{
		std::vector< Tile* > *w = new std::vector< Tile* >();
		
		for (int j = 0; j < mHeight; ++j)
		{
			w->push_back(NULL);
		}
		
		mMatrix->push_back(w);
	}
}

World::~World()
{
	for (int i = 0; i < mWidth; ++i)
	{
		delete mMatrix->at(i);
	}
	delete mMatrix;
}

int World::getWidth()
{
	return mWidth;
}

int World::getHeight()
{
	return mHeight;
}

Tile* World::getTile(int x, int y)
{
	return mMatrix->at(x)->at(y);
}

void World::setTile(Tile* tile, int x, int y)
{
	std::vector< Tile *> * v = mMatrix->at(x);
	v->insert(v->begin() + y, tile);
}

void World::setEntities(std::vector <Entity*> entities)
{
    mEntities = entities;
}

std::vector <Entity*> World::getEntities()
{
    return mEntities;
}
