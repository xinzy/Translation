#ifndef MAINUIVIEWMODEL_H
#define MAINUIVIEWMODEL_H

#include <QObject>
#include <QVariant>

#include <QAction>
#include <QProcess>
#include <QApplication>

#include <core/translator.h>

class MainUiViewModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QVariant> sourceCommonLang READ sourceCommonLang NOTIFY sourceCommonLangChanged)
    Q_PROPERTY(QList<QVariant> targetCommonLang READ targetCommonLang NOTIFY targetCommonLangChanged)

    Q_PROPERTY(int sourceCommonLangIndex READ sourceCommonLangIndex WRITE setSourceCommonLangIndex NOTIFY sourceCommonLangIndexChanged)
    Q_PROPERTY(int targetCommonLangIndex READ targetCommonLangIndex WRITE setTargetCommonLangIndex NOTIFY targetCommonLangIndexChanged)

    Q_PROPERTY(QList<QVariant> sourceSelectLangs READ sourceSelectLangs NOTIFY sourceSelectLangsChanged)
    Q_PROPERTY(QList<QVariant> targetSelectLangs READ targetSelectLangs NOTIFY targetSelectLangsChanged)

    Q_PROPERTY(QList<QVariant> translationEngines READ translationEngines CONSTANT)
    Q_PROPERTY(TranslationEngine currentEngine READ currentEngine NOTIFY currentEngineChanged)

    Q_PROPERTY(QString displayResult READ displayResult WRITE setDisplayResult NOTIFY displayResultChanged)

public:
    explicit MainUiViewModel(QObject *parent = nullptr);

    QList<QVariant> sourceCommonLang() const;
    QList<QVariant> targetCommonLang() const;

    int sourceCommonLangIndex() const;
    Q_INVOKABLE void setSourceCommonLangIndex(int index);

    int targetCommonLangIndex() const;
    Q_INVOKABLE void setTargetCommonLangIndex(int index);

    QList<QVariant> sourceSelectLangs();
    QList<QVariant> targetSelectLangs();

    QList<QVariant> translationEngines();

    TranslationEngine currentEngine() const;
    void setCurrentTranslationEngine(TranslationEngine engine);

    QString displayResult() const;
    void setDisplayResult(QString result);

    Q_INVOKABLE void changeEngine(TranslationEngine engine);
    Q_INVOKABLE void translate(QString input);

    Q_INVOKABLE void startSetting();
signals:
    void sourceCommonLangChanged();
    void targetCommonLangChanged();

    void sourceCommonLangIndexChanged();
    void targetCommonLangIndexChanged();

    void sourceSelectLangsChanged();
    void targetSelectLangsChanged();

    void displayResultChanged();
    void currentEngineChanged();

private:
    void initCommonLangAction();
    void initEngine();

    QList<QVariant> makeLanguageForSelect(QList<QVariant> &list, bool isSource);
    void selectLang(QString text, QString code, bool isSource);

private:
    QList<QVariant> mSourceCommonLanguage;
    QList<QVariant> mTargetCommonLanguage;

    QList<QVariant> mSourceLanguages;
    QList<QVariant> mTargetLanguages;

    int mSourceCommonLangIndex = 0;
    int mTargetCommonLangIndex = 0;

    QString mDisplayResult;

    TranslationEngine mCurrentEngine;
    Translator *mTranslator;
};

#endif // MAINUIVIEWMODEL_H
