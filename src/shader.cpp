#include "shader.h"
#include "fileReader.h"
#include <glad/glad.h>
#include "iostream"
void shader::getShaderFromFile(SHADER_TYPE shaderTy, std::string path) {
    fileReader shaderPath(path);
    shaderContent = shaderPath.getContent();
    this->shaderTy = shaderTy; 
}

void shader::genShaderID() {
    unsigned int type = 0x00; 
    switch(shaderTy) {
        case VS: type = GL_VERTEX_SHADER; break;
        case TCS: type = GL_TESS_CONTROL_SHADER; break;
        case TES: type = GL_TESS_EVALUATION_SHADER; break;
        case GS: type = GL_GEOMETRY_SHADER; break;
        case FS: type = GL_FRAGMENT_SHADER; break;
        default: assert(0 && "wrong shader type");
    }
    shaderID = glCreateShader(type);
}

bool shader::compile() {
    genShaderID();
    assert(!shaderContent.empty() && "empty shader");
    const char *addr = shaderContent.c_str();
    glShaderSource(shaderID, 1, &addr, NULL);
    glCompileShader(shaderID);
    
    int ret;
    char infoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &ret);
    if (!ret)
    {
        glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    return ret;
}

unsigned shader::getShaderID() {
    return shaderID;
}