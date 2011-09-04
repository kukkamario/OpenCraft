#ifdef OC_WINDOWS
#include <Windows.h>
#endif
#include <gl\GL.h>
#include "glext.h"
#include <gl\GLU.h>
#include "freeglut.h"

bool loadExtension();

void glGenBuffersARB(GLsizei n,GLuint *buffers);

void glBindBufferARB(GLenum target,GLuint buffer);

void glBufferDataARB(GLenum target,GLsizeiptrARB size,const GLvoid *data,GLenum usage);

void glDeleteBufferARB(GLsizei n,GLuint *buffers);
