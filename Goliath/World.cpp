#include <iostream>
#include <exception>
#include <stdexcept>

#include "World.h"

World::World(int width, int height, std::vector<TileType *> &tileTypes)
{
    mWidth = width;
    mHeight = height;

    // copy over tile types
    std::vector<TileType *>::iterator iter;
    for (iter = tileTypes.begin(); iter < tileTypes.end(); iter++)
    {
        mTileTypes.push_back(*iter);
    }

    // build world
    //mMatrix = new std::vector<std::vector<Tile*> *>();
    for (int i = 0; i < mWidth; ++i)
    {
        std::vector<Tile*> *w = new std::vector<Tile*>();

        for (int j = 0; j < mHeight; ++j)
        {
            w->push_back(NULL);
        }

        mMatrix.push_back(w);
    }

    mPlayerEntity = NULL;
}

World::~World()
{
	// clean tile-types
	while (!mTileTypes.empty())
	{
		delete mTileTypes.back();
		mTileTypes.pop_back();
	}

	// clean tiles
    while (!mMatrix.empty())
    {
    	std::vector<Tile*> *w = mMatrix.back();

    	while (!w->empty())
    	{
    		delete w->back();
    		w->pop_back();
    	}

    	delete w;
    	mMatrix.pop_back();
    }

    // clean entities
    std::set<Entity *>::iterator it;
    for (it=mEntitySet.begin(); it!=mEntitySet.end(); ++it)
    {
    	delete *it;
    }
    mEntitySet.erase(mEntitySet.begin(), mEntitySet.end());
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
    try
    {
        std::vector<Tile*> *v = mMatrix.at(x);
        try
        {
            return mMatrix.at(x)->at(y);
        }
        catch (std::out_of_range &e)
        {
            return NULL;
        }
    } catch (std::out_of_range &e)
    {
        return NULL;
    }
}

void World::setTile(Tile* tile, int x, int y)
{
    std::vector<Tile *> * v = mMatrix.at(x);

    // if we are replacing a tile, make sure we clean up
    Tile* oldTile = v->at(y);
    if (oldTile != NULL)
    	delete oldTile;

    // erase old tile
    v->erase(v->begin() + y);

    // insert new tile
    v->insert(v->begin() + y, tile);
}

bool World::addEntity(Entity * entity)
{
    // TODO: check for collisions
    mEntitySet.insert(entity);
    return false;
}

void World::removeEntity(Entity *entity)
{
    mEntitySet.erase(entity);
}

Entity* World::getPlayerEntity() const
{
    return mPlayerEntity;
}

void World::setPlayerEntity(Entity* entity)
{
    mPlayerEntity = entity;
}
