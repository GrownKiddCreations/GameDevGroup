/*
 * SimpleWorldBuilder.h
 *
 *  Created on: Jan 21, 2012
 *      Author: Martin
 */

#ifndef SIMPLEWORLDBUILDER_H_
#define SIMPLEWORLDBUILDER_H_

#include "WorldBuilder.h"

class SimpleWorldBuilder : public WorldBuilder
{
public:
	SimpleWorldBuilder(int, int);
	virtual ~SimpleWorldBuilder(void);
	World* build(void);
	void setSize(int, int);
private:
	int mWidth;
	int mHeight;
};

#endif /* SIMPLEWORLDBUILDER_H_ */
