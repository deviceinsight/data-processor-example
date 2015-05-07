#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QtCore>

class Configuration : public QObject  {

    Q_OBJECT

private:
    QStringList ignoredEvents;

public:
    Configuration() {
    }

    QStringList getIgnoredEvents() const {
        return ignoredEvents;
    }

public slots:
    void updateConfiguration(QVariantMap map);

};

#endif
