#include "mainuiviewmodel.h"
#include "settingsview.h"

#include <QProcess>
#include <QApplication>
#include <QTimer>

MainUiViewModel::MainUiViewModel(QObject *parent)
    : QObject(parent), mDisplayResult("")
{
    mTranslator = new Translator(this);
    initEngine();
    connect(mTranslator, &Translator::onTranslationResult, this, [this](QString content) {
        setDisplayResult(content);
    });
    initCommonLangAction();
}

QList<QVariant> MainUiViewModel::sourceCommonLang() const
{
    return mSourceCommonLanguage;
}

QList<QVariant> MainUiViewModel::targetCommonLang() const
{
    return mTargetCommonLanguage;
}

int MainUiViewModel::sourceCommonLangIndex() const
{
    return mSourceCommonLangIndex;
}

void MainUiViewModel::setSourceCommonLangIndex(int index)
{
    if (mSourceCommonLangIndex == index) return;
    mSourceCommonLangIndex = index;
    emit sourceCommonLangIndexChanged();
}

int MainUiViewModel::targetCommonLangIndex() const
{
    return mTargetCommonLangIndex;
}

void MainUiViewModel::setTargetCommonLangIndex(int index)
{
    if (mTargetCommonLangIndex == index) return;
    mTargetCommonLangIndex = index;
    emit targetCommonLangIndexChanged();
}

QList<QVariant> MainUiViewModel::sourceSelectLangs()
{
    return makeLanguageForSelect(mSourceLanguages, true);
}

QList<QVariant> MainUiViewModel::targetSelectLangs()
{
    return makeLanguageForSelect(mTargetLanguages, false);
}

QList<QVariant> MainUiViewModel::translationEngines()
{
    QList<QVariant> list;
    auto engines = Config::instance()->availableEngines();
    for (int i = 0; i < engines.size(); i++) {
        auto item = engines.at(i);
        QVariant var = QVariant::fromValue(item);
        list.append(var);
    }

    return list;
}

TranslationEngine MainUiViewModel::currentEngine() const
{
    return mCurrentEngine;
}

void MainUiViewModel::setCurrentTranslationEngine(TranslationEngine engine)
{
    if (mCurrentEngine == engine) return;
    mCurrentEngine = engine;
    emit currentEngineChanged();
}

QString MainUiViewModel::displayResult() const
{
    return mDisplayResult;
}

void MainUiViewModel::setDisplayResult(QString result)
{
    if (mDisplayResult == result) return;
    mDisplayResult = result;
    emit displayResultChanged();
}

void MainUiViewModel::changeEngine(TranslationEngine engine)
{
    if (engine.engine() == mCurrentEngine.engine()) return;
    Config::instance()->changeEngine(engine.engine());

    QTimer::singleShot(100, [](){
        qApp->quit();
        QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    });
}

void MainUiViewModel::translate(QString input)
{
    qDebug() << "start translate: " << input;
    if (input.isEmpty()) {
        setDisplayResult("");
        return;
    }
    mTranslator->translate(input);
}

void MainUiViewModel::startSetting()
{
    SettingsView *settings = new SettingsView;
    settings->setAttribute(Qt::WA_ShowModal);
    settings->show();
}

void MainUiViewModel::initCommonLangAction()
{
    mSourceCommonLanguage.clear();
    auto commonSourceLangs = mTranslator->commonSourceLanguage();
    for (int i = 0; i < commonSourceLangs.size(); i++) {
        Language *lang = commonSourceLangs.at(i);
        QString code = lang->code;
        if (code == "auto") {
            setSourceCommonLangIndex(i);
            mTranslator->setSourceLangCode(code);
        }

        QAction *sourceAction = new QAction(lang->text, this);
        sourceAction->setIconText(code);
        connect(sourceAction, &QAction::triggered, this, [this, sourceAction]() {
            mTranslator->setSourceLangCode(sourceAction->iconText());
        });
        mSourceCommonLanguage.append(QVariant::fromValue(sourceAction));
    }

    mTargetCommonLanguage.clear();
    auto commonTargetLangs = mTranslator->commonTargetLanguage();
    for (int i = 0; i < commonTargetLangs.size(); i++) {
        Language *lang = commonTargetLangs.at(i);
        QString code = lang->code;

        if (code == "en") {
            setTargetCommonLangIndex(i);
            mTranslator->setTargetLangCode(code);
        }

        QAction *targetAction = new QAction(lang->text, this);
        targetAction->setIconText(code);
        connect(targetAction, &QAction::triggered, this, [this, targetAction]() {
            mTranslator->setTargetLangCode(targetAction->iconText());
        });
        mTargetCommonLanguage.append(QVariant::fromValue(targetAction));
    }
}

void MainUiViewModel::initEngine()
{
    setCurrentTranslationEngine(Config::instance()->currentTranslationEngine());
}

QList<QVariant> MainUiViewModel::makeLanguageForSelect(QList<QVariant> &list, bool isSource)
{
    QString autoLangCode = mTranslator->autoLangCode();
    QString selectLangCode = isSource ? mTranslator->sourceLangCode() : mTranslator->targetLangCode();

    if (list.isEmpty())
    {
        QList<Language*>* langs = mTranslator->supportedLangs();
        int size = langs->size();
        for (int i = 0; i < size; i++)
        {
            auto lang = langs->at(i);
            if (!isSource && lang->code == autoLangCode) continue;
            QAction *action = new QAction(lang->text, this);
            action->setIconText(lang->code);
            action->setCheckable(true);
            action->setProperty("isSource", isSource);
            if (lang->code == selectLangCode) action->setChecked(true);
            else action->setChecked(false);
            connect(action, &QAction::triggered, this, [this, action]() {
                bool from = action->property("isSource").toBool();
                qDebug() << "isSource: " << from;
                selectLang(action->text(), action->iconText(), from);
            });

            QVariant var = QVariant::fromValue(action);
            list.append(var);
        }
    } else
    {
        int size = list.size();
        for (int i = 0; i < size; i++)
        {
            QVariant var = list.at(i);
            QAction* action = var.value<QAction*>();
            action->setChecked(selectLangCode == action->iconText());
        }
    }
    return list;
}

void MainUiViewModel::selectLang(QString text, QString code, bool isSource)
{
    if (isSource) {
        mTranslator->setSourceLangCode(code);

        bool has = false;
        for (int i = 0; i < mSourceCommonLanguage.size(); i++) {
            QAction *lang = mSourceCommonLanguage.at(i).value<QAction*>();
            if (lang->iconText() == code) {
                setSourceCommonLangIndex(i);
                has = true;
                break;
            }
        }
        if (!has) {
            if (mSourceCommonLanguage.size() == 4) mSourceCommonLanguage.removeLast();
            QAction *action = new QAction(text, this);
            action->setIconText(code);
            connect(action, &QAction::triggered, this, [this, action]() {
                mTranslator->setSourceLangCode(action->iconText());
            });
            mSourceCommonLanguage.append(QVariant::fromValue(action));
            setSourceCommonLangIndex(3);
            emit sourceCommonLangChanged();
        }
    } else {
        mTranslator->setTargetLangCode(code);

        bool has = false;
        for (int i = 0; i < mTargetCommonLanguage.size(); i++) {
            QAction *lang = mTargetCommonLanguage.at(i).value<QAction*>();
            if (lang->iconText() == code) {
                setTargetCommonLangIndex(i);
                has = true;
                break;
            }
        }
        if (!has) {
            if (mTargetCommonLanguage.size() == 3) mTargetCommonLanguage.removeLast();
            QAction *action = new QAction(text, this);
            action->setIconText(code);
            connect(action, &QAction::triggered, this, [this, action]() {
                mTranslator->setTargetLangCode(action->iconText());
            });
            mTargetCommonLanguage.append(QVariant::fromValue(action));
            setTargetCommonLangIndex(2);
            emit targetCommonLangChanged();
        }
    }
}
