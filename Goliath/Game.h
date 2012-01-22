#pragma once

#ifdef WIN32
#include <Windows.h>
#endif

#include "SDL/SDL.h"

#include <vector>
#include <map>
#include "RenderEngine.h"
#include "EventHandler.h"
#include "FrameControl.h"
#include "PhyEngine.h"
#include "World.h"
#include "SimpleWorldBuilder.h"
#include "Entity.h"

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

        int onExecute();
        bool onInit();
        void onLoop();
        void onRender();
        void onCleanUp();

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

        WorldBuilder* mWorldBuilder;
        World *mCurrentWorld;

        std::map<SDLKey, bool> mKeyStateMap;

};

