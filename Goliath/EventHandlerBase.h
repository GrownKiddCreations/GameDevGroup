#pragma once

#include "SDL/SDL.h"


class EventHandlerBase
{
public:
	EventHandlerBase(void);
	~EventHandlerBase(void);

	virtual void onEvent(SDL_Event *event);
	virtual void onKeyDown(SDLKey sym, SDLMod mod, Uint16 unicode) { }
	virtual void onKeyUp(SDLKey sym, SDLMod mod, Uint16 unicode) { }
	virtual void onMouseFocus() { }
	virtual void onMouseBlur() { }
	virtual void onMouseMove(int mX, int mY, int relX, int relY,
		bool Left,bool Right,bool Middle) { }
	virtual void onMouseWheel(bool Up, bool Down) { }    //Not implemented
	virtual void onInputFocus() { }
	virtual void onInputBlur() { }
	virtual void onResize(int w,int h) { }
	virtual void onRestore() { }
	virtual void onMinimize() { }
	virtual void onExpose() { }
	virtual void onExit() { }
	virtual void onUser(Uint8 type, int code, void* data1, void* data2) { }
	virtual void onLButtonDown(int x, int y) { }
	virtual void onLButtonUp(int x, int y) { }
	virtual void onRButtonDown(int x, int y) { }
	virtual void onRButtonUp(int x, int y) { }
	virtual void onMButtonDown(int x, int y) { }
	virtual void onMButtonUp(int x, int y) { }

private:

};

