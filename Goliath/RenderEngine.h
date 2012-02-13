#pragma once

#include "Entity.h"
#include "World.h"

class RenderEngine
{
	public:
		RenderEngine(void);
        RenderEngine(int windowWidth, int windowHeight, int viewportWidth, int viewportHeight);
		~RenderEngine(void);
        
        bool initGraphics();
		void initCamera();

		/*
		 * Draw entity to screen
		 */
        void renderEntity(Entity *being);

        /*
         * Draw world to screen
         */
        void renderWorld(World *world);

        /*
         * Centers the viewport on the player character, within the world bounds
         */
        void centerView(World *world);
        
    private:
        int mWindowWidth, mWindowHeight;
        int mViewportWidth, mViewportHeight;
        float mOffsetX, mOffsetY;
};

