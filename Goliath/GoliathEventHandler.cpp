

#include <iostream>

#include "GoliathEventHandler.h"
#include "Game.h"


GoliathEventHandler::GoliathEventHandler()
{
}

GoliathEventHandler::GoliathEventHandler(Game *game)
{
	mpGame = game;
}

GoliathEventHandler::~GoliathEventHandler(void)
{
}

void GoliathEventHandler::SetGame(Game *game)
{
	if (game != 0)
		mpGame = game;
}

/* virtual */ void GoliathEventHandler::OnExit()
{
	this->mpGame->Quit();    
}

/* virtual */ void GoliathEventHandler::OnMouseMove(int x, int y, int relX, int relY,
            bool Left,bool Right,bool Middle)
{
    WindowToGameCoordinates(x,y);

    Entity *test = mpGame->entityList[0];
    test->setPosition(x,y);
    std::cout << "MMove (" << x << "," << y << ")" << std::endl;
    std::cout << "MMove rel (" << relX << "," << relY << ")" << std::endl;
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

/* virtual */ void GoliathEventHandler::OnLButtonDown(int x, int y)
{
    std::cout << "LBDown (" << x << "," << y << ")" << std::endl;    
}

/* virtual */ void GoliathEventHandler::OnLButtonUp(int x, int y)
{
    std::cout << "LBUp (" << x << "," << y << ")" << std::endl;
}

/* virtual */ void GoliathEventHandler::OnRButtonDown(int x, int y)
{
    std::cout << "RBDown (" << x << "," << y << ")" << std::endl;
}

/* virtual */ void GoliathEventHandler::OnRButtonUp(int x, int y)
{
    std::cout << "RBUp (" << x << "," << y << ")" << std::endl;
}

void GoliathEventHandler::WindowToGameCoordinates(int &x, int &y)
{
    int gameX, gameY;

    /* considering viewport at origin (0,0) */
    gameX = (x/Game::WINDOW_WIDTH) * Game::VIEWPORT_WIDTH;
    gameY = ((Game::WINDOW_HEIGHT - y)/Game::WINDOW_HEIGHT) * Game::VIEWPORT_HEIGHT;
	
    x = gameX;
    y = gameY;
}
