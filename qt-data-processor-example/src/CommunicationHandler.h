#ifndef COMMUNICATION_HANDLER_H
#define COMMUNICATION_HANDLER_H

#include <QtCore>
#include "util\JsonUtil.h"

class CommunicationHandler :  public QThread {

    Q_OBJECT

private:
    static const int MAX_LINE_LEN = 8192;

    bool configurationReceived;

    QSharedPointer<QTextStream> input;
    QSharedPointer<QTextStream> output;

    void transmitMessage(QString message);

public:
    explicit CommunicationHandler(QSharedPointer<QTextStream> pInput, QSharedPointer<QTextStream> pOutput, QObject* _parent = 0);

protected:
    virtual void run();

public slots:
    void sendMessage(QVariantMap map);

signals:
    void configurationMessageReceived(QVariantMap configurationMessage);
    void eventMessageReceived(QVariantMap event);


};

#endif
