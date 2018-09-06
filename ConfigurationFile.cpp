#include "ConfigurationFile.h"

ConfigurationFile::ConfigurationFile(): Configuration ()
{

}

Component<Configuration> getConfigurationFileComponent() {
    return fruit::createComponent()
            .bind<Configuration, ConfigurationFile>();
}
