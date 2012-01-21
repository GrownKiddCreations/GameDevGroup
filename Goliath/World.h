#ifndef _WORLD_H
#define _WORLD_H

#include <vector>
#include <set>

#include "Tile.h"
#include "Entity.h"

class World
{
    public:
        World(int, int, std::vector<TileType *> &tileTypes);
        ~World();

        int getWidth();
        int getHeight();

        Tile* getTile(int x, int y);
        void setTile(Tile* tile, int x, int y);

        bool addEntity(Entity *);
        void removeEntity(Entity *);

        Entity* getPlayerEntity() const;
        void setPlayerEntity(Entity*); // FIXME: what if the entity is not present?

    private:
        int mWidth;
        int mHeight;
        Entity* mPlayerEntity;
        std::vector<TileType *> mTileTypes;
        std::vector<std::vector<Tile*> *> *mMatrix;
        std::set<Entity *> mEntitySet;

        friend class RenderEngine;
};

#endif
