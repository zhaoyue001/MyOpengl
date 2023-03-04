#ifndef TEXTURE_H
#define TEXTURE_H
#include <string>
#include "imageReader.h"
class texture {
public:
    texture(std::string path) : imgFilePath(path) {}
    void set2DTexture();
private:
    std::string imgFilePath;
    unsigned textureID;
    imgReader reader;
    int width;
    int height;
    int channels;

};
#endif