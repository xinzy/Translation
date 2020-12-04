#ifndef PROXY_H
#define PROXY_H

#include <QObject>

struct Proxy
{
    Q_GADGET

    Q_PROPERTY(QString url MEMBER url)
    Q_PROPERTY(QString port MEMBER port)
    Q_PROPERTY(QString username MEMBER username)
    Q_PROPERTY(QString password MEMBER password)

public:
    QString url = "";
    QString port = "";
    QString username = "";
    QString password = "";
};

Q_DECLARE_METATYPE(Proxy)

#endif // PROXY_H
