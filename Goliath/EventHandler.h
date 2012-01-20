#pragma once

#include "EventHandlerBase.h"

class Game;

class EventHandler : public EventHandlerBase
{
	public:
		EventHandler();
		EventHandler(Game *game);
		~EventHandler(void);

		void SetGame(Game *game);
		void onExit();
        void onMouseMove(int x, int y, int relX, int relY,
            bool Left,bool Right,bool Middle);
        void onLButtonDown(int x, int y);
	    void onLButtonUp(int x, int y);
	    void onRButtonDown(int x, int y);
	    void onRButtonUp(int x, int y);/*
        void onMButtonDown(int x, int y);
        void onMButtonUp(int x, int y);*/
        void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode);
        void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode);


	private:
		Game *mpGame;

        void windowToGameCoordinates(int &x, int &y);
};

