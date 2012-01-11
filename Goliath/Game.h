#pragma once

#ifdef WIN32
#include <Windows.h>
#endif

#include "SDL/SDL.h"
#include <GL/glut.h>

#include "PhyEngine.h"
#include "RenderEngine.h"
#include "EventHandler.h"
#include "FrameControl.h"
#include "World.h"
#include "Entity.h"
#include <vector>

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

        int OnExecute();
        bool OnInit();
        void OnLoop();
        void OnRender();
        void OnCleanUp();

        void Quit();
        
        World* getWorld();
		void setWorld(World* world);

    public:
        std::vector<Entity*> entityList;

    private:
        bool mIsRunning;
        PhyEngine mPhyEngine;
        RenderEngine mRenderEngine;
        EventHandler mEventHandler;
        FrameControl mFrameControl;
        World *mCurrentWorld;
};

