#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include <iostream>
//#include "stb_image.h"
class Texture
{
private:
    unsigned char *picture;
    int width;
    int height;
    int nrChannels;
public:
    unsigned ID;
    bool loadPicture(const GLchar *picturePath);
    bool genTexture2D();
    bool bindTextureTo2D();
    ~Texture();
};
#endif