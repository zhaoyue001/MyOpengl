#include "program.h"
#include <glad/glad.h>

program::~program() {
  glDeleteVertexArrays(1, &getVAO());
  glDeleteBuffers(1, &getVBO());
  glDeleteBuffers(1, &getEBO());
  glDeleteProgram(getProgramID());
}

bool program::compileVertexShader(std::string path) {
  vs.getShaderFromFile(shader::VS, SHADERS_PATH + path);
  return vs.compile();
}

bool program::compileGeometryShader(std::string path) {
  gs.getShaderFromFile(shader::GS, SHADERS_PATH + path);
  return gs.compile();
}

bool program::compileFragmentShader(std::string path) {
  fs.getShaderFromFile(shader::FS, SHADERS_PATH + path);
  return fs.compile();
}

void program::genProgID() { progID = glCreateProgram(); }

void program::attachShaders() {
  if (vs.isCompiled())
    glAttachShader(progID, vs.getShaderID());
  if (fs.isCompiled())
    glAttachShader(progID, fs.getShaderID());
  if (gs.isCompiled())
    glAttachShader(progID, gs.getShaderID());
}

bool program::link() {
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

void program::drawElement(MODE mode, unsigned count, ELE_TYPE eleTypem, unsigned indices)
{
  glDrawElements(GL_POINTS + mode, count, GL_BYTE + eleTypem, 0);
}
void program::bindVertexArray() { glBindVertexArray(getVAO()); }

void program::clear(float R, float G, float B, float A) {
  glClearColor(R, G, B, A);
  glClear(GL_COLOR_BUFFER_BIT);
}

void program::freeShaders() {
  if (vs.isCompiled())
    glDeleteShader(vs.getShaderID());
  if (fs.isCompiled())
    glDeleteShader(fs.getShaderID());
  if (gs.isCompiled())
    glDeleteShader(gs.getShaderID());
}

void program::setVAO() {
  if (VAO == 0)
    glGenVertexArrays(1, &VAO);
  glBindVertexArray(VAO);
}

void program::setVBO(const void *data, unsigned dataSize) {
  if (VBO == 0)
    glGenBuffers(1, &VBO);
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferData(GL_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
}

void program::setEBO(const void *data, unsigned dataSize) {
  if (EBO == 0)
    glGenBuffers(1, &EBO);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, dataSize, data, GL_STATIC_DRAW);
}

void program::setAttribute(unsigned location, unsigned size, unsigned type,
                           unsigned stride, unsigned offset) {
  glVertexAttribPointer(location, size, type, GL_FALSE, stride, (void *)offset);
  glEnableVertexAttribArray(location);
}

bool program::setTexture(std::string path) {
  return tex.set2DTexture(RESOURCE_PATH + path);
}

bool program::setUnifrom(std::string name, unsigned count, void *data,
                         uniform::TYPE type) {
  uniform uni(progID);
  uni.setData(name, count, data, type);
}

void program::use() { glUseProgram(progID); }