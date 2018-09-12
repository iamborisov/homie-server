#ifndef CONTAINER_H
#define CONTAINER_H

#include "common/fruit.h"
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
//  - injector
//  - application
//  - arguments
//  - configuration
//-----------------------------------------------------------------------------

public:
    Injector<Container>* getInjector();
    void setInjector(Injector<Container>* injector);

    Application* getApplication();
    Arguments* getArguments();
    Configuration* getConfiguration();

private:
    Injector<Container>* injector;

    Application* application;
    Arguments* arguments;
    Configuration* configuration;

//-----------------------------------------------------------------------------
// Service
//-----------------------------------------------------------------------------

//public:
//    virtual void attach(Service* container) override;
//    virtual void detach() override;

protected slots:
    virtual void onAttachContainer() override;
    virtual void onDetachContainer() override;

//-----------------------------------------------------------------------------
};

#endif //  CONTAINER_H
