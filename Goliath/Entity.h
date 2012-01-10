#ifndef _ENTITIES_H
#define _ENTITIES_H

#include "Number2D.h"
#include <string>

class Entity
{
    public:
        Entity(std::string, Number2D, Number2D, bool);
        ~Entity(void);

        Number2D getDimensions2D();
        int getWidth();
        int getHeight();

        Number2D getPosition2D();
        int getX();
        int getY();

        Number2D getSpeed2D();
        int getSpeedX();
        int getSpeedY();

        bool isPassable();

        void setSpeed(Number2D);
        void setPosition(Number2D);
        void setPosition(int,int);

    private:
        int mWidth, mHeight;
        int mPositionX, mPositionY;
        int mSpeedX, mSpeedY;
        bool mPassable; // for collision detection

        //Number2D attributes
        Number2D mDimension2D;
        Number2D mPosition2D;
        Number2D mSpeed2D;
};
#endif //_ENTITIES_H
