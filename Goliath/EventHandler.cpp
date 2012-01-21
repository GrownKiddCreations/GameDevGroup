

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

/* virtual */ void EventHandler::onExit()
{
	this->mpGame->Quit();    
}

/* virtual */ void EventHandler::onMouseMove(int x, int y, int relX, int relY,
            bool Left,bool Right,bool Middle)
{
    //std::cout << "MMove (" << x << "," << y << ")" << std::endl;

    //std::cout << "w2g MMove (" << x << "," << y << ")" << std::endl;

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

/* virtual */ void EventHandler::onLButtonDown(int x, int y)
{
    std::cout << "LBDown (" << x << "," << y << ")" << std::endl;    
}

/* virtual */ void EventHandler::onLButtonUp(int x, int y)
{
    std::cout << "LBUp (" << x << "," << y << ")" << std::endl;
}

/* virtual */ void EventHandler::onRButtonDown(int x, int y)
{
    std::cout << "RBDown (" << x << "," << y << ")" << std::endl;
}

/* virtual */ void EventHandler::onRButtonUp(int x, int y)
{
    std::cout << "RBUp (" << x << "," << y << ")" << std::endl;
}

/* virtual */ void EventHandler::onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode)
{
    Entity *test = mpGame->getWorld()->getPlayerEntity();
    int x, y;
    x = test->getX();
    y = test->getY();

    switch (sym)
        {
        case SDLK_LEFT: //LEFT ARROW
            test->setPosition((x - 5), y);
            break;
        case SDLK_RIGHT:
            test->setPosition((x + 5), y);
            break;
        case SDLK_UP:
            test->setPosition(x, (y + 5));
            break;
        case SDLK_DOWN:
            test->setPosition(x, (y - 5));
            break;
        default:
            break;
        }

    /*switch (sym)
    {
    case SDLK_LEFT: //LEFT ARROW
        windowToGameCoordinates(x, y);
        test->setPosition((x - 0.1), y);
        break;
    case SDLK_RIGHT:
        windowToGameCoordinates(x, y);
        test->setPosition((x + 0.1), y);
        break;
    case SDLK_UP:
        windowToGameCoordinates(x, y);
        test->setPosition(x, (y + 0.1));
        break;
    case SDLK_DOWN:
        windowToGameCoordinates(x, y);
        test->setPosition(x, (y - 0.1));
        break;
    default:
        break;
    }*/
}

/* virtual */ void EventHandler::onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode)
{

}

void EventHandler::windowToGameCoordinates(int &x, int &y)
{
    int gameX, gameY;

    /* considering viewport at origin (0,0) */
    gameX = ((float) x/Game::WINDOW_WIDTH) * Game::VIEWPORT_WIDTH;
    gameY = ((float) (Game::WINDOW_HEIGHT - y)/Game::WINDOW_HEIGHT) * Game::VIEWPORT_HEIGHT;
	
    x = gameX;
    y = gameY;
}
