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

RenderEngine::RenderEngine(int windowWidth, int windowHeight,
    int viewportWidth, int viewportHeight)
{
    mWindowWidth = windowWidth;
    mWindowHeight = windowHeight;
    mViewportWidth = viewportWidth;
    mViewportHeight = viewportHeight;
}

RenderEngine::~RenderEngine(void)
{
}

bool RenderEngine::InitGraphics()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return false;

    if (SDL_SetVideoMode(mWindowWidth, mWindowHeight, 32,
        SDL_HWSURFACE | SDL_OPENGL) == 0)
		return false;

    SDL_WM_SetCaption("Goliath",0);

    /* OpenGL options */
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER,1);

    return true;
}

void RenderEngine::InitCamera()
{
	glClearColor(0, 0, 0, 0); 
    glViewport(0, 0, mWindowWidth, mWindowHeight);
 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

    /* If left or bottom changes from 0, GoliathEventHandler::WindowToGameCoordinates needs
       to change -> viewport at origin (0,0) */
    glOrtho(0, mViewportWidth, mViewportHeight, 0, 1, -1);
    
 	glMatrixMode(GL_MODELVIEW); 
	glEnable(GL_TEXTURE_2D); 
	glLoadIdentity();
}
