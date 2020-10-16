#include "language.h"

Language::Language() {}

Language::Language(QString t, QString c) : text(t), code(c)
{ }

QDebug operator<<(QDebug debug, const Language& lang)
{
    QDebugStateSaver saver(debug);
    Q_UNUSED(saver)
    debug.nospace() << "Language(" << "text: " << lang.text << "; code: " << lang.code << ")";
    return debug;
}

