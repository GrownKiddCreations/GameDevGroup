
#include <iostream>

#include "Game.h"

int main(int argc, char** argv)
{
    std::cout << "Initializing.." << std::endl;

    Game theGame;

    return theGame.OnExecute();

}
