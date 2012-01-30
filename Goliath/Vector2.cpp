/*
 * Vector2.cpp
 *
 *  Created on: Jan 9, 2012
 *      Author: thakidd
 */

#include "Vector2.h"

#include <math.h>

Vector2::Vector2()
{

}

Vector2::Vector2(float x, float y)
{
    this->x = x;
    this->y = y;
}

float Vector2::magnitude()
{
	return sqrt((x * x) + (y * y));
}

Vector2* Vector2::scale(float scale)
{
	x *= scale;
	y *= scale;

	return this;
}

Vector2* Vector2::add(Vector2 other)
{
	x += other.x;
	y += other.y;

	return this;
}

Vector2* Vector2::makeUnit()
{
	float m = magnitude();
	if (m != 0)
	{
		x /= m;
		y /= m;
	}

	return this;
}
