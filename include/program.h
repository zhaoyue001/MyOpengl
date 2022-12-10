#ifndef PROGRAM_H
#define PROGRAM_H
#include "shader.h"
class program {
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
private:
    shader vs;
    shader gs;
    shader fs;
    unsigned progID;

    int ret = 0;
    std::string errInfo;
    void genProgID();
    void attachShaders();
};
#endif