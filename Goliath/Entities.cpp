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

	isPassable = passable;
}

Entities::~Entities()
{

}

Number2D Entities::getDimensions2D()
{
	return Entities::mDimension2D;
}

Number2D Entities::getPosition2D()
{
	return Entities::mPosition2D;
}

Number2D Entities::getSpeed2D()
{
	return Entities::mSpeed2D;
}
