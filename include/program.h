#ifndef PROGRAM_H
#define PROGRAM_H
#include "config.h"
#include "shader.h"
#include "texture.h"
#include "uniform.h"

class program {
public:
  enum MODE {
    POINTS,
    LINES,
    LINE_LOOP,
    LINE_STRIP,
    TRIANGLES,
    TRIANGLE_STRIP,
    TRIANGLE_FAN
  };
  enum ELE_TYPE {
    BYTE = 0,
    UNSIGNED_BYTE,
    SHORT,
    UNSIGNED_SHORT,
    INT,
    UNSIGNED_INT,
    FLOAT
  };
  program() {}
  ~program();
  bool compileVertexShader(std::string path);
  bool compileFragmentShader(std::string path);
  bool compileGeometryShader(std::string path);
  bool link();
  void use();
  void bindVertexArray();
  void drawElement(MODE mode, unsigned count, ELE_TYPE eleTypem,
                   unsigned indices);
  void setVAO();
  void setVBO(const void *data, unsigned dataSize);
  void setEBO(const void *data, unsigned dataSize);
  void setAttribute(unsigned location, unsigned size, unsigned type,
                    unsigned stride, unsigned offset);
  bool setTexture(std::string path);
  bool setUnifrom(std::string name, unsigned count, void *data,
                  uniform::TYPE type);

  void clear(float R, float G, float B, float A);

  unsigned &getVAO() { return VAO; }
  unsigned &getVBO() { return VBO; }
  unsigned &getEBO() { return EBO; }
  unsigned getVSID() { return vs.getShaderID(); }
  unsigned getFSID() { return fs.getShaderID(); }
  unsigned getGSID() { return gs.getShaderID(); }
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

  unsigned VAO = 0;
  unsigned VBO = 0;
  unsigned EBO = 0;

  texture tex;
};
#endif