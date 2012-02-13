#pragma once

#include <vector>
#include "World.h"

const int TERMINAL_VELOCITY = 20;

class PhyEngine
{
    public:
        PhyEngine();
        ~PhyEngine(void);

        /*
         * Apply motion and collision rules over one unit of time
         */
        void step(World*);

    private:

};
