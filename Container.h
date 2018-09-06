#ifndef  HOMIE_CONTAINER_INTERFACE_H
#define  HOMIE_CONTAINER_INTERFACE_H

#include <QObject>
#include <fruit/fruit.h>

using fruit::Component;

class Container : public QObject
{
    Q_OBJECT
public:
    Container();

signals:

public slots:
};

#endif //  HOMIE_CONTAINER_INTERFACE_H
