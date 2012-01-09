#ifndef _ENTITIES_H
#define _ENTITIES_H

class Entities
{
	public:
		Entities(void);
		~Entities(void);

		int getWidth();
		int getHeight();
		int getX();
		int getY();
		int* getSpeed();
		int getDirectionX();
		int getDirectiony();

	private:
		int mSpeedX, mSpeedY;
		int mDirectionX, mDirectionY;
		int mSpeed[2];
};
