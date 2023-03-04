#define STB_IMAGE_IMPLEMENTATION
#include "imageReader.h"
#include "stb_image.h"
void imgReader::loadImage(std::string file, int& width, int& height, int& nrChannels) {
    imgData = stbi_load(file.c_str(), &width, &height, &nrChannels, 0);
}
void imgReader::freeImage() {
    stbi_image_free(imgData);
}