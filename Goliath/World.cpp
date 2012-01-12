#include "World.h"


World::World(int width, int height)
{
    mWidth = width;
	mHeight = height;

	mMatrix = new Tile**[mWidth];	
	for (int i = 0; i < mWidth; ++i)
	{
		mMatrix[i] = new Tile*[mHeight];		
		for (int j = 0; j < mHeight; ++j)
		{
			mMatrix[i][j] = NULL;
		}	
	}
}

World::~World()
{
	for (int i = 0; i < mWidth; ++i)
	{		
		for (int j = 0; j < mHeight; ++j)
		{
			delete mMatrix[i][j];
		}	
		delete [] mMatrix[i];
	}
	delete [] mMatrix;
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
	return mMatrix[x][y];
}

void World::setTile(Tile* tile, int x, int y)
{
	mMatrix[x][y] = tile;
}

void World::setEntities(std::vector <Entity*> entities)
{
    mEntities = entities;
}

std::vector <Entity*> World::getEntities()
{
    return mEntities;
}
