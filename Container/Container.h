#ifndef CONTAINER_H
#define CONTAINER_H

#include <QObject>

#include "Application/Application.h"
#include "Arguments/Arguments.h"
#include "Configuration/Configuration.h"

class Container : public QObject
{
    Q_OBJECT

public:
    Container(Application* application,
              Arguments* arguments,
              Configuration* configuration);

    Application* getApplication();
    Arguments* getArguments();
    Configuration* getConfiguration();

private:
    Application* application;
    Arguments* arguments;
    Configuration* configuration;
};

#endif //  CONTAINER_H
