#include "Tile.h"

Tile::Tile(TileType& type)
{
	mType = &type;
}

Tile::~Tile()
{

}

TileType* Tile::getType()
{
	return mType;
}
