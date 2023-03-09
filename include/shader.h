#ifndef SHADER_H
#define SHADER_H
#include "string"

class shader
{
public:
  enum SHADER_TYPE
  {
    NODEF,
    VS,
    TCS,
    TES,
    GS,
    FS
  };
  shader() : compiled(false), shaderTy(NODEF), ret(0), shaderID(-1){};
  shader(const shader &) = delete;

  bool compile();

  void getShaderFromFile(SHADER_TYPE shaderTy, std::string path);
  bool isCompiled() { return compiled; }
  unsigned getShaderID() { return shaderID; }
  const std::string &getErrInfo() const { return errInfo; }

private:
  std::string shaderContent;
  std::string errInfo;
  int ret;
  bool compiled;
  SHADER_TYPE shaderTy;
  unsigned shaderID;
  void genShaderID();
};
#endif