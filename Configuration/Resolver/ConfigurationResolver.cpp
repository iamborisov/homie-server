#include "ConfigurationResolver.h"
#include "Container/Container.h"
#include "Configuration/ConfigurationOption.h"
#include <QDebug>
ConfigurationResolver::ConfigurationResolver():
    Service()
{

}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

std::vector<ConfigurationSource*> ConfigurationResolver::getConfigurationSources()
{
    qDebug() << "ConfigurationResolver::getConfigurationSources";

    Container* container = static_cast<Container*>(getContainer());

    return container
            ->getInjector()
            ->getMultibindings<ConfigurationSource>();
}

void ConfigurationResolver::load(ConfigurationService* service)
{
    qDebug() << "ConfigurationResolver::load";

   foreach(ConfigurationSource* source, getConfigurationSources()) {
       if (source->getPriority() != prIgnore) {
           source->load(service->getConfigurationGroup());
       }
   }
}

void ConfigurationResolver::resolve(ConfigurationService* service)
{
    qDebug() << "ConfigurationResolver::resolve";

    foreach(ConfigurationSource* source, getConfigurationSources()) {
        if (source->getPriority() != prIgnore) {
             source->resolve(service->getConfigurationGroup());
        }
    }
}
