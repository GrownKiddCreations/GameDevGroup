#pragma once

class RenderEngine
{
	public:
		RenderEngine(void);
        RenderEngine(int windowWidth, int windowHeight,
            int viewportWidth, int viewportHeight);
		~RenderEngine(void);
        
        bool InitGraphics();
		void InitCamera();
        void RenderWorld();
        void RenderBeings();
        
    private:
        int mWindowWidth, mWindowHeight;
        int mViewportWidth, mViewportHeight;
};

