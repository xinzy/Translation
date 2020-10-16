#include "translationengine.h"

TranslationEngine::TranslationEngine()
    : mEngine(Engine::Google), mName(""), mIcon("")
{ }

TranslationEngine::TranslationEngine(Engine engine, QString name, QString icon)
    : mEngine(engine), mName(name), mIcon(icon)
{ }

TranslationEngine::TranslationEngine(const TranslationEngine &other)
    : TranslationEngine(other.mEngine, other.mName, other.mIcon)
{
}

bool TranslationEngine::operator==(const TranslationEngine &other) const
{
    return mEngine == other.mEngine && mName == other.mName && mIcon == other.mIcon;
}

bool TranslationEngine::operator!=(const TranslationEngine &other) const
{
    return !(*this == other);
}

QString TranslationEngine::name() const
{
    return mName;
}

void TranslationEngine::setName(QString name)
{
    if (mName == name) return;
    mName = name;
}

QString TranslationEngine::icon() const
{
    return mIcon;
}

void TranslationEngine::setIcon(QString icon)
{
    if (mIcon == icon) return;
    mIcon = icon;
}

Engine TranslationEngine::engine() const
{
    return mEngine;
}

void TranslationEngine::setEngine(Engine engine)
{
    if (mEngine == engine) return;
    mEngine = engine;
}

QDebug operator<<(QDebug debug, const TranslationEngine &engine)
{
    debug.nospace() << "TranslationEngine( engine: " << engine.mEngine
                    << ", name: " << engine.mName
                    << ", icon: " << engine.mIcon
                    << " )";

    return debug;
}
