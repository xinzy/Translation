#ifndef LANGUAGE_H
#define LANGUAGE_H

#include <QDebug>
#include <QObject>

class Language
{
    Q_GADGET

    Q_PROPERTY(QString text MEMBER text)
    Q_PROPERTY(QString code MEMBER code)

public:
    Q_INVOKABLE Language();
    Language(QString t, QString c);

public:
    QString text;
    QString code;
};

Q_DECLARE_METATYPE(Language)

QDebug operator<<(QDebug debug, const Language& lang);

#endif // LANGUAGE_H
