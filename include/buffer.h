#ifndef BUFFER_H
#define BUFFER_h

class buffer {
private:
    unsigned bufferID;
    unsigned bufferType;

public:
    void setBufferType(unsigned type);
    void genBuffer();
    void bindBuffer();
    void sendData(unsigned size, const void* data);
};
#endif