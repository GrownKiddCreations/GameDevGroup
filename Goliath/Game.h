#pragma once

#ifdef WIN32
#include <Windows.h>
#endif

#include "SDL/SDL.h"

#include <map>
#include <vector>
#include "World.h"
#include "Entity.h"
#include "PhyEngine.h"
#include "RenderEngine.h"
#include "EventHandler.h"
#include "FrameControl.h"
#include "SimpleWorldBuilder.h"

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

    private:
        bool                    mIsRunning;
        PhyEngine               mPhyEngine;
        RenderEngine            mRenderEngine;
        EventHandler            mEventHandler;
        FrameControl            mFrameControl;

        WorldBuilder*           mWorldBuilder;
        World*                  mCurrentWorld;

        std::map<SDLKey, bool>  mKeyStateMap;

};

