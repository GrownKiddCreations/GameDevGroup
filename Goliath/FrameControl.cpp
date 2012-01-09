
<<<<<<< HEAD
#include <SDL/SDL.h>
=======
#include "SDL/SDL.h"
>>>>>>> e36408cc3f5f3f077cc16de72ab6d990cb80cb51


#include "FrameControl.h"

FrameControl::FrameControl(void)
{
}


FrameControl::~FrameControl(void)
{
}

void FrameControl::OnLoop()
{
    if (mOldtimeMs + 1000 /*ms*/ < SDL_GetTicks())
    {
        mOldtimeMs = SDL_GetTicks();
        mFPS = mAuxFrames;
        mAuxFrames = 0;
    }

    mSpeedFactor = ((SDL_GetTicks() - mLastTimeMs) / 1000.0f) * FrameControl::BASE_FPS;
    mLastTimeMs = SDL_GetTicks();
    mAuxFrames++;
}

int FrameControl::GetFPS()
{
    return mFPS;
}

float FrameControl::GetSpeedFactor()
{
    return mSpeedFactor;
}
