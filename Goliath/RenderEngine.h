#pragma once

#include "Entity.h"

class RenderEngine
{
	public:
		RenderEngine(void);
        RenderEngine(int windowWidth, int windowHeight,
            int viewportWidth, int viewportHeight);
		~RenderEngine(void);
        
        bool InitGraphics();
		void InitCamera();
        void RenderWorld(Entity *being);
        void RenderEntities();
        
    private:
        int mWindowWidth, mWindowHeight;
        int mViewportWidth, mViewportHeight;
};

