#ifndef TEXTURE_H
#define TEXTURE_H
#include "imageReader.h"
#include <string>
class texture {
public:
  texture() {}
  bool set2DTexture(std::string path);

private:
  unsigned textureID;
  imgReader reader;
  int width;
  int height;
  int channels;
};
#endif