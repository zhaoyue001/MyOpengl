#include "program.h"
#include <glad/glad.h>

bool program::compileVertexShader(std::string path)
{
    vs.getShaderFromFile(VS, path);
    return vs.compile();
}

bool program::compileGeometryShader(std::string path)
{
    gs.getShaderFromFile(GS, path);
    return gs.compile();
}

bool program::compileFragmentShader(std::string path)
{
    fs.getShaderFromFile(FS, path);
    return fs.compile();
}

void program::genProgID()
{
    progID = glCreateProgram();
}

void program::attachShaders()
{
    if (vs.isCompiled())
        glAttachShader(progID, vs.getShaderID());
    if (fs.isCompiled())
        glAttachShader(progID, fs.getShaderID());
    if (gs.isCompiled())
        glAttachShader(progID, gs.getShaderID());
}

bool program::linkProgram()
{
    genProgID();
    attachShaders();
    glLinkProgram(progID);
    // check for linking errors
    glGetProgramiv(progID, GL_LINK_STATUS, &ret);
    char infoLog[512];
    if (!ret)
    {
        glGetProgramInfoLog(progID, 512, NULL, infoLog);
        errInfo.append(infoLog);
    }
    return ret;
}

void program::freeShaders()
{
    if (vs.isCompiled())
        glDeleteShader(vs.getShaderID());
    if (fs.isCompiled())
        glDeleteShader(fs.getShaderID());
    if (gs.isCompiled())
        glDeleteShader(gs.getShaderID());
}

void program::setVAO()
{
    if (VAO == 0)
        glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
}

void program::setVBO(const void *data, unsigned dataSize)
{
    if (VBO == 0)
        glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
}

void program::setEBO(const void *data, unsigned dataSize)
{
    if (EBO == 0)
        glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
}

void program::setAttribute(unsigned location, unsigned size, unsigned type, unsigned stride, unsigned offset)
{
    glVertexAttribPointer(location, size, type, GL_FALSE, stride, (void *)offset);
    glEnableVertexAttribArray(location);
}