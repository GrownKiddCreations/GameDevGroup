
#ifndef _TILETYPE_H
#define _TILETYPE_H

#include <string>

class TileType
{

	public:
		TileType(std::string, bool);
        ~TileType();
	
		std::string getName();	
		bool isPassable();
	
	private:
		std::string mName;
		bool mIsPassable;
	
};

#endif
