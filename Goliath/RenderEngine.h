#pragma once

#include "Entity.h"
#include "World.h"

class RenderEngine
{
	public:
		RenderEngine(void);
        RenderEngine(int windowWidth, int windowHeight,
            int viewportWidth, int viewportHeight);
		~RenderEngine(void);
        
        bool initGraphics();
		void initCamera();
        void renderEntity(Entity *being);
        void RenderEntities();
        void renderWorld(World *world); // FIXME
        
    private:
        int mWindowWidth, mWindowHeight;
        int mViewportWidth, mViewportHeight;
};

