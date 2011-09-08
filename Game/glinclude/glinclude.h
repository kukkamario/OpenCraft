#ifdef OC_WINDOWS
#include <Windows.h>
#endif
#include <gl\GL.h>
#include "glext.h"
#include <gl\GLU.h>
#include "freeglut.h"

#ifndef SAFE_DELETE
#define SAFE_DELETE(ptr) {if(ptr) delete ptr;}
#endif
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(ptr) {if(ptr) delete[] ptr;}
#endif

bool loadExtension();

void glGenBuffersARB(GLsizei n,GLuint *buffers);

void glBindBufferARB(GLenum target,GLuint buffer);

void glBufferDataARB(GLenum target,GLsizeiptrARB size,const GLvoid *data,GLenum usage);

void glDeleteBufferARB(GLsizei n,GLuint *buffers);

void glUseProgram(GLuint program);

void glCreateShader(GLenum shaderType);

void glAttachShader(GLuint program,GLuint shader);

void glCompileShader(GLuint shader);

void glUniform1i(GLuint location,GLuint value);

void glGetUniformLocation(GLuint program,const char *name);

void glCreateProgram();

void glGetInfoLog(GLuint program,GLsizei maxLength,GLsizei *length,char *text);

void glLinkProgram(GLuint program);
void glDeleteObject(GLuint object);
