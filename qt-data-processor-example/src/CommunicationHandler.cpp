
#include "CommunicationHandler.h"


CommunicationHandler::CommunicationHandler(QSharedPointer<QTextStream> pInput, QSharedPointer<QTextStream> pOutput, QObject* _parent):
    input(pInput),
    output(pOutput),
    configurationReceived(false),
    QThread(_parent) {
}


void CommunicationHandler::run() {
    while(!input->atEnd()) {
        QString line = input->readLine(MAX_LINE_LEN);

        QVariantMap map = JsonUtil::parse(line).toMap();

        if(map.empty()) {
            qDebug() << "Could not parse JSON string:" << line;
        } else {

            if(!configurationReceived) {
                emit configurationMessageReceived(map);
                configurationReceived = true;
            } else if(map.contains("event")) {
                qDebug() << "event Received";
                emit eventMessageReceived(map);
            } else {
                qDebug() << "Objecthandling not defined - returning";
                QString transmitString = JsonUtil::stringify(map);
                transmitMessage(transmitString);
            }
        }



        if(input->status() != QTextStream::Ok) {
            qDebug() << "Status of input stream not ok. Status was:" << input->status();
            QCoreApplication::exit(1);
        }
    }

    qDebug() << "Input-stream ended unexpected.";
    QCoreApplication::exit(1);
}

void CommunicationHandler::transmitMessage(QString message) {
    message.append("\n");
    *output << message;
    output->flush();
}


void CommunicationHandler::sendMessage(QVariantMap map) {
    QString transmitString = JsonUtil::stringify(map);
    transmitMessage(transmitString);
}