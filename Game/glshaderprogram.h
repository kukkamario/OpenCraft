#ifndef GLSHADERPROGRAM_H
#define GLSHADERPROGRAM_H
#include "glshader.h"
#include <QList>

class glShaderProgram
{
public:
    glShaderProgram();
    bool load(const QString &path);
    void setVertexShader(glShader *shader);
    void setFragmentShader(glShader *shader);
    bool link();
    void use();
private:
    glShader *mVertexShader;
    glShader *mFragmentShader;
    GLuint mPtr;
};

#endif // GLSHADERPROGRAM_H
