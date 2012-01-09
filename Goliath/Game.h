#pragma once

#ifdef WIN32
#include <Windows.h>
#endif

#include <SDL/SDL.h>
#include <GL/glut.h>

#include "PhyEngine.h"
#include "RenderEngine.h"
#include "GoliathEventHandler.h"
#include "FrameControl.h"

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

    private:
        bool mIsRunning;
        PhyEngine mPhyEngine;
        RenderEngine mRenderEngine;
        GoliathEventHandler mEventHandler;
        FrameControl mFrameControl;
};

