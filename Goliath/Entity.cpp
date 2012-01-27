/*
 * Entity.cpp
 *
 *  Created on: Jan 9, 2012
 *      Author: thakidd
 */

#include "Entity.h"
#include "Vector2.h"

Entity::Entity(std::string filename, Vector2 size, Vector2 position, bool passable)
{
    mDimension2D = size;

    mPosition2D = position;

    mPassable = passable;

    mProposedDisplacement2D = Vector2(0,0);
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

Vector2 Entity::getSpeed2D()
{
    return mSpeed2D;
}

int Entity::getSpeedX()
{
    return mSpeed2D.x;
}

int Entity::getSpeedY()
{
    return mSpeed2D.y;
}

bool Entity::isPassable()
{
    return mPassable;
}

void Entity::setPosition(Vector2 position)
{
    mPosition2D = position;
}

void Entity::setPosition(int x, int y)
{
    mPosition2D.x = x;
    mPosition2D.y = y;
}

void Entity::setSpeed(Vector2 speed)
{
    mSpeed2D = speed;
}

void Entity::setProposedDisplacement(float xd, float yd)
{
	mProposedDisplacement2D.x = xd;
	mProposedDisplacement2D.y = yd;
}

Vector2 Entity::getProposedDisplacement()
{
	return mProposedDisplacement2D;
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
