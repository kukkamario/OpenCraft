#ifndef SHADERPROGRAM_H
#define SHADERPROGRAM_H

#include <QGLShaderProgram>

class ShaderProgram : public QGLShaderProgram
{
public:
    explicit ShaderProgram(QObject *parent = 0);
    int textureLocation()const{return mTextureLocation;}
    void checkTextureLocation();
private:
    int mTextureLocation;
};

#endif // SHADERPROGRAM_H
