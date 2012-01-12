#ifndef _TILE_H
#define _TILE_H

#include "TileType.h"

const int TILE_SIZE = 20;

class Tile
{

	public:
		Tile(TileType*);
        ~Tile();
        
        TileType* getType();
	
	private:
		TileType *mType;
};

#endif
