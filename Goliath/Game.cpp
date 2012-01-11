
#include "Game.h"

#include <iostream>
#include "Vector2.h"

Game::Game(void) :
        mPhyEngine(), mRenderEngine(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT,
                Game::VIEWPORT_WIDTH, Game::VIEWPORT_HEIGHT), mEventHandler()
{
    mIsRunning = false;
}

Game::~Game(void)
{
}

bool Game::OnInit()
{
    /* Set itself on the eventHandler */
    mEventHandler.SetGame(this);

    /* Initialize game graphics and window */
    if (!mRenderEngine.InitGraphics())
        return false;

    /* Initialize camera projection */
    mRenderEngine.InitCamera();

    std::cout << "OpenGL version: " << (char*) glGetString(GL_VERSION) << std::endl;

    return true;

}

int Game::OnExecute()
{
    /* Initialize game control objects and resources */
    if (OnInit() == false)
        return -1;

    /* Start the game */
    mIsRunning = true;

    SDL_Event event;

    /* Main game loop */
    while (mIsRunning)
    {
        /* Checks for events */
        while (SDL_PollEvent(&event))
        {
            /* Pass event to the handler */
            mEventHandler.OnEvent(&event);
        }

        /* Updates game data */
        OnLoop();
        /* Renders game objects */
        OnRender();
    }

    /* Cleans allocated resources */
    OnCleanUp();

    return 0;
}

void Game::OnLoop()
{

}

void Game::OnRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    mRenderEngine.RenderWorld(*(entityList.begin()));

    SDL_GL_SwapBuffers();
}

void Game::OnCleanUp()
{
    SDL_Quit();
}

void Game::Quit()
{
    mIsRunning = false;
}

