#ifndef LANGPROVIDER_H
#define LANGPROVIDER_H

#include "language.h"

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include <QObject>
#include <QFile>

class LangProvider : public QObject
{
    Q_OBJECT

public:
    LangProvider(QObject *parent = nullptr);
    ~LangProvider();

    virtual QList<Language*>* supportedLangs() const;

    virtual QList<Language*> commonSourceLangs() const;

    virtual QList<Language*> commonTargetLangs() const;

    virtual QString autoLangCode() const;

    virtual void translate(QString input, QString sourceCode, QString targetCode) = 0;

protected:
    void initLangs(QString path);

protected:
    QList<Language*> *mSupportedLangs;

signals:
    void onTranslationResult(QString result);

};

#endif // LANGPROVIDER_H
