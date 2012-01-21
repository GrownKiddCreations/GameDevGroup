#ifndef _WORLD_H
#define _WORLD_H

#include <vector>

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

        std::vector<Entity*> getEntities();
        void setEntities(std::vector<Entity*> entities);

    private:
        int mWidth;
        int mHeight;
        std::vector<TileType *> mTileTypes;
        std::vector<std::vector<Tile*> *> *mMatrix;
        std::vector<Entity*> mEntities;

        friend class RenderEngine;
};

#endif
