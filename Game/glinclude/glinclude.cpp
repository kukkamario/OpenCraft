#include "glinclude.h"


PFNGLGENBUFFERSARBPROC mglGenBuffersARB;
PFNGLBINDBUFFERARBPROC mglBindBufferARB;
PFNGLBUFFERDATAARBPROC mglBufferDataARB;
PFNGLDELETEBUFFERSARBPROC mglDeleteBuffersARB;


PFNGLCREATEPROGRAMOBJECTARBPROC  glCreateProgramObjectARB;
PFNGLUSEPROGRAMOBJECTARBPROC     glUseProgramObjectARB;
PFNGLCREATESHADEROBJECTARBPROC   glCreateShaderObjectARB;
PFNGLSHADERSOURCEARBPROC         glShaderSourceARB;
PFNGLCOMPILESHADERARBPROC        glCompileShaderARB;
PFNGLGETOBJECTPARAMETERIVARBPROC glGetObjectParameterivARB;
PFNGLATTACHOBJECTARBPROC         glAttachObjectARB;
PFNGLLINKPROGRAMARBPROC          glLinkProgramARB;
PFNGLGETUNIFORMLOCATIONARBPROC   glGetUniformLocationARB;
PFNGLUNIFORM1IARBPROC            glUniform1iARB;
PFNGLACTIVETEXTUREARBPROC        glActiveTextureARB;
PFNGLGETINFOLOGARBPROC           glGetInfoLogARB;

bool mShaders = true;

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


    if (glutExtensionSupported("GL_ARB_vertex_shader") && glutExtensionSupported("GL_ARB_fragment_shader") && glutExtensionSupported("GL_VERSION_2_0") != GL_TRUE)
    {
        mShaders = false;
    }
    else
    {
        glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC)wglGetProcAddress("glCreateProgramObjectARB");
        glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC)wglGetProcAddress("glUseProgramObjectARB");
        glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC)wglGetProcAddress("glCreateShaderObjectARB");
        glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC)wglGetProcAddress("glShaderSourceARB");
        glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC)wglGetProcAddress("glCompileShaderARB");
        glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)wglGetProcAddress("glGetObjectParameterivARB");
        glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC)wglGetProcAddress("glAttachObjectARB");
        glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC)wglGetProcAddress("glGetInfoLogARB");
        glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC)wglGetProcAddress("glLinkProgramARB");
        glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC)wglGetProcAddress("glGetUniformLocationARB");
        glUniform1iARB = (PFNGLUNIFORM1IARBPROC)wglGetProcAddress("glUniform1iARB");
    }

    return true;
}

void glUseProgram(GLuint program)
{
    mglUseProgramARB(program);
}

void glCreateShader(GLenum shaderType)
{
    mglCreateShaderARB(shaderType);
}

void glAttachShader(GLuint program,GLuint shader)
{
    mglAttachShaderARB(program,shader);
}

void glCompileShader(GLuint shader)
{
    mglCompileShaderARB(shader);
}

void glUniform1i(GLuint location,GLuint value)
{
    glUniform1iARB(location,value);
}

void glGetUniformLocation(GLuint program,const char *name)
{
    glGetUniformLocationARB(program,name);
}

void glCreateProgram()
{
    mglCreateProgramARB();
}

void glGetInfoLog(GLuint program,GLuint maxLength,GLuint *length,char *text)
{
    glGetInfoLogARB(program,maxLength,length,text);
}

void glLinkProgram(GLuint program)
{
    mglLinkProgramARB(program);
}

void glDeleteObject(GLuint object)
{
    mglDeleteObjectARB(object);
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

