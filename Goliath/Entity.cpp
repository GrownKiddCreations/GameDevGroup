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

Entity::Entity(std::string name, std::string description, float x, float y, float w, float h, float mass, bool passable)
{
	//mBoundingBox(x, y, w, h);

	//mPosition2D.x = x;
	//mPosition2D.y = y;

    //mDimension2D.x = w;
    //mDimension2D.y = h;

    mBoundingBox.setPosition(x, y);
    mBoundingBox.setSize(w, h);

    mPassable = passable;

    mName = description;//this is temporary until I figure a better way around; describes enemy vs player

    mMass = mass;
}

Entity::~Entity()
{

}

Vector2<float> Entity::getDimensions2D()
{
    return mBoundingBox.getDimension();
}

int Entity::getWidth()
{
    return mBoundingBox.getWidth();
}

int Entity::getHeight()
{
    return mBoundingBox.getHeight();
}

Vector2<float> Entity::getPosition2D()
{
    return mBoundingBox.getPosition();
}

int Entity::getX()
{
    return mBoundingBox.getLeft();
}

int Entity::getY()
{
    return mBoundingBox.getBottom();
}

bool Entity::isPassable()
{
    return mPassable;
}

void Entity::setPosition(Vector2<float> position)
{
	mBoundingBox.setPosition(position.x, position.y);
}

void Entity::setPosition(float x, float y)
{
	mBoundingBox.setPosition(x, y);
}

Rectangle<float> Entity::getBoundingBox()
{
	return mBoundingBox;
}

std::string Entity::getName()
{
    return mName;
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

Vector2<float> Entity::getForce()
{
	return mForce2D;
}

Vector2<float> Entity::getVelocity()
{
	return mVelocity2D;
}

void Entity::setVelocity(float x, float y)
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

Vector2<float> Entity::getImpulse()
{
	return mImpulse2D;
}

int Entity::top()
{
    return mBoundingBox.getTop();
}

int Entity::right()
{
	return mBoundingBox.getRight();
}

int Entity::bottom()
{
    return mBoundingBox.getBottom();
}

int Entity::left()
{
    return mBoundingBox.getLeft();
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

