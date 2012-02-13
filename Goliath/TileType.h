
#ifndef _TILETYPE_H
#define _TILETYPE_H

#include <string>

class TileType
{

	public:
		TileType(std::string, bool, bool);
        ~TileType();
	
		std::string getName();	
		bool isPassable();
		bool isCloud();
	
	private:
		std::string mName;
		bool mIsPassable;
		bool mIsCloud;
	
};

#endif
