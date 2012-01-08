#pragma once

#include <Windows.h>
#include <SDL.h>
#include <gl/GL.h>

#include "PhyEngine.h"
#include "RenderEngine.h"
#include "GoliathEventHandler.h"

class Game
{
    public:
        static const int WINDOW_WIDTH = 640;
        static const int WINDOW_HEIGHT = 480;
        static const int VIEWPORT_WIDTH = WINDOW_WIDTH;
        static const int VIEWPORT_HEIGHT = WINDOW_HEIGHT;
        
	public:
		Game(void);
		~Game(void);

		int		OnExecute();
		bool	OnInit();
		void	OnLoop();
		void	OnRender();
		void	OnCleanUp();

		void	Quit();


	private:
		bool				mIsRunning;
		PhyEngine			mPhyEngine;
		RenderEngine		mRenderEngine;
        GoliathEventHandler mEventHandler;
};

