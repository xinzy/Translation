#ifndef SETTINGITEM_H
#define SETTINGITEM_H

#include <QObject>

class SettingItem
{
    Q_GADGET

    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString icon READ icon CONSTANT)
    Q_PROPERTY(QString url READ url CONSTANT)

public:
    SettingItem();
    SettingItem(QString name, QString icon, QString url);

    const QString name() const;
    const QString icon() const;
    const QString url() const;

signals:

private:
    QString mName;
    QString mIcon;
    QString mUrl;
};

Q_DECLARE_METATYPE(SettingItem)

#endif // SETTINGITEM_H
