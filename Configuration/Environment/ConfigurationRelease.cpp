#include "ConfigurationRelease.h"

ConfigurationRelease::ConfigurationRelease(ConfigurationResolver* resolver):
    Configuration (resolver)
{

}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Required<ConfigurationResolver>, Configuration> getConfigurationReleaseComponent()
{
    return createComponent()
            .bind<Configuration, ConfigurationRelease>();
}
