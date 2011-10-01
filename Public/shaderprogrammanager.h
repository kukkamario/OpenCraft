#ifndef SHADERPROGRAMMANAGER_H
#define SHADERPROGRAMMANAGER_H
#include "shaderprogram.h"
#include <QMap>
#define MAX_SHADER_PROGRAMS 64
#define INVALID_SHADER_PROGRAM_PTR (-1)
typedef char ShaderProgramHandle;

class ShaderProgramManager:QObject
{
    Q_OBJECT
public:
    enum QualityMode
    {
        Low,
        Medium,
        High
    };

    enum CustomMode
    {
        NoCustom,
        UnderWater
    };

    ShaderProgramManager(QObject *parent = 0);
    ~ShaderProgramManager();
    ShaderProgram *find(const ShaderProgramHandle ptr){return mShaderProgramArray[ptr]->mPtr;}
    ShaderProgram *find(const QString &name){if (!mShaderPrograms.contains(name)) return 0;return mShaderPrograms[name]->mPtr;}
    ShaderProgramHandle load(const QString &path,QualityMode qmode = Medium,CustomMode cmode = NoCustom);

private:
    struct ShaderProgramInfo
    {
        QString mName;
        ShaderProgram *mPtr;
        QString mPath;
    };

    QMap<QString,ShaderProgramInfo*> mShaderPrograms;
    ShaderProgramInfo *mShaderProgramArray[MAX_SHADER_PROGRAMS];
    int mShaderProgramPtrCounter;
};

#endif // SHADERPROGRAMMANAGER_H
