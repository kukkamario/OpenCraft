#ifndef GLSHADER_H
#define GLSHADER_H
#include "glinclude/glinclude.h"
#include <QString>
class glShaderProgram;
class glShader
{
public:
    glShader();
    ~glShader();
    void load(const QString &path);
private:
    glShaderProgram *mOwnerProgram;
    GLuint mShaderPtr;
};

#endif // GLSHADER_H
