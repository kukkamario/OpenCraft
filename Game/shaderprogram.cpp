#include "shaderprogram.h"

ShaderProgram::ShaderProgram(QObject *parent) :
    QGLShaderProgram(parent)
{
    mTextureLocation = 0;
}

void ShaderProgram::checkTextureLocation()
{
    mTextureLocation = this->uniformLocation("sampler");
}
