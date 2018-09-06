#ifndef CONTAINER_H
#define CONTAINER_H

#include <QObject>
#include <fruit/fruit.h>

using fruit::Component;

class Container : public QObject
{
    Q_OBJECT
public:
    INJECT(Container());

signals:

public slots:
};

Component<Container> getContainerComponent();

#endif // CONTAINER_H
