#include "glinclude.h"
#include <QDebug>



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
PFNGLMULTITEXCOORD1FVPROC        glMultiTexCoord1fvProg;
PFNGLMULTITEXCOORD2FVPROC        glMultiTexCoord2fvProg;
PFNGLMULTITEXCOORD3FVPROC        glMultiTexCoord3fvProg;
PFNGLMULTITEXCOORD4FVPROC        glMultiTexCoord4fvProg;
PFNGLVERTEXATTRIBPOINTERARBPROC  glVertexAttribPointerARB;

bool loadExtension(const QGLContext *context)
{
    if (glutExtensionSupported("GL_ARB_vertex_buffer_object") == GL_FALSE)
    {
        return false;
    }
    mglGenBuffersARB  = (PFNGLGENBUFFERSARBPROC)context->getProcAddress("glGenBuffersARB");
    mglBindBufferARB = (PFNGLBINDBUFFERARBPROC)context->getProcAddress("glBindBufferARB");
    mglBufferDataARB = (PFNGLBUFFERDATAARBPROC)context->getProcAddress("glBufferDataARB");
    mglDeleteBuffersARB = (PFNGLDELETEBUFFERSARBPROC)context->getProcAddress("glDeleteBuffersARB");

    qDebug(qPrintable("OpenGL version:"+QString((const char*)glGetString(GL_VERSION))));
    if (glutExtensionSupported("GL_ARB_vertex_shader") && glutExtensionSupported("GL_ARB_fragment_shader") && glutExtensionSupported("GL_ARB_fragment_shader"))
    {
        glCreateProgramObjectARB = (PFNGLCREATEPROGRAMOBJECTARBPROC)context->getProcAddress("glCreateProgramObjectARB");
        glUseProgramObjectARB = (PFNGLUSEPROGRAMOBJECTARBPROC)context->getProcAddress("glUseProgramObjectARB");
        glCreateShaderObjectARB = (PFNGLCREATESHADEROBJECTARBPROC)context->getProcAddress("glCreateShaderObjectARB");
        glShaderSourceARB = (PFNGLSHADERSOURCEARBPROC)context->getProcAddress("glShaderSourceARB");
        glCompileShaderARB = (PFNGLCOMPILESHADERARBPROC)context->getProcAddress("glCompileShaderARB");
        glGetObjectParameterivARB = (PFNGLGETOBJECTPARAMETERIVARBPROC)context->getProcAddress("glGetObjectParameterivARB");
        glAttachObjectARB = (PFNGLATTACHOBJECTARBPROC)context->getProcAddress("glAttachObjectARB");
        glGetInfoLogARB = (PFNGLGETINFOLOGARBPROC)context->getProcAddress("glGetInfoLogARB");
        glLinkProgramARB = (PFNGLLINKPROGRAMARBPROC)context->getProcAddress("glLinkProgramARB");
        glGetUniformLocationARB = (PFNGLGETUNIFORMLOCATIONARBPROC)context->getProcAddress("glGetUniformLocationARB");
        glUniform1iARB = (PFNGLUNIFORM1IARBPROC)context->getProcAddress("glUniform1iARB");
        glDeleteObjectARB = (PFNGLDELETEOBJECTARBPROC)context->getProcAddress("glDeleteObjectARB");
        glMultiTexCoord1fvProg = (PFNGLMULTITEXCOORD1FVPROC)context->getProcAddress("glMultiTexCoord1fv");
        glMultiTexCoord2fvProg = (PFNGLMULTITEXCOORD2FVPROC)context->getProcAddress("glMultiTexCoord2fv");
        glMultiTexCoord3fvProg = (PFNGLMULTITEXCOORD3FVPROC)context->getProcAddress("glMultiTexCoord3fv");
        glMultiTexCoord4fvProg = (PFNGLMULTITEXCOORD4FVPROC)context->getProcAddress("glMultiTexCoord4fv");
        glVertexAttribPointerARB = (PFNGLVERTEXATTRIBPOINTERARBPROC)context->getProcAddress("glVertexAttribPointerARB");
    }
    else
    {
        qDebug("Graphicscard doesn't support shaders.");
        return false;
    }
    if (glutExtensionSupported("GL_ARB_texture_non_power_of_two") == GL_FALSE){

        qCritical("Extension not supported...");
        return false;

    }
    return true;
}

void glUseProgram(GLhandleARB program)
{
    glUseProgramObjectARB(program);
}

void glShaderSource(GLhandleARB shader, int numOfStrings, const char **strings, int *lenOfStrings)
{
    glShaderSourceARB(shader,numOfStrings,strings,lenOfStrings);
}

GLhandleARB glCreateShader(GLenum shaderType)
{
    return glCreateShaderObjectARB(shaderType);
}

void glAttachShader(GLhandleARB program,GLhandleARB shader)
{
    glAttachObjectARB(program,shader);
}

void glCompileShader(GLhandleARB shader)
{
    glCompileShaderARB(shader);
}

void glUniform1i(GLhandleARB location,GLhandleARB value)
{
    glUniform1iARB(location,value);
}

void glGetUniformLocation(GLhandleARB program,const char *name)
{
    glGetUniformLocationARB(program,name);
}

GLhandleARB glCreateProgram()
{
    return glCreateProgramObjectARB();
}

void glGetInfoLog(GLhandleARB program,GLsizei maxLength,GLsizei *length,char *text)
{
    glGetInfoLogARB(program,maxLength,length,text);
}

void glLinkProgram(GLhandleARB program)
{
    glLinkProgramARB(program);
}

void glDeleteObject(GLhandleARB object)
{
    glDeleteObjectARB(object);
}

void glGetObjectParameteriv(GLhandleARB object, GLenum type, int *param)
{
    glGetObjectParameterivARB(object,type,param);
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


void glMultiTexCoord1fv(GLenum target,float *coord)
{
    glMultiTexCoord1fvProg(target,coord);
}

void glMultiTexCoord2fv(GLenum target,float *coord)
{
    glMultiTexCoord2fvProg(target,coord);
}
void glMultiTexCoord3fv(GLenum target,float *coord)
{
    glMultiTexCoord3fvProg(target,coord);
}
void glMultiTexCoord4fv(GLenum target,float *coord)
{
    glMultiTexCoord4fvProg(target,coord);
}

void glVertexAttribPointer(GLuint index,GLint size,GLenum type,GLboolean normalized,GLsizei stride,const GLvoid *pointer)
{
    glVertexAttribPointerARB(index,size,type,normalized,stride,pointer);
}
