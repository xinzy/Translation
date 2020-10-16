#include "settingitem.h"

SettingItem::SettingItem()
    : SettingItem("", "", "")
{ }

SettingItem::SettingItem(QString name, QString icon, QString url)
    : mName(name), mIcon(icon), mUrl(url)
{ }

const QString SettingItem::name() const
{
    return mName;
}

const QString SettingItem::icon() const
{
    return mIcon;
}

const QString SettingItem::url() const
{
    return mUrl;
}
