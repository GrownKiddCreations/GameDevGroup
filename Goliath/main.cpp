
#include <iostream>
#include <vector>

#include "Game.h"

using namespace std;


int main(int argc, char** argv)
{

	Game theGame;

    /* Initialize game control objects and resources */
    if (theGame.onInit() != false)
    {
        return theGame.onExecute();
    }
    else
    {
        return -1;
    }
}
