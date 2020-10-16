#include "langprovider.h"

LangProvider::LangProvider(QObject *parent)
    : QObject(parent), mSupportedLangs(new QList<Language*>)
{ }

LangProvider::~LangProvider()
{
    if (mSupportedLangs) {
        delete mSupportedLangs;
        mSupportedLangs = nullptr;
    }
}

QList<Language *> *LangProvider::supportedLangs() const
{
    return mSupportedLangs;
}

QList<Language*> LangProvider::commonSourceLangs() const
{
    return mSupportedLangs->mid(0, 3);
}

QList<Language *> LangProvider::commonTargetLangs() const
{
    return mSupportedLangs->mid(1, 2);
}

QString LangProvider::autoLangCode() const
{
    return "auto";
}

void LangProvider::initLangs(QString path)
{
    QFile file(path);
    file.open(QFile::ReadOnly);
    QString content = file.readAll();

    QJsonDocument document = QJsonDocument::fromJson(content.toUtf8());
    QJsonArray array = document.array();
    for (int i = 0; i < array.size(); i++) {
        QJsonValue value = array[i];
        QJsonObject object = value.toObject();

        Language *lang = new Language;
        lang->text = object.value("text").toString();
        lang->code = object.value("code").toString();
        mSupportedLangs->append(lang);
    }
}
