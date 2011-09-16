#ifndef OCGUIOBJECT_H
#define OCGUIOBJECT_H

#include <QRect>

class OCGuiObject{

    public:
    virtual void paint() = 0;
    QRect rect()const{return mRect;}

    protected:
    QRect mRect;

};

#endif // OCGUIOBJECT_H
