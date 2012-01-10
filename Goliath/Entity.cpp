/*
 * Entity.cpp
 *
 *  Created on: Jan 9, 2012
 *      Author: thakidd
 */

#include "Entity.h"
#include "Number2D.h"

Entity::Entity(std::string filename, Number2D size, Number2D position, bool passable)
{
    mDimension2D = size;
    mWidth = size.x;
    mHeight = size.y;

    mPosition2D = position;
    mPositionX = position.x;
    mPositionY = position.y;

    mPassable = passable;
}

Entity::~Entity()
{

}

Number2D Entity::getDimensions2D()
{
    return mDimension2D;
}

int Entity::getWidth()
{
    return mWidth;
}

int Entity::getHeight()
{
    return mHeight;
}

Number2D Entity::getPosition2D()
{
    return mPosition2D;
}

int Entity::getX()
{
    return mPositionX;
}

int Entity::getY()
{
    return mPositionY;
}

Number2D Entity::getSpeed2D()
{
    return mSpeed2D;
}

int Entity::getSpeedX()
{
    return mSpeedX;
}

int Entity::getSpeedY()
{
    return mSpeedY;
}

bool Entity::isPassable()
{
    return mPassable;
}

void Entity::setPosition(Number2D position)
{
    mPosition2D = position;
}

void Entity::setPosition(int x, int y)
{
    mPositionX = x;
    mPositionY = y;
    mPosition2D.x = x;
    mPosition2D.y = y;
}

void Entity::setSpeed(Number2D speed)
{
    mSpeed2D = speed;
}
