#ifndef HTTP_H
#define HTTP_H

#include <QNetworkAccessManager>
#include <QObject>

class Http : public QObject
{

public:
    Http(QObject *parent = nullptr);

    void testHttp();

private:
};

#endif // HTTP_H
