#include "shaderprogrammanager.h"
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include "errorhandler.h"
#include <QGLShader>

#define MAGIC_NUMBER (0x01412533)

ShaderProgramManager::ShaderProgramManager(QObject *parent)
    :QObject(parent)
{

}

ShaderProgramManager::~ShaderProgramManager()
{
}

QGLShaderProgram *ShaderProgramManager::load(const QString &path, QualityMode qmode, CustomMode cmode)
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



    QString vertexShaderS;
    QString fragmentShaderS;

    in >> vertexShaderS;
    in >> fragmentShaderS;
    file.close();

    Q_ASSERT(!mShaderPrograms.contains(name));

    switch (qmode)
    {
    case Low:
        fragmentShaderS = "#define GRAPHICS_QUALITY_LOW\n"+fragmentShaderS;
        vertexShaderS = "#define GRAPHICS_QUALITY_LOW\n"+vertexShaderS;
        break;
    case Medium:
        fragmentShaderS = "#define GRAPHICS_QUALITY_MEDIUM\n"+fragmentShaderS;
        vertexShaderS = "#define GRAPHICS_QUALITY_MEDIUM\n"+vertexShaderS;
        break;
    case High:
        fragmentShaderS = "#define GRAPHICS_QUALITY_HIGH\n"+fragmentShaderS;
        vertexShaderS = "#define GRAPHICS_QUALITY_HIGH\n"+vertexShaderS;
        break;
    }

    switch (cmode)
    {
    case NoCustom:
        fragmentShaderS = "#define MODE_NORMAL\n"+fragmentShaderS;
        vertexShaderS = "#define MODE_NORMAL\n"+vertexShaderS;
    case UnderWater:
        fragmentShaderS = "#define MODE_UNDER_WATER\n"+fragmentShaderS;
        vertexShaderS = "#define MODE_UNDER_WATER\n"+vertexShaderS;
    }


    QGLShader *vertexShader = new QGLShader(QGLShader::Vertex,this);
    if (!vertexShader->compileSourceCode(vertexShaderS))
    {
        ErrorHandler::instance()->raiseError(tr("Compiling vertexshader of %1 failed.\n OpenGL msg: %2").arg(path,vertexShader->log()));
        delete vertexShader;
    }
    else
    {
        ErrorHandler::instance()->debugPrint(tr("Vertexshader of %1 compile log: %2").arg(path,vertexShader->log()));
    }

    QGLShader *fragmentShader = new QGLShader(QGLShader::Fragment,this);
    if (!fragmentShader->compileSourceCode(vertexShaderS))
    {
        ErrorHandler::instance()->raiseError(tr("Compiling fragmentshader of %1 failed.\n OpenGL msg: %2").arg(path,fragmentShader->log()));
        delete vertexShader;
        delete fragmentShader;
        return 0;
    }
    else
    {
        ErrorHandler::instance()->debugPrint(tr("Fragmentshader of %1 compile log: %2").arg(path,fragmentShader->log()));
    }


    QGLShaderProgram *program = new QGLShaderProgram(this);
    program->addShader(vertexShader);
    program->addShader(fragmentShader);
    if (!program->link())
    {
        ErrorHandler::instance()->raiseError(tr("Linking of %1 failed. \n OpenGL log: %2").arg(path,program->log()));

        delete program;
        delete vertexShader;
        delete fragmentShader;
        return 0;
    }

    mShaderPrograms[name] = program;

    return program;
}