
#include "TileType.h"

TileType::TileType(std::string name, bool isPassable, bool isCloud)
{
	mName = name;
	mIsPassable = isPassable;
	mIsCloud = isCloud;
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

bool TileType::isCloud()
{
	return mIsCloud;
}

