#include "glinclude.h"


PFNGLGENBUFFERSARBPROC mglGenBuffersARB;
PFNGLBINDBUFFERARBPROC mglBindBufferARB;
PFNGLBUFFERDATAARBPROC mglBufferDataARB;
PFNGLDELETEBUFFERSARBPROC mglDeleteBuffersARB;

bool loadExtension()
{
	if (!glfwExtensionSupported("GL_ARB_vertex_buffer_object"))
	{
		return false;
	}
	mglGenBuffersARB  = (PFNGLGENBUFFERSARBPROC)glfwGetProcAddress("glGenBuffersARB");
	mglBindBufferARB = (PFNGLBINDBUFFERARBPROC) glfwGetProcAddress("glBindBufferARB");
	mglBufferDataARB = (PFNGLBUFFERDATAARBPROC) glfwGetProcAddress("glBufferDataARB");
	mglDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC) glfwGetProcAddress("glDeleteBuffersARB");
	return true;
}

void glGenBuffersARB(GLsizei n,GLuint *buffers)
{
	mglGenBuffersARB(n,buffers);
}

void glBindBufferARB(GLenum target, GLuint buffer)
{
	mglBindBufferARB(target,buffer);
}

void glBufferDataARB(GLenum target,GLsizeiptrARB size,const GLvoid *data,GLenum usage)
{
	mglBufferDataARB(target,size,data,usage);
}

void glDeleteBufferARB(GLsizei n,GLuint *buffers)
{
	mglDeleteBuffersARB(size,buffers);
}

