#ifndef IMG_READER
#define IMG_READER
#define STB_IMAGE_IMPLEMENTATION
#include <string>
class imgReader
{
public:
    imgReader(){};
    void loadImage(std::string file, int& width, int& height, int& nrChannels);
    void freeImage();
    unsigned char* getData() {return imgData;}
private:
    unsigned char* imgData;
};
#endif