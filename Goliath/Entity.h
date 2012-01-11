#ifndef _ENTITIES_H
#define _ENTITIES_H

#include "Vector2.h"
#include <string>

class Entity
{
    public:
        Entity(std::string, Vector2, Vector2, bool);
        ~Entity(void);

        Vector2 getDimensions2D();
        int getWidth();
        int getHeight();

        Vector2 getPosition2D();
        int getX();
        int getY();

        Vector2 getSpeed2D();
        int getSpeedX();
        int getSpeedY();

        bool isPassable();

        void setSpeed(Vector2);
        void setPosition(Vector2);
        void setPosition(int,int);

    private:

        std::string mTextureImgName;
        int mWidth, mHeight;
        int mPositionX, mPositionY;
        int mSpeedX, mSpeedY;
        bool mPassable; // for collision detection

        //Vector2 attributes
        Vector2 mDimension2D;
        Vector2 mPosition2D;
        Vector2 mSpeed2D;
};
#endif //_ENTITIES_H