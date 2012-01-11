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
		
		Tile* getTile(int x, int y);
		void setTile(Tile* tile, int x, int y);
		
	private:
		int mWidth;
		int mHeight;
		Tile*** mMatrix;
	
	friend class RenderEngine;
};

#endif
