#include "shaderprogrammanager.h"
#include <QFile>
#include <QDataStream>
#include <QTextStream>
#include "errorhandler.h"
#include <QGLShader>
#include "glinclude/glinclude.h"

#define MAGIC_NUMBER (0x01412533)


ShaderProgramManager::ShaderProgramManager(QObject *parent)
    :QObject(parent)
{
    mShaderProgramPtrCounter = 1;
    memset(mShaderProgramArray,0,MAX_SHADER_PROGRAMS*sizeof(ShaderProgramInfo*));
}

ShaderProgramManager::~ShaderProgramManager()
{
    for (int i = 0;i != MAX_SHADER_PROGRAMS;i++)
    {
        if (mShaderProgramArray[i]) delete mShaderProgramArray[i];
    }
}

ShaderProgramHandle ShaderProgramManager::load(const QString &path, QualityMode qmode, CustomMode cmode)
{
    Q_ASSERT(mShaderProgramPtrCounter < MAX_SHADER_PROGRAMS);
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        ErrorHandler::instance()->raiseError(QString("Can't open shaderprogram file %1").arg(path));
        return -1;
    }

    int magicnum = 0;
    QDataStream in(&file);
    in >> magicnum;
    if (magicnum != MAGIC_NUMBER)
    {
        ErrorHandler::instance()->raiseError(QString("Invalid shaderprogram file %1").arg(path));
        file.close();
        return -1;
    }

    int versionnum;
    in >> versionnum;
    if (versionnum != 0x00000001)
    {
        ErrorHandler::instance()->raiseError(QString("Invalid shaderprogram file version %1").arg(path));
        return -1;
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
        return -1;
    }
    else
    {
        ErrorHandler::instance()->debugPrint(tr("Fragmentshader of %1 compile log: %2").arg(path,fragmentShader->log()));
    }


    ShaderProgram *program = new ShaderProgram(this);
    program->addShader(vertexShader);
    program->addShader(fragmentShader);
    program->bindAttributeLocation("position",GLSL_POS_VERTEX_COORDS);
    program->bindAttributeLocation("normal",GLSL_POS_NORMAL);
    program->bindAttributeLocation("texCoord",GLSL_POS_TEXTURE_COORDS);
    program->bindAttributeLocation("color",GLSL_POS_COLOR);
    if (!program->link())
    {
        ErrorHandler::instance()->raiseError(tr("Linking of %1 failed. \n OpenGL log: %2").arg(path,program->log()));

        delete program;
        delete vertexShader;
        delete fragmentShader;
        return -1;
    }
    program->checkTextureLocation();

    ShaderProgramInfo *info = new ShaderProgramInfo;
    info->mPtr = program;
    info->mName = name;
    info->mPath = path;

    mShaderPrograms[name] = info;
    mShaderProgramArray[mShaderProgramPtrCounter] = info;

    return mShaderProgramPtrCounter++;
}
