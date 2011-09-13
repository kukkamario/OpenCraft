#ifndef SHADERPROGRAMMANAGER_H
#define SHADERPROGRAMMANAGER_H
#include <QGLShaderProgram>
#include <QMap>

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
    QGLShaderProgram find(const QString &name);
    QGLShaderProgram *load(const QString &path,QualityMode qmode = Medium,CustomMode cmode = NoCustom);

private:
    QMap<QString,QGLShaderProgram*> mShaderPrograms;
};

#endif // SHADERPROGRAMMANAGER_H
