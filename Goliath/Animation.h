#pragma once

#ifndef _ANIMATION_H
#define _ANIMATION_H

class Animation
{
    public:
        Animation(void);
        ~Animation(void);

        void Animate();
        void SetFramePeriod(int period);
        void SetCurrentFrame(int frame);
        int  GetCurrentFrame();

    private:
        int  mCurrentFrame;
        int  mNumFrames;      /* maximum number of frames on animation */
        int  mFrameIncrement;
        long mLastFrameTime;  /* time the last frame was drawn */
        int  mFramePeriod;    /* time of eache frame in miliseconds */

};

#endif //ANIMATION_H
