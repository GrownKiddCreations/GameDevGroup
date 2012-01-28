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

void Vector2::scale(float scale)
{
	x *= scale;
	y *= scale;
}

Vector2 Vector2::createUnit()
{
	float m = magnitude();
	if (m != 0)
	{
		return Vector2(x /= m, y /= m);
	}
	return Vector2(0.0, 0.0);
}
