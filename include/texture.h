#ifndef TEXTURE_H
#define TEXTURE_H
#include <glad/glad.h>
#include <iostream>

class Texture {
private:
  unsigned char *picture;
  int width;
  int height;
  int nrChannels;

public:
  unsigned ID;
  bool loadPicture(const GLchar *picturePath);
  bool genTexture2D(GLint format);
  bool bindTextureTo2D();
  ~Texture();
};
#endif