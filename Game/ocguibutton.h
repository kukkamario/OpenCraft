#ifndef OCGUIBUTTON_H
#define OCGUIBUTTON_H

#include <QPixmap>
#include <QRect>

#include "ocguiobject.h"
#include "screenstate.h"

class OCGuiButton: public OCGuiObject {
    QPixmap mImage;
public:
    OCGuiButton(QPixmap img, QRect rect);

};

#endif // OCGUIBUTTON_H
