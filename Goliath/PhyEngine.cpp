#include <iostream>
#include <math.h>
#include <exception>
#include <stdexcept>

#include "PhyEngine.h"
#include "Entity.h"
#include "Vector2.h"
#include "Tile.h"

PhyEngine::PhyEngine()
{

}

PhyEngine::~PhyEngine(void)
{
}

void PhyEngine::step(World* world)
{

	const int WORLD_LIMIT_X = world->getWidth() * TILE_SIZE;
	const int WORLD_LIMIT_Y = world->getHeight() * TILE_SIZE;

	std::set<Entity *>::iterator iter;
	for (iter=world->mEntitySet.begin() ; iter != world->mEntitySet.end(); iter++)
	{
		Entity *entity = *iter;

		Vector2 proposedDisplacement = entity->getProposedDisplacement();

		// apply gravity
		//proposedDisplacement.y -= 3;

		Vector2 finalDisplacement(proposedDisplacement.x, proposedDisplacement.y);
		Vector2 currentPosition = entity->mPosition2D;
		Vector2 finalPosition = entity->mPosition2D;

		// get directions
		bool up = false, left = false, down = false, right = false;

		if (finalDisplacement.x < 0)
			left = true;
		else if (finalDisplacement.x > 0)
			right = true;

		if (finalDisplacement.y < 0)
			down = true;
		else if (finalDisplacement.y > 0)
			up = true;

		int currentBox[4][2];
		int finalBox[4][2];

		// tl
		currentBox[0][0] = (currentPosition.x) / TILE_SIZE;
		currentBox[0][1] = (currentPosition.y + entity->getHeight()) / TILE_SIZE;
		// bl
		currentBox[1][0] = (currentPosition.x) / TILE_SIZE;
		currentBox[1][1] = (currentPosition.y) / TILE_SIZE;
		// br
		currentBox[2][0] = (currentPosition.x + entity->getWidth()) / TILE_SIZE;
		currentBox[2][1] = (currentPosition.y) / TILE_SIZE;
		// tr
		currentBox[3][0] = (currentPosition.x + entity->getWidth()) / TILE_SIZE;
		currentBox[3][1] = (currentPosition.y + entity->getHeight()) / TILE_SIZE;

		// tl
		finalBox[0][0] = (currentPosition.x + proposedDisplacement.x) / TILE_SIZE;
		finalBox[0][1] = (currentPosition.y + proposedDisplacement.y + entity->getHeight()) / TILE_SIZE;
		// bl
		finalBox[1][0] = (currentPosition.x + proposedDisplacement.x) / TILE_SIZE;
		finalBox[1][1] = (currentPosition.y + proposedDisplacement.y) / TILE_SIZE;
		// br
		finalBox[2][0] = (currentPosition.x + proposedDisplacement.x + entity->getWidth()) / TILE_SIZE;
		finalBox[2][1] = (currentPosition.y + proposedDisplacement.y) / TILE_SIZE;
		// tr
		finalBox[3][0] = (currentPosition.x + proposedDisplacement.x + entity->getWidth()) / TILE_SIZE;
		finalBox[3][1] = (currentPosition.y + proposedDisplacement.y + entity->getHeight()) / TILE_SIZE;

		finalPosition.x += finalDisplacement.x;
		finalPosition.y += finalDisplacement.y;

		// enforce world bounds
		if (finalPosition.x < 0)
		{
			finalPosition.x = 0;
		}

		if (finalPosition.y < 0)
		{
			finalPosition.y = 0;
		}

		if (finalPosition.x + entity->getWidth() > WORLD_LIMIT_X)
		{
			finalPosition.x = WORLD_LIMIT_X - entity->getWidth();
		}

		if (finalPosition.y + entity->getHeight() > WORLD_LIMIT_Y)
		{
			finalPosition.y = WORLD_LIMIT_Y - entity->getHeight();
		}

		// check collision with non-passable tiles
		// left-right bounds checking
		Tile *tile = NULL;
		// left
		if (left)
		{
			if (currentBox[0][0] != finalBox[0][0])
			{
				int entity_tiles_vertical = finalBox[0][1] - finalBox[1][1] + 1;

				for (int i = 0; i < entity_tiles_vertical; ++i)
				{
					tile = world->getTile(finalBox[0][0], finalBox[0][1] - i);
					if (!tile->getType()->isPassable())
					{
						finalPosition.x = (finalBox[0][0] * TILE_SIZE) + TILE_SIZE;
						break;
					}
				}
				tile = NULL;
			}
		}
		// right
		else if (right)
		{
			if (currentBox[3][0] != finalBox[3][0])
			{
				int entity_tiles_vertical = finalBox[0][1] - finalBox[1][1] + 1;

				for (int i = 0; i < entity_tiles_vertical; ++i)
				{
					try
					{
						tile = world->getTile(finalBox[3][0], finalBox[3][1] - i);
						if (!tile->getType()->isPassable())
						{
							finalPosition.x = (finalBox[3][0] * TILE_SIZE) - entity->getWidth() - 1;
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

		// left-right bounds checking
		// up
		if (up)
		{
			if (currentBox[0][1] != finalBox[0][1])
			{
				int entity_tiles_horizontal = finalBox[3][0] - finalBox[0][0] + 1;

				for (int i = 0; i < entity_tiles_horizontal; ++i)
				{
					try
					{
						tile = world->getTile(finalBox[3][0] - i, finalBox[3][1]);
						if (!tile->getType()->isPassable())
						{
							finalPosition.y = (finalBox[3][1] * TILE_SIZE) - entity->getHeight() - 1;
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
			if (currentBox[1][1] != finalBox[1][1])
			{
				int entity_tiles_horizontal = finalBox[3][0] - finalBox[0][0] + 1;

				for (int i = 0; i < entity_tiles_horizontal; ++i)
				{
					tile = world->getTile(finalBox[3][0] - i, finalBox[1][1]);
					if (!tile->getType()->isPassable())
					{
						finalPosition.y = (finalBox[1][1] * TILE_SIZE) + TILE_SIZE;
						break;
					}
				}
				tile = NULL;
			}
		}

		// TODO: check collision with other entities

		entity->setPosition(finalPosition);
		entity->setProposedDisplacement(0, 0);
	}

}
