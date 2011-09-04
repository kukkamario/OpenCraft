#include "glinclude.h"


PFNGLGENBUFFERSARBPROC mglGenBuffersARB;
PFNGLBINDBUFFERARBPROC mglBindBufferARB;
PFNGLBUFFERDATAARBPROC mglBufferDataARB;
PFNGLDELETEBUFFERSARBPROC mglDeleteBuffersARB;


bool loadExtension()
{
    if (glutExtensionSupported("GL_ARB_vertex_buffer_object") == GL_FALSE)
    {
        return false;
    }
    mglGenBuffersARB  = (PFNGLGENBUFFERSARBPROC)glutGetProcAddress("glGenBuffersARB");
    mglBindBufferARB = (PFNGLBINDBUFFERARBPROC)glutGetProcAddress("glBindBufferARB");
    mglBufferDataARB = (PFNGLBUFFERDATAARBPROC)glutGetProcAddress("glBufferDataARB");
    mglDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC)glutGetProcAddress("glDeleteBuffersARB");
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
        mglDeleteBuffersARB(n,buffers);
}

