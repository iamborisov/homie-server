#include "ConfigurationSourceArguments.h"

#include <QtDebug>

ConfigurationSourceArguments::ConfigurationSourceArguments(Arguments* arguments):
    ConfigurationSource(),
    arguments(arguments)
{
    priority = ConfigurationSourcePriority::prHigh;

    QObject::connect(this, &Service::doAttachContainer, this, &ConfigurationSourceArguments::onAttachContainer);
    QObject::connect(this, &Service::doDetachContainer, this, &ConfigurationSourceArguments::onDetachContainer);
}

void ConfigurationSourceArguments::onAttachContainer()
{
    arguments->attach(getContainer());
}

void ConfigurationSourceArguments::onDetachContainer()
{
    arguments->detach();
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void ConfigurationSourceArguments::loadOption(ConfigurationOption* option)
{
    if (option->getIsArgument()) {
        qDebug() << "Argument " << option->getPath() << " registered";

        arguments->registerArgument(
            option->getPath(),
            option->getDescription(),
            option->getKey()
        );
    } else {
        qDebug() << "Option " << option->getPath() << " registered";

        if (option->hasShortcut()) {
            arguments->registerOption(
                QStringList() << option->getShortcut() << option->getPath(),
                option->getDescription(),
                option->getKey(),
                option->getDefaultValue()
            );
        } else {
            arguments->registerOption(
                option->getPath(),
                option->getDescription(),
                option->getKey(),
                option->getDefaultValue()
            );
        }
    }
}

void ConfigurationSourceArguments::resolveOption(ConfigurationOption *option)
{
    option->setValue(
        arguments->value(
            option->getKey(),
            option->getDefaultValue()
        )
    );
}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Required<Arguments>, ConfigurationSource> getConfigurationSourceArgumentsComponent()
{
    return createComponent()
            .bind<ConfigurationSource, ConfigurationSourceArguments>();
}
