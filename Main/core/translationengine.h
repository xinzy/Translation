#ifndef TRANSLATIONENGINE_H
#define TRANSLATIONENGINE_H

#include <QDebug>
#include <QObject>

enum Engine
{
    Google,
    Baidu,
    Youdao
};
Q_DECLARE_METATYPE(Engine)

class TranslationEngine
{
    Q_GADGET

    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QString icon READ icon WRITE setIcon)
    Q_PROPERTY(Engine engine READ engine WRITE setEngine)

public:
    TranslationEngine();
    TranslationEngine(Engine engine, QString name, QString icon);

    TranslationEngine(const TranslationEngine &other);

    bool operator==(const TranslationEngine &other) const;
    bool operator!=(const TranslationEngine &other) const;

    QString name() const;
    void setName(QString name);

    QString icon() const;
    void setIcon(QString icon);

    Engine engine() const;
    void setEngine(Engine engine);

public:
    QString mName;
    QString mIcon;
    Engine mEngine;
};
Q_DECLARE_METATYPE(TranslationEngine)

QDebug operator<<(QDebug debug, const TranslationEngine &engine);

#endif // TRANSLATIONENGINE_H
