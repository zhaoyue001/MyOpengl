#ifndef PROGRAM_H
#define PROGRAM_H
#include "shader.h"
class program
{
public:
    program() {}
    bool compileVertexShader(std::string path);
    bool compileFragmentShader(std::string path);
    bool compileGeometryShader(std::string path);

    unsigned getVSID() { return vs.getShaderID(); }
    unsigned getFSID() { return fs.getShaderID(); }
    unsigned getGSID() { return gs.getShaderID(); }

    bool linkProgram();
    unsigned getProgramID() { return progID; }

    void freeShaders();

    void setVAO();

    void setVBO(const void *data, unsigned dataSize);
    void setEBO(const void *data, unsigned dataSize);
    unsigned &getVAO() { return VAO; }
    unsigned &getVBO() { return VBO; }
    unsigned &getEBO() { return EBO; }

    void setAttribute(unsigned location, unsigned size, unsigned type, unsigned stride, unsigned offset);

private:
    shader vs;
    shader gs;
    shader fs;
    unsigned progID;

    int ret = 0;
    std::string errInfo;
    void genProgID();
    void attachShaders();

    unsigned VAO = 0;
    unsigned VBO = 0;
    unsigned EBO = 0;
};
#endif