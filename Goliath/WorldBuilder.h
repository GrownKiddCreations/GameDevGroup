/*
 * WorldBuilder.h
 *
 *  Created on: Jan 21, 2012
 *      Author: Martin
 */

#ifndef WORLDBUILDER_H_
#define WORLDBUILDER_H_

#include "World.h"

class WorldBuilder
{
public:
	virtual World* build(void) = 0;
};

#endif /* WORLDBUILDER_H_ */
