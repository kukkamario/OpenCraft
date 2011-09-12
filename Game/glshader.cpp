#include "glshader.h"
#include <QStringList>
#include "glinclude/glinclude.h"


glShader::glShader()
{
    mShaderPtr = 0;
}

glShader::~glShader()
{
    glDeleteObject(mShaderPtr);
}

bool glShader::load(const QStringList &shader,Type t)
{
    Q_ASSERT(isNull());
    char **lines = new char*[shader.size()];
    QStringList::const_iterator iterator = shader.begin();
    for (int i = 0; i != shader.size();i++)
    {
        lines[i] = (char*)(const char*)(*iterator).toLatin1();
    }
    mShaderPtr = glCreateShader((t == VertexShader) ? GL_VERTEX_SHADER : GL_FRAGMENT_SHADER);
    mType = t;
    glShaderSource(mShaderPtr,shader.size(),(const char**)lines,NULL);

    delete[] lines;
    return true;
}

bool glShader::compile()
{
    Q_ASSERT(mShaderPtr);
    glCompileShader(mShaderPtr);
    int state;
    glGetObjectParameteriv(mShaderPtr,GL_OBJECT_COMPILE_STATUS_ARB,&state);
    return state;
}
