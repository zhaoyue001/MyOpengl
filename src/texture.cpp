#include "texture.h"
#include "glad/glad.h"

bool texture::set2DTexture(std::string path) {
  glGenTextures(1, &textureID);
  glBindTexture(GL_TEXTURE_2D, textureID);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  reader.loadImage(path, width, height, channels);
  if (!reader.getData()) {
    return false;
  }
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
               GL_UNSIGNED_BYTE, reader.getData());
  glGenerateMipmap(GL_TEXTURE_2D);
  return true;
}