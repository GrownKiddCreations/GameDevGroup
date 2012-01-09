#include "Animation.h"


Animation::Animation(void)
{
}


Animation::~Animation(void)
{
}

void Animation::Animate()
{
}

void Animation::SetFramePeriod(int period)
{
    if (period > 0)
        mFramePeriod = period;
}

void Animation::SetCurrentFrame(int frame)
{
    if (frame >= 0 && frame < mNumFrames)
        mCurrentFrame = frame;
}

int  Animation::GetCurrentFrame()
{
    return this->mCurrentFrame; 
}
