#ifndef CONTAINER_H
#define CONTAINER_H

#include <QObject>

#include "Application.h"
#include "Arguments.h"
#include "Configuration.h"

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
