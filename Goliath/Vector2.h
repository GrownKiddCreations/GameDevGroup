/*
 * Vector2.h
 *
 *  Created on: Jan 9, 2012
 *      Author: thakidd
 */

#ifndef VECTOR2_H_
#define VECTOR2_H_

class Vector2
{
public:

	Vector2();
	Vector2(float, float);

	float magnitude();
	void scale(float);
	Vector2 createUnit();

    float x;
    float y;


          
};

#endif //VECTOR2_H_
