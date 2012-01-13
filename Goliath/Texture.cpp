
#include "Texture.h"

#ifdef WIN32
#include <Windows.h>
#endif
#include "FreeImage.h"
#include <gl/glew.h>

#include <iostream>


Texture::Texture(void)
{
}

Texture::Texture(std::string filename)
{

}

Texture::~Texture(void)
{
}

void Texture::load(bool generateMipmaps)
{
    FREE_IMAGE_FORMAT imgFormat = FIF_UNKNOWN;
	FIBITMAP *dib(0);

	imgFormat = FreeImage_GetFileType(mFilename.c_str(), 0);

	std::cout << "File format: " << imgFormat << std::endl;

	if (FreeImage_FIFSupportsReading(imgFormat)) // Check if the plugin has reading capabilities and load the file
		dib = FreeImage_Load(imgFormat, mFilename.c_str());
	if (!dib)
        std::cout << "Error loading texture files!" << std::endl;
		
	BYTE* bDataPointer = FreeImage_GetBits(dib); // Retrieve the image data

	mWidth = FreeImage_GetWidth(dib); // Get the image width and height
	mHeight = FreeImage_GetHeight(dib);
	mBitsPerPixel = FreeImage_GetBPP(dib);

    if (!bDataPointer || !mWidth || !mHeight)
        std::cout << "Error loading texture files!" << std::endl;

    // Generate an OpenGL texture ID for this texture
    glGenTextures(1, &mId);
    glBindTexture(GL_TEXTURE_2D, mId); 

    int format = mBitsPerPixel == 24 ? GL_BGR_EXT : mBitsPerPixel == 8 ? GL_LUMINANCE : 0; 
    int iInternalFormat = mBitsPerPixel == 24 ? GL_RGB : GL_DEPTH_COMPONENT;  

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, mWidth, mHeight, 0, format, GL_UNSIGNED_BYTE, bDataPointer); 

    if(generateMipmaps)
      glGenerateMipmap(GL_TEXTURE_2D);

   FreeImage_Unload(dib); 
   
}