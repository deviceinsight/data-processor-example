#ifndef JSON_UTIL_H
#define JSON_UTIL_H

#include <QVariant>
#include <QString>

class JsonUtil {
public:
    static QVariant parse(QString string);
    static QString  stringify(QVariant v);
};
#endif
