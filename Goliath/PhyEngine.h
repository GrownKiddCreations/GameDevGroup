#pragma once

#include <vector>
#include "World.h"

const int TERMINAL_VELOCITY = 10;

class PhyEngine
{
    public:
        PhyEngine();
        ~PhyEngine(void);

        void step(World*);

    private:

};
