#ifndef SHADER_H
#define SHADER_H
#include "string"
enum SHADER_TYPE { VS, TCS, TES, GS, FS };
class shader {
public:
  shader() {};

  void getShaderFromFile(SHADER_TYPE shaderTy, std::string path);
  bool compile();
  unsigned getShaderID();

private:
  std::string shaderContent;
  SHADER_TYPE shaderTy;
  unsigned shaderID;
  void genShaderID();
};
#endif