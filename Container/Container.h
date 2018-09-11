#ifndef CONTAINER_H
#define CONTAINER_H

#include "common/Service.h"

#include "Application/Application.h"
#include "Arguments/Arguments.h"
#include "Configuration/Configuration.h"

class Container : public Service
{
    Q_OBJECT
public:
    Container(Application* application,
              Arguments* arguments,
              Configuration* configuration);

//-----------------------------------------------------------------------------
// Fields
//  - application
//  - arguments
//  - configuration
//-----------------------------------------------------------------------------

public:
    Application* getApplication();
    Arguments* getArguments();
    Configuration* getConfiguration();

private:
    Application* application;
    Arguments* arguments;
    Configuration* configuration;

//-----------------------------------------------------------------------------
};

#endif //  CONTAINER_H
