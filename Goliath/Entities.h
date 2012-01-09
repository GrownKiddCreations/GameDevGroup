#ifndef _ENTITIES_H
#define _ENTITIES_H

class Entities
{
    public:
        Entities(Number2D, Number2D, bool);
        ~Entities(void);

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
        void setPostion(Number2D);

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
#endif _ENTITIES_H
