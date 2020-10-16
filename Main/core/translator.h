#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include "langprovider.h"
#include "language.h"
#include "translationengine.h"
#include "config.h"

#include <utils/utils.h>
#include <baidu/baidulangprovider.h>
#include <google/googlelangprovider.h>
#include <youdao/youdaolangprovider.h>

#include <QObject>
#include <QSettings>


class Translator : public QObject
{
    Q_OBJECT
public:
    explicit Translator(QObject *parent = nullptr);

    void translate(QString input);

    QString autoLangCode() const;

    QList<Language*>* supportedLangs() const;
    QList<Language*> commonSourceLanguage() const;
    QList<Language*> commonTargetLanguage() const;

    void setSourceLangCode(QString code);
    void setTargetLangCode(QString code);

    QString sourceLangCode() const;
    QString targetLangCode() const;

    QList<TranslationEngine>& availableEngine();
    Engine selectedEngine();

    void changeEngine(TranslationEngine &engine);

signals:
    void onTranslationResult(QString result);

private:
    void initConfig();
    void setupProvider();

private:
    LangProvider *mLangProvider;
    TranslationEngine mCurrentEngine;

    QString mSourceLangCode = "auto";
    QString mTargetLangCode = "en";
};

#endif // TRANSLATOR_H
