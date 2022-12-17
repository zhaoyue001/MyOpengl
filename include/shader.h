#ifndef SHADER_H
#define SHADER_H
#include "string"
enum SHADER_TYPE
{
  VS,
  TCS,
  TES,
  GS,
  FS
};
class shader
{
public:
  shader(){};

  void getShaderFromFile(SHADER_TYPE shaderTy, std::string path);
  bool compile();
  bool isCompiled() { return compiled; }
  unsigned getShaderID() { return shaderID; }
  const std::string &getErrInfo() const { return errInfo; }

private:
  std::string shaderContent;
  std::string errInfo;
  int ret = 0;
  bool compiled = false;
  SHADER_TYPE shaderTy;
  unsigned shaderID;
  void genShaderID();
};
#endif