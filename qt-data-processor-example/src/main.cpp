#include <QtCore>
#include <QDebug>
#include "Configuration.h"
#include "CommunicationHandler.h"
#include "EventProcessor.h"


int main(int argc, char* argv[]) {

    /* Qt-Core Application */
    QCoreApplication app(argc, argv);

    /* safe pointers to stdin and stdout */
    QSharedPointer<QTextStream> streamStdoutPtr = QSharedPointer<QTextStream>(new QTextStream(stdout));
    QSharedPointer<QTextStream> streamStdinPtr = QSharedPointer<QTextStream>(new QTextStream(stdin));


    /* Setup CommunicationHandler */
    CommunicationHandler *commHdl = new CommunicationHandler(streamStdinPtr, streamStdoutPtr, &app);

    //* Create Configuration-Object */
    Configuration *configurationPtr = new Configuration();
    QSharedPointer<Configuration> configuration(configurationPtr);

    EventProcessor *eventProcessorPtr = new EventProcessor(configuration);
    QSharedPointer<EventProcessor> eventProcessor(eventProcessorPtr);


    /* Signals and slots */
    app.connect(commHdl, SIGNAL(configurationMessageReceived(QVariantMap)), configuration.data(), SLOT(updateConfiguration(QVariantMap)));

    app.connect(commHdl, SIGNAL(eventMessageReceived(QVariantMap)), eventProcessor.data(), SLOT(eventMessageReceived(QVariantMap)));
    app.connect(eventProcessor.data(), SIGNAL(sendEventMessage(QVariantMap)), commHdl, SLOT(sendMessage(QVariantMap)));




    /* Start communication handler */
    commHdl->start();

    /* Execute Application */
    app.exec();
}


