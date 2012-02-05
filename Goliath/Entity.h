#ifndef _ENTITIES_H
#define _ENTITIES_H

#include <string>

#include "Rectangle.h"
#include "Vector2.h"

class World;

class Entity
{
    public:
        Entity(std::string, std::string, float, float, float, float, float, bool);
        ~Entity(void);

        Vector2<float> getDimensions2D();
        int getWidth();
        int getHeight();

        Vector2<float> getPosition2D();
        int getX();
        int getY();

        bool isPassable();

        //x,y coords
        void setPosition(Vector2<float>);
        void setPosition(float,float);

        std::string getName();

        //what is force for?
        void addForce(float, float);
        void setForce(float,float);
        Vector2<float> getForce();

        Vector2<float> getVelocity();
        void setVelocity(float, float);
        float getMass();

        //what is this?
        void setImpulse(float, float);
        Vector2<float> getImpulse();

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
        Vector2<float>     mDimension2D;
        Vector2<float>     mPosition2D;
        Vector2<float>     mForce2D;//TODO need description of purpose
        Vector2<float>     mVelocity2D;//TODO need description of purpose
        Vector2<float>     mImpulse2D;//TODO need description of purpose

        friend class RenderEngine;
        friend class PhyEngine;
};
#endif //_ENTITIES_H
