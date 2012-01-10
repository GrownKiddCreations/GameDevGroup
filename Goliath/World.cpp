#include "World.h"

World::World(int width, int height)
{
    mWidth = width;
	mHeight = height;
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
