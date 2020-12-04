#include "translationresult.h"
#include "http/httpbasic.h"

REGISTER_JSON_LIST_CONVERTERS(ResultItem)

ResultItem::ResultItem()
{
}

bool ResultItem::operator ==(ResultItem &other)
{
    return dst == other.dst && src == other.src;
}

TranslationResult::TranslationResult()
{
}

bool TranslationResult::operator ==(TranslationResult &other)
{
    return from == other.from && to == other.to && result == other.result;
}

QDebug operator<<(QDebug debug, ResultItem &item)
{
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "ResultItem(" << "src: " << item.src << "; dst: " << item.dst << ")";
    return debug;
}

QDebug operator<<(QDebug debug, TranslationResult &result)
{
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    const int size = result.result.size();
    debug.nospace() << "TranslationResult(" << "from: " << result.from << "; to: " << result.to
                    << "; result: { ";
    for (int i = 0; i < size; i++) {
        ResultItem item = result.result[i];
        if (i > 0) debug.nospace() << "; ";
        debug.nospace() << item;
    }
    debug.nospace() << " })";
    return debug;
}
