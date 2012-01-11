#ifndef _TILE_H
#define _TILE_H

#include "TileType.h"

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
