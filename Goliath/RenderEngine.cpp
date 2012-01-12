/**
 * RenderEngine Class
 *
 */
#ifdef WIN32
#include <Windows.h>
#endif

#include <GL/gl.h>
#include "SDL/SDL.h"
#include <vector>
#include <iostream>

#include "RenderEngine.h"

RenderEngine::RenderEngine(void)
{
    mWindowWidth = 640;
    mWindowHeight = 480;
}

RenderEngine::RenderEngine(int windowWidth, int windowHeight, int viewportWidth,
        int viewportHeight)
{
    mWindowWidth = windowWidth;
    mWindowHeight = windowHeight;
    mViewportWidth = viewportWidth;
    mViewportHeight = viewportHeight;
}

RenderEngine::~RenderEngine(void)
{
}

bool RenderEngine::initGraphics()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
        return false;

    if (SDL_SetVideoMode(mWindowWidth, mWindowHeight, 32,
            SDL_HWSURFACE | SDL_OPENGL) == 0)
        return false;

    SDL_WM_SetCaption("Goliath", 0);

    /* OpenGL options */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    return true;
}

void RenderEngine::initCamera()
{
    glClearColor(0, 0, 0, 0);
    glViewport(0, 0, mWindowWidth, mWindowHeight);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    /* If left or bottom changes from 0, EventHandler::WindowToGameCoordinates needs
     to change -> viewport at origin (0,0) */
    glOrtho(0, mViewportWidth, 0, mViewportHeight, 1, -1);//SDL works with a top-left origin so top and bottom must be swapped

    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);
    glLoadIdentity();
}

void RenderEngine::renderEntity(Entity *being)
{

    glColor3f(1, 1, 1);
    //glRectf(being->getX(), being->getY(), being->getX()+being->getWidth(), being->getY()+being->getHeight());
    //glColor3f(0.5, 0.5, 0.5);

    /*glBegin(GL_LINE_LOOP);
    glVertex2f(being->getX(), being->getY());
    glVertex2f(being->getX() + being->getWidth(), being->getY());
    glVertex2f(being->getX() + being->getWidth(), being->getY() + being->getHeight());
    glVertex2f(being->getX(), being->getY() + being->getHeight());
    glEnd();*/
}

void RenderEngine::renderWorld(World *world)
{
	int X_OFFSET = 20;
	int Y_OFFSET = 20;

	for (int i = 0; i < world->getWidth(); i++)
	{
		for (int j = 0; j < world->getHeight(); j++)
		{
			Tile* currentTile = world->getTile(i, j);
			if (currentTile != NULL)
			{
				if (!currentTile->getType()->isPassable())
				{
					glColor3f(1, 1, 1);
					glRectf(i * TILE_SIZE + X_OFFSET, j * TILE_SIZE + Y_OFFSET, TILE_SIZE, TILE_SIZE);
				}
			}
		}	
	}
	
	// show grid
	for (int i = 0; i < world->getWidth(); ++i)
	{
		for (int j = 0; j < world->getHeight(); ++j)
		{
			glColor3f(0.5, 0.5, 0.5);	
			glBegin(GL_LINE_LOOP);
			glVertex2f(i * TILE_SIZE + X_OFFSET, j * TILE_SIZE + Y_OFFSET);
			glVertex2f(i * TILE_SIZE + TILE_SIZE + X_OFFSET, j * TILE_SIZE + Y_OFFSET);
			glVertex2f(i * TILE_SIZE + TILE_SIZE + X_OFFSET, j * TILE_SIZE + TILE_SIZE + Y_OFFSET);
			glVertex2f(i * TILE_SIZE + X_OFFSET, j * TILE_SIZE + TILE_SIZE + Y_OFFSET);
			glEnd();
		}	
	}
}
