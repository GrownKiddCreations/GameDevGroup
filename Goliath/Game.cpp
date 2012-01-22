#include "Game.h"
#include "Vector2.h"
#include <GL/glew.h>
#include "lib/FreeImage.h"
#include "WorldBuilder.h"
#include "SimpleWorldBuilder.h"

#include <iostream>

//TODO create an initializer for a list of elements/entities
Game::Game(void) :
        mPhyEngine(), mRenderEngine(Game::WINDOW_WIDTH, Game::WINDOW_HEIGHT,
                Game::VIEWPORT_WIDTH, Game::VIEWPORT_HEIGHT), mEventHandler()
{
    mIsRunning = false;
    mCurrentWorld = NULL;

    mWorldBuilder = new SimpleWorldBuilder(32, 24);

    setWorld(mWorldBuilder->build());

    // FIXME - adding a test entity
    Vector2 dudeDim(60,60);
    Vector2 dudePos(300, 300);
    Entity *test = new Entity("img/images.jpg", dudeDim, dudePos, false);
    entityList.push_back(test);
    mCurrentWorld->addEntity(test);
    mCurrentWorld->setPlayerEntity(test);

    upKeyDown = false;
    leftKeyDown = false;
    downKeyDown = false;
    rightKeyDown = false;
}

Game::~Game(void)
{
    if (mCurrentWorld != NULL)
        delete mCurrentWorld;

    delete mWorldBuilder;
}

bool Game::onInit()
{
    std::cout << "Initializing FreeImage..." << std::endl;
    FreeImage_Initialise(1);

    /* Set itself on the eventHandler */
    mEventHandler.SetGame(this);

    /* Initialize game graphics and window */
    if (!mRenderEngine.initGraphics())
        return false;

    /* Initialize camera projection */
    mRenderEngine.initCamera();

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        std::cout << "Error: " << glewGetErrorString(err) << std::endl;
    }

    std::cout << "Status: Using GLEW " << glewGetString(GLEW_VERSION)
            << std::endl;

    if (glewIsSupported("GL_VERSION_1_4  GL_ARB_point_sprite"))
    {
        std::cout << "Great, we have OpenGL 1.4 + point sprites." << std::endl;
    }

    if (glewIsSupported("GL_VERSION_3_3"))
    {
        std::cout << "Great, we have OpenGL 3.3!" << std::endl;
    }

    std::cout << "OpenGL version: " << (char*) glGetString(GL_VERSION)
            << std::endl;

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
            mEventHandler.onEvent(&event);

            switch (event.type)
            {
				case SDL_KEYDOWN:
				{
					SDLKey sym = event.key.keysym.sym;
					SDLMod mod = event.key.keysym.mod;
					Uint16 unicode = event.key.keysym.unicode;

					switch (sym)
					{
					case SDLK_UP: upKeyDown = true; break;
					case SDLK_LEFT:	leftKeyDown = true; break;
					case SDLK_DOWN:	downKeyDown = true; break;
					case SDLK_RIGHT: rightKeyDown = true; break;
					default: break;
					}

					break;
				}
				case SDL_KEYUP:
				{
					SDLKey sym = event.key.keysym.sym;
					SDLMod mod = event.key.keysym.mod;
					Uint16 unicode = event.key.keysym.unicode;

					switch (sym)
					{
					case SDLK_UP: upKeyDown = false; break;
					case SDLK_LEFT:	leftKeyDown = false; break;
					case SDLK_DOWN:	downKeyDown = false; break;
					case SDLK_RIGHT: rightKeyDown = false; break;
					default: break;
					}

					break;
				}
            }
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

	Entity *pc = mCurrentWorld->getPlayerEntity();
	int x, y;

	x = pc->getX();
	y = pc->getY();

	const float SPEED = 2.0f;

	if (upKeyDown)
	{
		y += SPEED;
	}
	if (leftKeyDown)
	{
		x -= SPEED;
	}
	if (downKeyDown)
	{
		y -= SPEED;
	}
	if (rightKeyDown)
	{
		x += SPEED;
	}

	pc->setPosition(x, y);

}

void Game::onRender()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    //mRenderEngine.RenderWorld(*(entityList.begin()));

    if (mCurrentWorld != NULL)
        mRenderEngine.renderWorld(mCurrentWorld);

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
