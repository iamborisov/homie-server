#include "Container.h"

Container::Container(Application* application,
                     Arguments* arguments,
                     Configuration* configuration):
    QObject(nullptr),
    application(application),
    arguments(arguments),
    configuration(configuration)
{
}

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
