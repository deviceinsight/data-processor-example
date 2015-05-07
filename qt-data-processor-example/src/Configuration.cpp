#include "Configuration.h"

void Configuration::updateConfiguration(QVariantMap map)  {

    if(map.contains("ignoredEvents") && map["ignoredEvents"].canConvert<QStringList>()) {
        ignoredEvents = map["ignoredEvents"].toStringList();
    }

    qDebug() << "Ignored events are: " << ignoredEvents.join(", ");
}
