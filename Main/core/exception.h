#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <QString>



class Exception
{
public:
    explicit Exception(QString msg);

    QString message();

private:
    QString mMessage;
};

#endif // EXCEPTION_H
