#ifndef APICONFIG_H
#define APICONFIG_H

#include <QObject>

struct ApiConfig
{
    Q_GADGET

    Q_PROPERTY(QString appId MEMBER appId)
    Q_PROPERTY(QString appSecert MEMBER appSecert)

public:
    QString appId = "";
    QString appSecert = "";
};

Q_DECLARE_METATYPE(ApiConfig)

#endif // APICONFIG_H
