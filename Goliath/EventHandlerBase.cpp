

#include "EventHandlerBase.h"


EventHandlerBase::EventHandlerBase(void)
{
}


EventHandlerBase::~EventHandlerBase(void)
{
}

void EventHandlerBase::onEvent(SDL_Event *event)
{
    switch (event->type)
    {
        case SDL_ACTIVEEVENT:
			{
				switch (event->active.state)
				{
					case SDL_APPMOUSEFOCUS: 
						{
							if (event->active.gain)
								onMouseFocus();
							else
								onMouseBlur();
							break;
						}
					case SDL_APPINPUTFOCUS:
						{
							if (event->active.gain)
								onInputFocus();
							else
								onInputBlur();
							break;
						}
					case SDL_APPACTIVE:
						{
							if (event->active.gain)
								onRestore();
							else
								onMinimize();
							break;
						}
				}
			}
        case SDL_KEYDOWN:
			{
				onKeyDown(event->key.keysym.sym,event->key.keysym.mod,event->key.keysym.unicode);
				break;
			}
 
        case SDL_KEYUP:
			{
				onKeyUp(event->key.keysym.sym,event->key.keysym.mod,event->key.keysym.unicode);
				break;
			}
 
		case SDL_MOUSEMOTION:
			{
				onMouseMove(event->motion.x,event->motion.y,event->motion.xrel,
						event->motion.yrel,(event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT)) != 0,
						(event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0,
						(event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
				break;
			}

		case SDL_MOUSEBUTTONUP:
			{
				switch(event->button.button)
				{
					case SDL_BUTTON_LEFT:
						{
							onLButtonUp(event->button.x,event->button.y);
							break;
						}
					case SDL_BUTTON_RIGHT:
						{
							onRButtonUp(event->button.x,event->button.y);
							break;
						}
					case SDL_BUTTON_MIDDLE:
						{
							onMButtonUp(event->button.x,event->button.y);
							break;
						}
				}
				break;
			}
        case SDL_MOUSEBUTTONDOWN:
			{
				switch(event->button.button)
				{
					case SDL_BUTTON_LEFT:
						{
							onLButtonDown(event->button.x,event->button.y);
							break;
						}
					case SDL_BUTTON_RIGHT:
						{
							onRButtonDown(event->button.x,event->button.y);
							break;
						}
					case SDL_BUTTON_MIDDLE:
						{
							onMButtonDown(event->button.x,event->button.y);
							break;
						}
				}
				break;
			}
		case SDL_QUIT:
			{
				onExit();
				break;
			}

		case SDL_SYSWMEVENT: 
			{
				//Ignore
				break;
			}

		case SDL_VIDEORESIZE:
			{
				onResize(event->resize.w,event->resize.h);
				break;
			}

		case SDL_VIDEOEXPOSE:
			{
				onExpose();
				break;
			}

		default:
			{
				onUser(event->user.type,event->user.code,event->user.data1,event->user.data2);
				break;
			}
	}
}
