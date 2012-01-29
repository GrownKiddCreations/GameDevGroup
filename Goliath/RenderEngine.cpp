/**
 * RenderEngine Class
 *
 */
#ifdef WIN32
#include <Windows.h>
#endif

#include <vector>
#include <GL/gl.h>
#include <iostream>
#include "SDL/SDL.h"

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
    glColor3f(1, 0, 0);
    glRectf(being->getX(), being->getY(), being->getX() + being->getWidth(), being->getY() + being->getHeight());
    
    /* Not a good idea to load the texture at every loop */
    /*being->getTexture()->load(false);
    being->getTexture()->bind();
    glBegin(GL_QUADS);
    glTexCoord2d(0,0); glVertex2d(being->getX(), being->getY());
    glTexCoord2d(1,0); glVertex2d(being->getX() + being->getWidth(), being->getY());
    glTexCoord2d(1,1); glVertex2d(being->getX() + being->getWidth(), being->getY() + being->getHeight());
    glTexCoord2d(0,1); glVertex2d(being->getX(), being->getY() + being->getHeight());
    glEnd();*/
}

void RenderEngine::renderWorld(World *world)
{
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
					glRecti(i * TILE_SIZE, j * TILE_SIZE, i * TILE_SIZE + TILE_SIZE, j * TILE_SIZE + TILE_SIZE);
				}
			}
		}	
	}
	
	// entities
	std::set<Entity *>::iterator iter;
	for (iter=world->mEntitySet.begin() ; iter != world->mEntitySet.end(); iter++)
	{
		renderEntity(*iter);
	}

	// grid
	for (int i = 0; i < world->getWidth(); ++i)
	{
		for (int j = 0; j < world->getHeight(); ++j)
		{
			glColor3f(0.5, 0.5, 0.5);	
			glBegin(GL_LINE_LOOP);
			glVertex2i(i * TILE_SIZE, j * TILE_SIZE);
			glVertex2i(i * TILE_SIZE + TILE_SIZE, j * TILE_SIZE);
			glVertex2i(i * TILE_SIZE + TILE_SIZE, j * TILE_SIZE + TILE_SIZE);
			glVertex2i(i * TILE_SIZE, j * TILE_SIZE + TILE_SIZE);
			glEnd();
		}	
	}

}
