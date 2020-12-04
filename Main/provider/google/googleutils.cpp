#include "googleutils.h"

GoogleUtils::GoogleUtils()
{
}

QString GoogleUtils::makeToken(QString input)
{
    QFile jsFile(":/js/Google.js");
    if (!jsFile.open(QFile::ReadOnly)) {
        qDebug() << "open file fail";
        return "";
    }

    QTextStream stream(&jsFile);
    QString content = stream.readAll();
    jsFile.close();

    QScriptEngine engine;
    QScriptValue js = engine.evaluate(content);
    QScriptValue func = engine.globalObject().property("token");

    QScriptValueList args;
    args << input;
    QString result = func.call(QScriptValue(), args).toString();
    qDebug() << "js result: " << result;

    return result;
}
