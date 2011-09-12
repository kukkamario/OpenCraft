#include "errorhandler.h"
#include <QDebug>

ErrorHandler::ErrorHandler()
{
}

ErrorHandler *ErrorHandler::instance()
{
    static ErrorHandler mHandler;
    return &mHandler;
}

void ErrorHandler::raiseError(const QString &msg)
{
    mLastError = msg;
    qCritical() << msg;
}
