#pragma once


class FrameControl
{
    public:
        FrameControl(void);
        ~FrameControl(void);

        void    OnLoop();
        int     GetFPS();
        float   GetSpeedFactor();
    
    private:
        static const int BASE_FPS = 32;

        int     mOldtimeMs, mLastTimeMs;
        float   mSpeedFactor;
        int     mFPS, mAuxFrames;
};

