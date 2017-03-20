#include "JsonUtil.h"

#include <qjson/serializer.h>
#include <qjson/parser.h>
#include <qjson/qjson_export.h>

QString JsonUtil::stringify(QVariant v) {

    QJson::Serializer serializer;

    bool ok;
    QByteArray json = serializer.serialize(v, &ok);

    if(ok) {
        return QString(json);
    } else {
        return QString();
    }
}


QVariant JsonUtil::parse(QString string) {

    QJson::Parser parser;

    bool ok;

    QByteArray json(string.toStdString().c_str());

    QVariant result = parser.parse(json, &ok);

    if(ok) {
        return result;
    } else {
        return QVariant();
    }
}

