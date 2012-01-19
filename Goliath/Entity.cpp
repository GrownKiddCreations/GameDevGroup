/*
 * Entity.cpp
 *
 *  Created on: Jan 9, 2012
 *      Author: thakidd
 */

#include "Entity.h"
#include "Vector2.h"

Entity::Entity(std::string filename, Vector2 size, Vector2 position, bool passable):
    mTexture(filename)
{
    mTexture.load(false);
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

Vector2 Entity::getDimensions2D()
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

Vector2 Entity::getPosition2D()
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

Vector2 Entity::getSpeed2D()
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

void Entity::setPosition(Vector2 position)
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

void Entity::setSpeed(Vector2 speed)
{
    mSpeed2D = speed;
}

int Entity::top()
{
    return mPositionY + mHeight;
}

int Entity::right()
{
    return mPositionX + mWidth;
}

int Entity::bottom()
{
    return mPositionY;
}

int Entity::left()
{
    return mPositionX;
}

Texture* Entity::getTexture()
{
    return &mTexture;
}