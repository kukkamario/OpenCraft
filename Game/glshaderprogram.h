#ifndef GLSHADERPROGRAM_H
#define GLSHADERPROGRAM_H
#include "glshader.h"
#include <QList>

class glShaderProgram
{
public:
    glShaderProgram();
    bool attach(glShader *shader);
    bool compile();
    void use();
private:
    QList<glShader*> mShaders;
};

#endif // GLSHADERPROGRAM_H
