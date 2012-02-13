/**
 * RenderEngine Class
 *
 */
#ifdef WIN32
#include <Windows.h>
#endif

#include <vector>
#include <string>
#include <GL/gl.h>
#include <iostream>
#include "SDL/SDL.h"

#include "RenderEngine.h"

RenderEngine::RenderEngine(void)
{
    mWindowWidth = 640;
    mWindowHeight = 480;
    mOffsetX = 0;
    mOffsetY = 0;
}

RenderEngine::RenderEngine(int windowWidth, int windowHeight, int viewportWidth,
        int viewportHeight)
{
    mWindowWidth = windowWidth;
    mWindowHeight = windowHeight;
    mViewportWidth = viewportWidth;
    mViewportHeight = viewportHeight;
    mOffsetX = 0;
    mOffsetY = 0;
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
    if((being->getName().compare("enemy")))
    {
        glColor3f(1, 0, 0);
    }
    else
    {
        glColor3f(0,1,0);
    }

    glRectf(being->getX(), being->getY(), being->getX() + being->getWidth(), being->getY() + being->getHeight());
}

void RenderEngine::centerView(World *world)
{
	// view is centered around the player character, so we get that first
	Entity *pc = world->getPlayerEntity();
	if (pc != NULL)
	{
		const int world_limit_x = world->getWidth() * TILE_SIZE;
		const int world_limit_y = world->getHeight() * TILE_SIZE;

		// the amount by which we will shift the view from origin
		float x_mod = 0.0;
		float y_mod = 0.0;

		// if window width is smaller than world width
		if (mWindowWidth < world_limit_x)
		{
			x_mod = pc->getX() + (pc->getWidth() / 2) - (mWindowWidth / 2);

			if (x_mod < 0)
				x_mod = 0;

			if (x_mod + mWindowWidth > world_limit_x)
				x_mod = world_limit_x - mWindowWidth;
		}
		// else center the world within the window
		else
		{
			float diff = world_limit_x - mWindowWidth;
			x_mod =  diff / 2;
		}


		// check if window height is smaller than world height
		if (mWindowHeight < world_limit_y)
		{
			y_mod = pc->getY() + (pc->getHeight() / 2) - (mWindowHeight / 2);

			if (y_mod < 0)
				y_mod = 0;

			if (y_mod + mWindowHeight > world_limit_y)
				y_mod = world_limit_y - mWindowHeight;
		}
		else
		{
			float diff = world_limit_y - mWindowHeight;
			y_mod =  diff / 2;
		}

		mOffsetX = x_mod * -1;
		mOffsetY = y_mod * -1;
	}
	else
	{
		mOffsetX = 0.0;
		mOffsetY = 0.0;
	}

	glTranslatef(mOffsetX, mOffsetY, 0.0);
}

void RenderEngine::renderWorld(World *world)
{

	// To improve render speed, we only draw the tiles that are actually in view
	int start_x = (mOffsetX * -1) / TILE_SIZE;
	int start_y = (mOffsetY * -1) / TILE_SIZE;
	int end_x = start_x + mViewportWidth / TILE_SIZE + 1;
	int end_y = start_y + mViewportHeight / TILE_SIZE + 1;

	for (int i = start_x; i < end_x; i++)
	{
		for (int j = start_y; j < end_y; j++)
		{
			Tile* currentTile = world->getTile(i, j);
			if (currentTile != NULL)
			{
				if (!currentTile->getType()->isPassable())
				{
					glColor3f(1, 1, 1);
					glRecti(i * TILE_SIZE, j * TILE_SIZE, i * TILE_SIZE + TILE_SIZE, j * TILE_SIZE + TILE_SIZE);
				}
				else if (currentTile->getType()->isCloud())
				{
					glColor3f(0, 0, 1);
					glRecti(i * TILE_SIZE, j * TILE_SIZE, i * TILE_SIZE + TILE_SIZE, j * TILE_SIZE + TILE_SIZE);
				}
			}
		}	
	}
	
	// entities TODO: cull out entities that are not in view
	std::set<Entity *>::iterator iter;
	for (iter=world->mEntitySet.begin() ; iter != world->mEntitySet.end(); iter++)
	{
		renderEntity(*iter);
	}

	// development grid overlay
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
