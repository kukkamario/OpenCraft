#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H
#include <QString>

class ErrorHandler
{
public:
    static ErrorHandler *instance();
    void raiseError(const QString &msg);
    QString lastError()const{return mLastError;}
private:
    ErrorHandler();
    QString mLastError;
};

#endif // ERRORHANDLER_H
