#include <math.h>
#include <cstdlib>
#include <iostream>
#include <exception>
#include <stdexcept>

#include "Tile.h"
#include "Entity.h"
#include "Vector2.h"
#include "PhyEngine.h"

const int TL = 0, BL = 1, BR = 2, TR = 3, X_ELM = 0, Y_ELM = 1;

PhyEngine::PhyEngine()
{

}

PhyEngine::~PhyEngine(void)
{
}

void PhyEngine::step(World* world)
{
    /*TODO
     * 1.For each entity in the list we need to adjust the gravity on a continually updating basis(constant change ie 9.8(m/s)^2)  and institute terminal velocity
     * 2.Slow horizontal movement down
     * 3.when jumping: speed moving "up" is much faster than while "falling"
     */

    const float     GRAVITY = -25;//gravity constant
	const int       WORLD_LIMIT_X = world->getWidth() * TILE_SIZE;//TODO explanation needed
	const int       WORLD_LIMIT_Y = world->getHeight() * TILE_SIZE;//TODO explanation needed

	const float     damping_coefficient = 0.04; // terrain types will need to have their own damping

	std::set<Entity *>::iterator iter;
	for (iter=world->mEntitySet.begin() ; iter != world->mEntitySet.end(); iter++)
	{
		Entity *entity = *iter;

		entity->addForce(0.0, GRAVITY); //adding gravity

		Vector2<float> impulse = entity->getImpulse();
		Vector2<float> force = entity->getForce();
		Vector2<float> velocity = entity->getVelocity();

		entity->setImpulse(0, 0); // clear
		entity->setForce(0, 0); // clear

		// f = ma
		velocity.x += (force.x / entity->getMass());
		velocity.y += (force.y / entity->getMass());

		velocity.x += impulse.x;
		velocity.y += impulse.y;

		velocity.scale(1.0 - damping_coefficient);//TODO explanation needed

		//TODO dampen decent; distance to small for terminal velocity
		if (velocity.magnitude() > TERMINAL_VELOCITY)
		{
			velocity.makeUnit()->scale(TERMINAL_VELOCITY);
		}

		Vector2<float> proposedDisplacement(velocity.x, velocity.y);

		if (entity->isOnPlatformDown(world) && proposedDisplacement.y <= 0)
		{
			velocity.y = 0;
			proposedDisplacement.y = 0;
		}

		Vector2<float> currentPosition = entity->getPosition2D();
		Vector2<float> finalPosition = entity->getPosition2D();

		Tile *tile = NULL;

		int currentBox[4][2];//4 arrays of 2 elements
		int finalBox[4][2];//4 arrays of 2 elements

		// topleft
		currentBox[TL][X_ELM] = (currentPosition.x) / TILE_SIZE;
		currentBox[TL][Y_ELM] = (currentPosition.y + entity->getHeight()) / TILE_SIZE;
		// bottomleft
		currentBox[BL][X_ELM] = (currentPosition.x) / TILE_SIZE;
		currentBox[BL][Y_ELM] = (currentPosition.y) / TILE_SIZE;
		// bottomright
		currentBox[BR][X_ELM] = (currentPosition.x + entity->getWidth()) / TILE_SIZE;
		currentBox[BR][Y_ELM] = (currentPosition.y) / TILE_SIZE;
		// topright
		currentBox[TR][X_ELM] = (currentPosition.x + entity->getWidth()) / TILE_SIZE;
		currentBox[TR][Y_ELM] = (currentPosition.y + entity->getHeight()) / TILE_SIZE;

		// topleft
		finalBox[TL][X_ELM] = (currentPosition.x + proposedDisplacement.x) / TILE_SIZE;
		finalBox[TL][Y_ELM] = (currentPosition.y + proposedDisplacement.y + entity->getHeight()) / TILE_SIZE;
		// bottomleft
		finalBox[BL][X_ELM] = (currentPosition.x + proposedDisplacement.x) / TILE_SIZE;
		finalBox[BL][Y_ELM] = (currentPosition.y + proposedDisplacement.y) / TILE_SIZE;
		// bottomright
		finalBox[BR][X_ELM] = (currentPosition.x + proposedDisplacement.x + entity->getWidth()) / TILE_SIZE;
		finalBox[BR][Y_ELM] = (currentPosition.y + proposedDisplacement.y) / TILE_SIZE;
		// topright
		finalBox[TR][X_ELM] = (currentPosition.x + proposedDisplacement.x + entity->getWidth()) / TILE_SIZE;
		finalBox[TR][Y_ELM] = (currentPosition.y + proposedDisplacement.y + entity->getHeight()) / TILE_SIZE;

		finalPosition.x += proposedDisplacement.x;
		finalPosition.y += proposedDisplacement.y;

		// get directions the entity is traveling in
		bool up = false, left = false, down = false, right = false;

		if (velocity.x < 0)
		{
			left = true;
		}
		else if (velocity.x > 0)
		{
			right = true;
		}

		if (velocity.y < 0)
		{
			down = true;
		}
		else if (velocity.y > 0)
		{
			up = true;
		}

		// enforce world bounds
		if (finalPosition.x < 0)
		{
			finalPosition.x = 0;
			velocity.x = 0;
		}

		if (finalPosition.y < 0)
		{
			finalPosition.y = 0;
			velocity.y = 0;
		}

		if (finalPosition.x + entity->getWidth() > WORLD_LIMIT_X)
		{
			finalPosition.x = WORLD_LIMIT_X - entity->getWidth();
			velocity.x = 0;
		}

		if (finalPosition.y + entity->getHeight() > WORLD_LIMIT_Y)
		{
			finalPosition.y = WORLD_LIMIT_Y - entity->getHeight();
			velocity.y = 0;
		}

		// check collision with non-passable tiles

		// left
		if (left)
		{
			if (currentBox[TL][X_ELM] != finalBox[TL][X_ELM])
			{
				int entity_tiles_vertical = finalBox[TL][Y_ELM] - finalBox[BL][Y_ELM] + 1;//what is entity_tiles_vertical? number of tiles contained within entity?

				for (int i = 0; i < entity_tiles_vertical; ++i)
				{
					tile = world->getTile(finalBox[TL][X_ELM], finalBox[TL][Y_ELM] - i);
					if (tile != NULL && !tile->getType()->isPassable())
					{
						finalPosition.x = (finalBox[TL][X_ELM] * TILE_SIZE) + TILE_SIZE + 1;
						velocity.x = 0;
						break;
					}
				}
				tile = NULL;
			}
		}
		// right
		else if (right)
		{
			if (currentBox[TR][X_ELM] != finalBox[TR][X_ELM])
			{
				int entity_tiles_vertical = finalBox[TL][Y_ELM] - finalBox[BL][Y_ELM] + 1;

				for (int i = 0; i < entity_tiles_vertical; ++i)
				{
					try
					{
						tile = world->getTile(finalBox[TR][X_ELM], finalBox[TR][Y_ELM] - i);
						if (tile != NULL && !tile->getType()->isPassable())
						{
							finalPosition.x = (finalBox[TR][X_ELM] * TILE_SIZE) - entity->getWidth() - 1;
							velocity.x = 0;
							break;
						}
					}
					catch (std::out_of_range &e)
					{
						std::cout << "out of bounds!\n";
					}
				}
				tile = NULL;
			}
		}

		// up
		if (up)
		{
			if (currentBox[TL][Y_ELM] != finalBox[TL][Y_ELM])
			{
				int entity_tiles_horizontal = finalBox[TR][X_ELM] - finalBox[TL][X_ELM] + 1;

				for (int i = 0; i < entity_tiles_horizontal; ++i)
				{
					try
					{
						tile = world->getTile(finalBox[TR][X_ELM] - i, finalBox[TR][Y_ELM]);
						if (tile != NULL && !tile->getType()->isPassable())
						{
							finalPosition.y = (finalBox[TR][Y_ELM] * TILE_SIZE) - entity->getHeight() - 1;
							velocity.y = 0;
							break;
						}
					}
					catch (std::out_of_range &e)
					{
						std::cout << "out of bounds!\n";
					}
				}
				tile = NULL;
			}
		}
		// down
		else if (down)
		{
			if (currentBox[BL][Y_ELM] != finalBox[BL][Y_ELM])
			{
				int entity_tiles_horizontal = finalBox[TR][X_ELM] - finalBox[TL][X_ELM] + 1;

				for (int i = 0; i < entity_tiles_horizontal; ++i)
				{
					tile = world->getTile(finalBox[TR][X_ELM] - i, finalBox[BL][Y_ELM]);
					if (tile != NULL && !tile->getType()->isPassable())
					{
						finalPosition.y = (finalBox[BL][Y_ELM] * TILE_SIZE) + TILE_SIZE;
						velocity.y = 0;
						break;
					}
				}
				tile = NULL;
			}
		}

		// TODO: check collision with other entities

		entity->setPosition(finalPosition);
		entity->setVelocity(velocity.x, velocity.y);
	}

}
