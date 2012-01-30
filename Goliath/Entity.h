#ifndef _ENTITIES_H
#define _ENTITIES_H

#include <string>

#include "Vector2.h"

class World;

class Entity
{
    public:
        Entity(std::string, Vector2, Vector2, float, bool);
        ~Entity(void);

        Vector2 getDimensions2D();
        int getWidth();
        int getHeight();

        Vector2 getPosition2D();
        int getX();
        int getY();

        bool isPassable();

        //x,y coords
        void setPosition(Vector2);
        void setPosition(float,float);

        std::string getName();

        //what is force for?
        void addForce(float, float);
        void setForce(float,float);
        Vector2 getForce();

        Vector2 getVelocity();
        Vector2 setVelocity(float, float);
        float getMass();

        //what is this?
        void setImpulse(float, float);
        Vector2 getImpulse();

        //collision detection
        int top();
        int bottom();
        int right();
        int left();

        // visitor methods
        bool isOnPlatformDown(World*);

    private:

        bool        mPassable; // for collision detection

        std::string mName;

        float       mMass;

        //Vector2 attributes
        Vector2     mDimension2D;
        Vector2     mPosition2D;
        Vector2     mForce2D;
        Vector2     mVelocity2D;
        Vector2     mImpulse2D;

        friend class RenderEngine;
        friend class PhyEngine;
};
#endif //_ENTITIES_H
