
#include "TileType.h"

TileType::TileType(std::string name, bool isPassable)
{
	mName = name;
	mIsPassable = isPassable;
}

TileType::~TileType()
{

}

std::string TileType::getName()
{
	return mName;
}

bool TileType::isPassable()
{
	return mIsPassable;
}
