#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <string>

class Texture
{
    public:
        Texture(void);
        Texture(std::string);
        ~Texture(void);

        void load(bool);
        void bind();


    private:
        std::string mFilename;
        int mWidth, mHeight, mBitsPerPixel;
        unsigned int mId;
};

#endif //TEXTURE_H
