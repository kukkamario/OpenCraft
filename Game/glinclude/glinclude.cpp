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
PFNGLDELETEOBJECTARBPROC         glDeleteObjectARB;

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
        glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC)glutGetProcAddress("glCreateProgramObjectARB");
        glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC)glutGetProcAddress("glUseProgramObjectARB");
        glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC)glutGetProcAddress("glCreateShaderObjectARB");
        glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC)glutGetProcAddress("glShaderSourceARB");
        glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC)glutGetProcAddress("glCompileShaderARB");
        glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)glutGetProcAddress("glGetObjectParameterivARB");
        glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC)glutGetProcAddress("glAttachObjectARB");
        glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC)glutGetProcAddress("glGetInfoLogARB");
        glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC)glutGetProcAddress("glLinkProgramARB");
        glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC)glutGetProcAddress("glGetUniformLocationARB");
        glUniform1iARB = (PFNGLUNIFORM1IARBPROC)glutGetProcAddress("glUniform1iARB");
        glDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC)glutGetProcAddress("glDeleteObjectARB");
    }

    return true;
}

void glUseProgram(GLuint program)
{
    glUseProgramObjectARB(program);
}

void glCreateShader(GLenum shaderType)
{
    glCreateShaderObjectARB(shaderType);
}

void glAttachShader(GLuint program,GLuint shader)
{
    glAttachObjectARB(program,shader);
}

void glCompileShader(GLuint shader)
{
    glCompileShaderARB(shader);
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
    glCreateProgramObjectARB();
}

void glGetInfoLog(GLuint program,GLsizei maxLength,GLsizei *length,char *text)
{
    glGetInfoLogARB(program,maxLength,length,text);
}

void glLinkProgram(GLuint program)
{
    glLinkProgramARB(program);
}

void glDeleteObject(GLuint object)
{
    glDeleteObjectARB(object);
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

