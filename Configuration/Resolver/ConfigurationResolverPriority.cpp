#include "ConfigurationResolverPriority.h"
#include "Container/Container.h"

ConfigurationResolverPriority::ConfigurationResolverPriority():
    ConfigurationResolver()
{

}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

std::vector<ConfigurationSource*> ConfigurationResolverPriority::getConfigurationSources()
{
    std::vector<ConfigurationSource*> result;

    for (int priorityInt = prLow; priorityInt <= prHigh; priorityInt++)
    {
       ConfigurationSourcePriority priority = static_cast<ConfigurationSourcePriority>(priorityInt);

       foreach(ConfigurationSource* source, ConfigurationResolver::getConfigurationSources()) {
           if (source->getPriority() == priority) {
                result.push_back(source);
           }
       }
    }

    return result;
}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<ConfigurationResolver> getConfigurationResolverPriorityComponent()
{
    return createComponent()
            .bind<ConfigurationResolver, ConfigurationResolverPriority>();
}
