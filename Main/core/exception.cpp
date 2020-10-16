#include "exception.h"

Exception::Exception(QString msg) : mMessage(msg)
{ }

QString Exception::message()
{
    return mMessage;
}
