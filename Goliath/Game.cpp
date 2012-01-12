
#include "Game.h"

#include <iostream>
#include "Vector2.h"

//TODO create an initializer for a list of elements/entities

Game::Game(void) :
        mPhyEngine(), mRenderEngine(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT,
                Game::VIEWPORT_WIDTH, Game::VIEWPORT_HEIGHT), mEventHandler()
{
    mIsRunning = false;
    mCurrentWorld = NULL;
}

Game::~Game(void)
{
	if (mCurrentWorld != NULL)
		delete mCurrentWorld;
}

bool Game::onInit()
{
    /* Set itself on the eventHandler */
    mEventHandler.SetGame(this);

    /* Initialize game graphics and window */
    if (!mRenderEngine.initGraphics())
        return false;

    /* Initialize camera projection */
    mRenderEngine.initCamera();

    std::cout << "OpenGL version: " << (char*) glGetString(GL_VERSION) << std::endl;

    return true;

}

int Game::onExecute()
{
    /* Initialize game control objects and resources */
    if (onInit() == false)
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
        onLoop();
        /* Renders game objects */
        onRender();
    }

    /* Cleans allocated resources */
    onCleanUp();

    return 0;
}

void Game::onLoop()
{

}

void Game::onRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //mRenderEngine.RenderWorld(*(entityList.begin()));
    
    if (mCurrentWorld != NULL)
		mRenderEngine.renderWorld(mCurrentWorld);

    if (mCurrentWorld->getEntities().empty() != true)
        mRenderEngine.renderEntity(mCurrentWorld->getEntities().front());

    SDL_GL_SwapBuffers();
}

void Game::onCleanUp()
{
    SDL_Quit();
}

void Game::Quit()
{
    mIsRunning = false;
}

World* Game::getWorld()
{
	return mCurrentWorld;
}

void Game::setWorld(World* world)
{
	mCurrentWorld = world;
}
