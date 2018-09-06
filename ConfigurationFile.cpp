#include "ConfigurationFile.h"

ConfigurationFile::ConfigurationFile():
    Configuration()
{

}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Configuration> getConfigurationFileComponent() {
    return fruit::createComponent()
            .bind<Configuration, ConfigurationFile>();
}
