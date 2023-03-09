#include "uniform.h"
#include "glad/glad.h"

int uniform::getLocation(std::string name) {
  return glGetUniformLocation(programID, name.c_str());
}

void uniform::setData(std::string name, unsigned count, void *data, TYPE type) {
  int location = getLocation(name);
  switch (type) {
  case FLOAT1:
    glUniform1f(location, *(float *)data);
    break;
  case FLOAT2:
    glUniform2f(location, *(float *)data, *((float *)data + 1));
    break;
  case FLOAT3:
    glUniform3f(location, *(float *)data, *((float *)data + 1),
                *((float *)data + 2));
    break;
  case FLOAT4:
    glUniform4f(location, *(float *)data, *((float *)data + 1),
                *((float *)data + 2), *((float *)data + 3));
    break;
  case INT1:
    glUniform1i(location, *(int *)data);
    break;
  case INT2:
    glUniform2i(location, *(int *)data, *((int *)data + 1));
    break;
  case INT3:
    glUniform3i(location, *(int *)data, *((int *)data + 1), *((int *)data + 2));
    break;
  case INT4:
    glUniform4i(location, *(int *)data, *((int *)data + 1), *((int *)data + 2),
                *((int *)data + 3));
    break;
  case FLOATVEC1:
    glUniform1fv(location, count, (float *)data);
    break;
  case FLOATVEC2:
    glUniform2fv(location, count, (float *)data);
    break;
  case FLOATVEC3:
    glUniform3fv(location, count, (float *)data);
    break;
  case FLOATVEC4:
    glUniform4fv(location, count, (float *)data);
    break;
  case INTVEC1:
    glUniform1iv(location, count, (int *)data);
    break;
  case INTVEC2:
    glUniform2iv(location, count, (int *)data);
    break;
  case INTVEC3:
    glUniform3iv(location, count, (int *)data);
    break;
  case INTVEC4:
    glUniform4iv(location, count, (int *)data);
    break;
  case MAT2:
    glUniformMatrix2fv(location, count, false, (float *)data);
    break;
  case MAT3:
    glUniformMatrix3fv(location, count, false, (float *)data);
    break;
  case MAT4:
    glUniformMatrix4fv(location, count, false, (float *)data);
    break;
  default:
    break;
  }
}
typedef void(APIENTRYP PFNGLUNIFORM1FPROC)(GLint location, GLfloat v0);
GLAPI PFNGLUNIFORM1FPROC glad_glUniform1f;
#define glUniform1f glad_glUniform1f
typedef void(APIENTRYP PFNGLUNIFORM2FPROC)(GLint location, GLfloat v0,
                                           GLfloat v1);
GLAPI PFNGLUNIFORM2FPROC glad_glUniform2f;
#define glUniform2f glad_glUniform2f
typedef void(APIENTRYP PFNGLUNIFORM3FPROC)(GLint location, GLfloat v0,
                                           GLfloat v1, GLfloat v2);
GLAPI PFNGLUNIFORM3FPROC glad_glUniform3f;
#define glUniform3f glad_glUniform3f
typedef void(APIENTRYP PFNGLUNIFORM4FPROC)(GLint location, GLfloat v0,
                                           GLfloat v1, GLfloat v2, GLfloat v3);
GLAPI PFNGLUNIFORM4FPROC glad_glUniform4f;
#define glUniform4f glad_glUniform4f
typedef void(APIENTRYP PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
GLAPI PFNGLUNIFORM1IPROC glad_glUniform1i;
#define glUniform1i glad_glUniform1i
typedef void(APIENTRYP PFNGLUNIFORM2IPROC)(GLint location, GLint v0, GLint v1);
GLAPI PFNGLUNIFORM2IPROC glad_glUniform2i;
#define glUniform2i glad_glUniform2i
typedef void(APIENTRYP PFNGLUNIFORM3IPROC)(GLint location, GLint v0, GLint v1,
                                           GLint v2);
GLAPI PFNGLUNIFORM3IPROC glad_glUniform3i;
#define glUniform3i glad_glUniform3i
typedef void(APIENTRYP PFNGLUNIFORM4IPROC)(GLint location, GLint v0, GLint v1,
                                           GLint v2, GLint v3);
GLAPI PFNGLUNIFORM4IPROC glad_glUniform4i;
#define glUniform4i glad_glUniform4i
typedef void(APIENTRYP PFNGLUNIFORM1FVPROC)(GLint location, GLsizei count,
                                            const GLfloat *value);
GLAPI PFNGLUNIFORM1FVPROC glad_glUniform1fv;
#define glUniform1fv glad_glUniform1fv
typedef void(APIENTRYP PFNGLUNIFORM2FVPROC)(GLint location, GLsizei count,
                                            const GLfloat *value);
GLAPI PFNGLUNIFORM2FVPROC glad_glUniform2fv;
#define glUniform2fv glad_glUniform2fv
typedef void(APIENTRYP PFNGLUNIFORM3FVPROC)(GLint location, GLsizei count,
                                            const GLfloat *value);
GLAPI PFNGLUNIFORM3FVPROC glad_glUniform3fv;
#define glUniform3fv glad_glUniform3fv
typedef void(APIENTRYP PFNGLUNIFORM4FVPROC)(GLint location, GLsizei count,
                                            const GLfloat *value);
GLAPI PFNGLUNIFORM4FVPROC glad_glUniform4fv;
#define glUniform4fv glad_glUniform4fv
typedef void(APIENTRYP PFNGLUNIFORM1IVPROC)(GLint location, GLsizei count,
                                            const GLint *value);
GLAPI PFNGLUNIFORM1IVPROC glad_glUniform1iv;
#define glUniform1iv glad_glUniform1iv
typedef void(APIENTRYP PFNGLUNIFORM2IVPROC)(GLint location, GLsizei count,
                                            const GLint *value);
GLAPI PFNGLUNIFORM2IVPROC glad_glUniform2iv;
#define glUniform2iv glad_glUniform2iv
typedef void(APIENTRYP PFNGLUNIFORM3IVPROC)(GLint location, GLsizei count,
                                            const GLint *value);
GLAPI PFNGLUNIFORM3IVPROC glad_glUniform3iv;
#define glUniform3iv glad_glUniform3iv
typedef void(APIENTRYP PFNGLUNIFORM4IVPROC)(GLint location, GLsizei count,
                                            const GLint *value);
GLAPI PFNGLUNIFORM4IVPROC glad_glUniform4iv;
#define glUniform4iv glad_glUniform4iv
typedef void(APIENTRYP PFNGLUNIFORMMATRIX2FVPROC)(GLint location, GLsizei count,
                                                  GLboolean transpose,
                                                  const GLfloat *value);
GLAPI PFNGLUNIFORMMATRIX2FVPROC glad_glUniformMatrix2fv;
#define glUniformMatrix2fv glad_glUniformMatrix2fv
typedef void(APIENTRYP PFNGLUNIFORMMATRIX3FVPROC)(GLint location, GLsizei count,
                                                  GLboolean transpose,
                                                  const GLfloat *value);
GLAPI PFNGLUNIFORMMATRIX3FVPROC glad_glUniformMatrix3fv;
#define glUniformMatrix3fv glad_glUniformMatrix3fv
typedef void(APIENTRYP PFNGLUNIFORMMATRIX4FVPROC)(GLint location, GLsizei count,
                                                  GLboolean transpose,
                                                  const GLfloat *value);
GLAPI PFNGLUNIFORMMATRIX4FVPROC glad_glUniformMatrix4fv;
#define glUniformMatrix4fv glad_glUniformMatrix4fv