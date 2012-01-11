#ifndef _WORLD_H
#define _WORLD_H

#include <vector>

#include "Tile.h"

class World
{

	public:
		World(int, int);
        ~World();
        
		int getWidth();
		int getHeight();
		bool isTilePassable(int x, int y);
	
	private:
		int mWidth;
		int mHeight;
	
};

#endif
