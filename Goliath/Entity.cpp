/*
 * Entity.cpp
 *
 *  Created on: Jan 9, 2012
 *      Author: thakidd
 */

#include "Entity.h"

#include "World.h"
#include "Tile.h"
#include "Vector2.h"

Entity::Entity(std::string filename, Vector2 size, Vector2 position, float mass, bool passable)
{
    mDimension2D = size;
    mPosition2D = position;
    mPassable = passable;

    mMass = mass;
}

Entity::~Entity()
{

}

Vector2 Entity::getDimensions2D()
{
    return mDimension2D;
}

int Entity::getWidth()
{
    return mDimension2D.x;
}

int Entity::getHeight()
{
    return mDimension2D.y;
}

Vector2 Entity::getPosition2D()
{
    return mPosition2D;
}

int Entity::getX()
{
    return mPosition2D.x;
}

int Entity::getY()
{
    return mPosition2D.y;
}

bool Entity::isPassable()
{
    return mPassable;
}

void Entity::setPosition(Vector2 position)
{
    mPosition2D = position;
}

void Entity::setPosition(float x, float y)
{
    mPosition2D.x = x;
    mPosition2D.y = y;
}

void Entity::addForce(float x, float y)
{
	mForce2D.x += x;
	mForce2D.y += y;
}

void Entity::setForce(float x, float y)
{
	mForce2D.x = x;
	mForce2D.y = y;
}

Vector2 Entity::getForce()
{
	return mForce2D;
}

Vector2 Entity::getVelocity()
{
	return mVelocity2D;
}

Vector2 Entity::setVelocity(float x, float y)
{
	mVelocity2D.x = x;
	mVelocity2D.y = y;
}

float Entity::getMass()
{
	return mMass;
}

void Entity::setImpulse(float xd, float yd)
{
	mImpulse2D.x = xd;
	mImpulse2D.y = yd;
}

Vector2 Entity::getImpulse()
{
	return mImpulse2D;
}

int Entity::top()
{
    return mPosition2D.y + mDimension2D.y;
}

int Entity::right()
{
	return mPosition2D.x + mDimension2D.x;
}

int Entity::bottom()
{
    return mPosition2D.y;
}

int Entity::left()
{
    return mPosition2D.x;
}

bool Entity::isOnPlatformDown(World* world)
{
	int bounds[4][2];

	bounds[0][0] = left() / TILE_SIZE;
	bounds[0][1] = top() / TILE_SIZE;

	bounds[1][0] = left() / TILE_SIZE;
	bounds[1][1] = bottom() / TILE_SIZE;

	bounds[2][0] = right() / TILE_SIZE;
	bounds[2][1] = bottom() / TILE_SIZE;

	bounds[3][0] = right() / TILE_SIZE;
	bounds[3][1] = top() / TILE_SIZE;

	if (bottom() < bounds[2][1] * TILE_SIZE + 1)
	{
		int tiles_horizontal = bounds[3][0] - bounds[0][0] + 1;
		Tile* tile = NULL;

		for (int i = 0; i < tiles_horizontal; ++i)
		{
			tile = world->getTile(bounds[2][0] - i, bounds[2][1] - 1);
			if (tile != NULL && !tile->getType()->isPassable())
			{
				return true;
			}
		}
	}

	return false;
}
