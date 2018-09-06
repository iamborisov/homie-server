#ifndef HOMIE_CONFIGURATION_INTERFACE_H
#define HOMIE_CONFIGURATION_INTERFACE_H

#include <QObject>
#include <fruit/fruit.h>

using fruit::Component;

class Configuration : public QObject
{
    Q_OBJECT
public:
    Configuration();

signals:

public slots:
};

#endif // HOMIE_CONFIGURATION_INTERFACE_H
