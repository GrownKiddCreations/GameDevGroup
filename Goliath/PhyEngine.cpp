#include "PhyEngine.h"
#include "Entity.h"
#include "Vector2.h"

PhyEngine::PhyEngine()
{

}

PhyEngine::~PhyEngine(void)
{
}

void PhyEngine::step(World* world)
{

	std::set<Entity *>::iterator iter;
	for (iter=world->mEntitySet.begin() ; iter != world->mEntitySet.end(); iter++)
	{
		Entity *entity = *iter;
		Vector2 proposedDisplacement = entity->getProposedDisplacement();
		Vector2 finalDisplacement(0.0, 0.0);
		Vector2 currentPosition = entity->mPosition2D;

		// check that the entity is within the world bounds
		if (proposedDisplacement.x != 0)
		{
			if (proposedDisplacement.x < 0)
			{
				if (currentPosition.x + proposedDisplacement.x < 0)
				{
					finalDisplacement.x = 0;
				}
				else
				{
					finalDisplacement.x = proposedDisplacement.x;
				}
			}
			else
			{
				if (currentPosition.x + entity->getWidth() + proposedDisplacement.x > world->mWidth * TILE_SIZE)
				{
					finalDisplacement.x = 0;
				}
				else
				{
					finalDisplacement.x = proposedDisplacement.x;
				}
			}
		}

		if (proposedDisplacement.y != 0)
		{
			if (proposedDisplacement.y < 0)
			{
				if (currentPosition.y + proposedDisplacement.y < 0)
				{
					finalDisplacement.y = 0;
				}
				else
				{
					finalDisplacement.y = proposedDisplacement.y;
				}
			}
			else
			{
				if (currentPosition.y + entity->getHeight() + proposedDisplacement.y > world->mHeight * TILE_SIZE)
				{
					finalDisplacement.y = 0;
				}
				else
				{
					finalDisplacement.y = proposedDisplacement.y;
				}
			}
		}

		// TODO: check collision with non passable tiles

		// TODO: check collision with other entities

		Vector2 finalPosition = entity->mPosition2D;
		finalPosition.x += finalDisplacement.x;
		finalPosition.y += finalDisplacement.y;

		entity->setPosition(finalPosition);
		entity->setProposedDisplacement(0, 0);
	}

}
