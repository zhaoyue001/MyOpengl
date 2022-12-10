#include "buffer.h"
#include "glad/glad.h"

void buffer::genBuffer() {
    glGenBuffers(1, &bufferID);
}

void buffer::bindBuffer() {
     glBindBuffer(bufferType, bufferID);
}

void buffer::sendData(unsigned size, const void* data) {
    glBufferData(bufferType, size, data, bufferID);
}
void buffer::setBufferType(unsigned type) {
    bufferType = type;
}