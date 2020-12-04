#ifndef HTTPBASIC_H
#define HTTPBASIC_H

#include <QtJsonSerializer/QtJsonSerializer>
#include <QDebug>

using namespace QtJsonSerializer;

template <class T>
struct HttpJsonRegister
{
    HttpJsonRegister() {
        qDebug() << "register converters";
        JsonSerializer::registerListConverters<T>();
    }
};


#define REGISTER_JSON_LIST_CONVERTERS(Type) \
    static const HttpJsonRegister<Type> static_const_json_register_##Type;
#endif // HTTPBASIC_H
