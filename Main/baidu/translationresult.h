#ifndef TRANSLATIONRESULT_H
#define TRANSLATIONRESULT_H

#include <QObject>
#include <QDebug>

class ResultItem {
    Q_GADGET

    Q_PROPERTY(QString src MEMBER src)
    Q_PROPERTY(QString dst MEMBER dst)

public:
    Q_INVOKABLE ResultItem();

    bool operator ==(ResultItem &other);

public:
    QString src;
    QString dst;
};

Q_DECLARE_METATYPE(ResultItem)

class TranslationResult
{
    Q_GADGET

    Q_PROPERTY(QString from MEMBER from)
    Q_PROPERTY(QString to MEMBER to)
    Q_PROPERTY(QList<ResultItem> trans_result MEMBER result)

public:
    Q_INVOKABLE TranslationResult();
    bool operator ==(TranslationResult &other);

public:
    QString from;
    QString to;

    QList<ResultItem> result;
};

Q_DECLARE_METATYPE(TranslationResult)

QDebug operator<<(QDebug debug, ResultItem &item);
QDebug operator<<(QDebug debug, TranslationResult &item);

#endif // TRANSLATIONRESULT_H
