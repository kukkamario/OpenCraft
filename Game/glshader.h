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
    enum Type
    {
        VertexShader,
        FragmentShader
    };

    bool load(const QString &path,Type t);
    bool load(const QStringList &shader,Type t);
    bool compile();
    bool isNull()const{return mShaderPtr == 0;}
    Type type()const{return mType;}
    void setParent(glShaderProgram *parent){mOwnerProgram = parent;}
    GLuint ptr()const{return mShaderPtr;}
private:
    glShaderProgram *mOwnerProgram;
    GLuint mShaderPtr;
    Type mType;
};

#endif // GLSHADER_H
