#include <texture.h>
#include "stb_image.h"
bool Texture::loadPicture(const GLchar *picturePath)
{
    picture = stbi_load(picturePath, &width, &height, &nrChannels, 0);
    if (!picture) {
        std::cout << "Failed to load texture" << std::endl;
        return false;
    }

    return true;
}

bool Texture::genTexture2D()
{
    glGenTextures(1, &ID);
    bindTextureTo2D();
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, picture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);   
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    return true;
}

bool Texture::bindTextureTo2D() {
    glBindTexture(GL_TEXTURE_2D, ID);
    return true;
}
Texture::~Texture() {
    if (picture) {
        stbi_image_free(picture);
    }
}