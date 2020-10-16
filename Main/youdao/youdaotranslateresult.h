#ifndef YOUDAOTRANSLATERESULT_H
#define YOUDAOTRANSLATERESULT_H

#include <QObject>
#include <QDebug>

class YoudaoTranslateResult
{
    Q_GADGET

    Q_PROPERTY(int errorCode MEMBER errorCode)
    Q_PROPERTY(QString query MEMBER query)
    Q_PROPERTY(QString requestId MEMBER requestId)
    Q_PROPERTY(QStringList translation MEMBER translation)

public:
    YoudaoTranslateResult();
    bool operator ==(YoudaoTranslateResult &other) const;
    bool isSuccess() const;
    QString result() const;

public:
    int errorCode;
    QString query;
    QString requestId;
    QStringList translation;
};

Q_DECLARE_METATYPE(YoudaoTranslateResult)

QDebug operator<<(QDebug debug, YoudaoTranslateResult result);

#endif // YOUDAOTRANSLATERESULT_H
