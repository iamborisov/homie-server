#include "Container.h"

Container::Container(Application* application,
                     Arguments* arguments,
                     Configuration* configuration):
    Service(),
    application(application),
    arguments(arguments),
    configuration(configuration)
{
    application->attach(this);
    arguments->attach(this);
    configuration->attach(this);
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
