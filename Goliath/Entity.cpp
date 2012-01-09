/*
 * Entities.cpp
 *
 *  Created on: Jan 9, 2012
 *      Author: thakidd
 */

#include "Entities.h"

Entities::Entities(Number2D size, Number2D position, bool passable)
{
    mDimension2D = size;
    mWidth = size.x;
    mHeight = size.y;

    mPosition2D = position;
    mPositionX = position.x;
    mPositionY = position.y;

    mPassable = passable;
}

Entities::~Entities()
{

}

Number2D Entities::getDimensions2D()
{
    return mDimension2D;
}

int Entities::getWidth()
{
    return mWidth;
}

int Entities::getHeight()
{
    return mHeight;
}

Number2D Entities::getPosition2D()
{
    return mPosition2D;
}

int Entities::getX()
{
    return mPositionX;
}

int Entities::getY()
{
    return mPositionY;
}

Number2D Entities::getSpeed2D()
{
    return mSpeed2D;
}

int Entities::getSpeedX()
{
    return mSpeedX;
}

int Entities::getSpeedY()
{
    return mSpeedY;
}

bool Entities::isPassable()
{
    return mPassable;
}

void Entities::setPostion(Number2D position)
{

}

void Entities::setSpeed(Number2D speed)
{

}
