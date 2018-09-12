#include "Container.h"

#include <QDebug>

Container::Container(Application* application,
                     Arguments* arguments,
                     Configuration* configuration):
    Service(),
    //application(application),
    arguments(arguments),
    configuration(configuration)
{
    this->application = application;
}

void Container::onAttachContainer()
{
    qDebug() << "Container::onAttachContainer";

    application->attach(getContainer());
    arguments->attach(getContainer());
    configuration->attach(getContainer());
}

void Container::onDetachContainer()
{
    qDebug() << "Container::onDetachContainer";

    application->detach();
    arguments->detach();
    configuration->detach();
}

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

Application* Container::getApplication()
{
    return application;
}

Arguments* Container::getArguments()
{
    return arguments;
}

Configuration* Container::getConfiguration()
{
    return configuration;
}

Injector<Container>* Container::getInjector()
{
    return injector;
}

void Container::setInjector(Injector<Container>* injector)
{
    this->injector = injector;
}
