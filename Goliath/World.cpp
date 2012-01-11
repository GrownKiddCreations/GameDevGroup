#include "World.h"

World::World(int width, int height)
{
    mWidth = width;
	mHeight = height;
	
	std::vector< std::vector<Tile> > matrix;
	
	/*int **matrix = new bool*[width];
	
	for (int i = 0; i < width; ++i)
	{
		for (int j = 0; j < height; ++j)
		{
			matrix[i][j] = false;
		}	
	}*/
}

World::~World()
{

}

int World::getWidth()
{
	return mWidth;
}

int World::getHeight()
{
	return mHeight;
}

bool World::isTilePassable(int x, int y)
{
	return false;
}
