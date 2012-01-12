#ifndef _WORLD_H
#define _WORLD_H

#include <vector>

#include "Tile.h"
#include "Entity.h"

class World
{

	public:
		World(int, int);
        ~World();
        
		int getWidth();
		int getHeight();
		
		Tile* getTile(int x, int y);
		void setTile(Tile* tile, int x, int y);
		std::vector <Entity*> getEntities();
		void setEntities(std::vector <Entity*> entities);
		
	private:
		int mWidth;
		int mHeight;
		Tile*** mMatrix;
		std::vector <Entity*> mEntities;
	
	friend class RenderEngine;
};

#endif
