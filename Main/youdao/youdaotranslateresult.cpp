#include "youdaotranslateresult.h"

YoudaoTranslateResult::YoudaoTranslateResult()
{ }

bool YoudaoTranslateResult::operator==(YoudaoTranslateResult &other) const
{
    return errorCode == other.errorCode
            && query == other.errorCode
            && translation == other.translation;
}

bool YoudaoTranslateResult::isSuccess() const
{
    return errorCode == 0;
}

QString YoudaoTranslateResult::result() const
{
    QString result;
    for (int i = 0; i < translation.size(); i++) {
        result.append(translation.at(i));
    }
    return result;
}

QDebug operator<<(QDebug debug, YoudaoTranslateResult result)
{
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)

    debug.nospace() << "YoudaoTranslateResult(" << "errorCode: " << result.errorCode
                    << ", query: " << result.query << ", translation: [";

    for (int i = 0; i < result.translation.size(); i++) {
        if (i > 0) debug.nospace() << ", ";
        debug.nospace() << result.translation.at(i);
    }
    debug.nospace() << "])";

    return debug;
}
