/*
 * Number2D.h
 *
 *  Created on: Jan 9, 2012
 *      Author: thakidd
 */

#ifndef NUMBER2D_H_
#define NUMBER2D_H_

class Number2D
{
    public:
        Number2D(int, int);
        ~Number2D();

        int x; //can be positive
        int y; //can be negative
        bool isPosX();
        bool isPosY();
};

#endif NUMBER2D_H_
