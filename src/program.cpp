#include "program.h"
#include <glad/glad.h>

bool program::compileVertexShader(std::string path) {
    vs.getShaderFromFile(VS, path);
    return vs.compile();
}

bool program::compileGeometryShader(std::string path) {
    gs.getShaderFromFile(GS, path);
    return gs.compile();
}

bool program::compileFragmentShader(std::string path) {
    fs.getShaderFromFile(FS, path);
    return fs.compile();
}

void program::genProgID() {
    progID = glCreateProgram();
}

void program::attachShaders() {
    if(vs.isCompiled())
        glAttachShader(progID, vs.getShaderID());
    if(fs.isCompiled())
        glAttachShader(progID, fs.getShaderID());
    if(gs.isCompiled())
        glAttachShader(progID, gs.getShaderID());
}

bool program::linkProgram() {
    genProgID();
    attachShaders();
    glLinkProgram(progID);
    // check for linking errors
    glGetProgramiv(progID, GL_LINK_STATUS, &ret);
    char infoLog[512];
    if (!ret) {
        glGetProgramInfoLog(progID, 512, NULL, infoLog);
        errInfo.append(infoLog);
    }
    return ret;
}

void program::freeShaders() {
    if(vs.isCompiled())
        glDeleteShader(vs.getShaderID());
    if(fs.isCompiled())
        glDeleteShader(fs.getShaderID());
    if(gs.isCompiled())
        glDeleteShader(gs.getShaderID());
}