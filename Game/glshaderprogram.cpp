#include "glshaderprogram.h"
#include "errorhandler.h"
#include <QFile>
#include <QDataStream>
#include <QStringList>


#define MAGIC_NUMBER (0x01412533)

glShaderProgram::glShaderProgram()
{
    mPtr = glCreateProgram();
    mVertexShader = 0;
    mFragmentShader = 0;
}

void glShaderProgram::setVertexShader(glShader *shader)
{
    Q_ASSERT(mVertexShader != 0);
    mVertexShader = shader;
    glAttachShader(mPtr,mVertexShader->ptr());
}

void glShaderProgram::setFragmentShader(glShader *shader)
{
    Q_ASSERT(mFragmentShader != 0);
    mFragmentShader = shader;
    glAttachShader(mPtr,mFragmentShader->ptr());
}

bool glShaderProgram::load(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        ErrorHandler::instance()->raiseError(QString("Can't open shaderprogram file %1").arg(path));
        return false;
    }

    int magicnum = 0;
    QDataStream in(&file);
    in >> magicnum;
    if (magicnum != MAGIC_NUMBER)
    {
        ErrorHandler::instance()->raiseError(QString("Invalid shaderprogram file %1").arg(path));
        file.close();
        return false;
    }

    int versionnum;
    in >> versionnum;
    if (versionnum != 0x00000001)
    {
        ErrorHandler::instance()->raiseError(QString("Invalid shaderprogram file version %1").arg(path));
        return false;
    }

    QString name;
    in >> name;

    int size;
    QStringList vertexShaderS;
    QStringList fragmentShaderS;

    in >> size;
    for (int i = 0; i != size;i++)
    {
        QString line;
        in >> line;
        vertexShaderS << line;
    }

    in >> size;
    for (int i = 0; i != size;i++)
    {
        QString line;
        in >> line;
        fragmentShaderS << line;
    }

    glShader *vertexShader = new glShader();
    if (!vertexShader->load(vertexShaderS,glShader::VertexShader)) return false;
    setVertexShader(vertexShader);

    glShader *fragmentShader = new glShader();
    if (!fragmentShader->load(fragmentShaderS,glShader::FragmentShader)) return false;
    setFragmentShader(fragmentShader);

    return true;
}

bool glShaderProgram::link()
{
    glLinkProgram(mPtr);

    int state;
    glGetObjectParameteriv(mPtr,GL_OBJECT_LINK_STATUS_ARB,&state);
    return state;
}
