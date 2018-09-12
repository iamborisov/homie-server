#include "ConfigurationDebug.h"

ConfigurationDebug::ConfigurationDebug(ConfigurationResolver* resolver):
    Configuration (resolver)
{

}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Required<ConfigurationResolver>, Configuration> getConfigurationDebugComponent()
{
    return createComponent()
            .bind<Configuration, ConfigurationDebug>();
}
