#ifdef OC_WINDOWS
#include <Windows.h>
#endif
#include <gl\GL.h>
#include "glext.h"
#include <gl\GLU.h>
#include <QGLContext>
#include "freeglut.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) {if(ptr) delete ptr;}
#endif
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(ptr) {if(ptr) delete[] ptr;}
#endif

#define GLSL_POS_VERTEX_COORDS 0
#define GLSL_POS_COLOR 1
#define GLSL_POS_TEXTURE_COORDS 2
#define GLSL_POS_NORMAL 3

bool loadExtension(const QGLContext *context);

void glGenBuffersARB(GLsizei n,GLuint *buffers);

void glBindBufferARB(GLenum target,GLuint buffer);

void glBufferDataARB(GLenum target,GLsizeiptrARB size,const GLvoid *data,GLenum usage);

void glDeleteBufferARB(GLsizei n,GLuint *buffers);


void glShaderSource(GLhandleARB shader, int numOfStrings, const char **strings, int *lenOfStrings);
void glGetObjectParameteriv(GLhandleARB object, GLenum type, int *param);
void glUseProgram(GLhandleARB program);

GLhandleARB glCreateShader(GLenum shaderType);

void glAttachShader(GLhandleARB program,GLhandleARB shader);

void glCompileShader(GLhandleARB shader);

void glUniform1i(GLhandleARB location,GLuint value);

void glGetUniformLocation(GLhandleARB program,const char *name);

GLhandleARB glCreateProgram();

void glGetInfoLog(GLhandleARB program,GLsizei maxLength,GLsizei *length,char *text);

void glLinkProgram(GLhandleARB program);
void glDeleteObject(GLhandleARB object);

void glMultiTexCoord1fv(GLenum target,float *coord);
void glMultiTexCoord2fv(GLenum target,float *coord);
void glMultiTexCoord3fv(GLenum target,float *coord);
void glMultiTexCoord4fv(GLenum target,float *coord);
void glVertexAttribPointer(GLuint index,GLint size,GLenum type,GLboolean normalized,GLsizei stride,const GLvoid *pointer);
