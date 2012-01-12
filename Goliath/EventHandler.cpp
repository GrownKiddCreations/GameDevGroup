

#include <iostream>

#include "EventHandler.h"
#include "Game.h"


EventHandler::EventHandler()
{
}

EventHandler::EventHandler(Game *game)
{
	mpGame = game;
}

EventHandler::~EventHandler(void)
{
}

void EventHandler::SetGame(Game *game)
{
	if (game != 0)
		mpGame = game;
}

/* virtual */ void EventHandler::OnExit()
{
	this->mpGame->Quit();    
}

/* virtual */ void EventHandler::OnMouseMove(int x, int y, int relX, int relY,
            bool Left,bool Right,bool Middle)
{
    //TODO move this code to keyboard control
    /*Entity *test = mpGame->entityList[0];
    WindowToGameCoordinates(x,y);
    test->setPosition(x-(test->getWidth()/2), y-(test->getHeight()/2));*/
    std::cout << "MMove (" << x << "," << y << ")" << std::endl;

    std::cout << "w2g MMove (" << x << "," << y << ")" << std::endl;

    //std::cout << "MMove rel (" << relX << "," << relY << ")" << std::endl;
    if (Left)
    {
        std::cout << "MMove Left Hold" << std::endl;
    }

    if (Middle)
    {
        std::cout << "MMove Middle Hold" << std::endl;
    }

    if (Right)
    {
        std::cout << "MMove Right Hold" << std::endl;
    }
}

/* virtual */ void EventHandler::OnLButtonDown(int x, int y)
{
    std::cout << "LBDown (" << x << "," << y << ")" << std::endl;    
}

/* virtual */ void EventHandler::OnLButtonUp(int x, int y)
{
    std::cout << "LBUp (" << x << "," << y << ")" << std::endl;
}

/* virtual */ void EventHandler::OnRButtonDown(int x, int y)
{
    std::cout << "RBDown (" << x << "," << y << ")" << std::endl;
}

/* virtual */ void EventHandler::OnRButtonUp(int x, int y)
{
    std::cout << "RBUp (" << x << "," << y << ")" << std::endl;
}

void EventHandler::WindowToGameCoordinates(int &x, int &y)
{
    int gameX, gameY;

    /* considering viewport at origin (0,0) */
    gameX = ((float) x/Game::WINDOW_WIDTH) * Game::VIEWPORT_WIDTH;
    gameY = ((float) (Game::WINDOW_HEIGHT - y)/Game::WINDOW_HEIGHT) * Game::VIEWPORT_HEIGHT;
	
    x = gameX;
    y = gameY;
}
