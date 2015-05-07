
#include "EventProcessor.h"


EventProcessor::EventProcessor(QSharedPointer<Configuration> pConfiguration, QObject* _parent):
    configuration(pConfiguration),
    QObject(_parent) {
}


void EventProcessor::eventMessageReceived(QVariantMap event) {

    QString eventKey = event["event"].toMap()["eventKey"].toString();

    if(!configuration->getIgnoredEvents().contains(eventKey)) {
        emit sendEventMessage(event);
    } else {
        qDebug() << "Ignoring event with key" << eventKey;
    }

}