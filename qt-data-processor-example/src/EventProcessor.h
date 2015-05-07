#ifndef EVENT_PROCESSOR_H
#define EVENT_PROCESSOR_H

#include <QtCore>

#include "Configuration.h"

class EventProcessor :  public QObject {

    Q_OBJECT

public:
    explicit EventProcessor(QSharedPointer<Configuration> pConfiguration, QObject* _parent = 0);

private:
    QSharedPointer<Configuration> configuration;

public slots:
    void eventMessageReceived(QVariantMap event);

signals:
    void sendEventMessage(QVariantMap map);

};

#endif
