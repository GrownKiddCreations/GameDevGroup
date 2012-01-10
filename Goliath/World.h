#ifndef _WORLD_H
#define _WORLD_H

class World
{

	public:
		World(int, int);
        ~World();
        
		int getWidth();
		int getHeight();
	
	private:
		int mWidth;
		int mHeight;
	
};

#endif
