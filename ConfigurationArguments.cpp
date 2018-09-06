#include "ConfigurationArguments.h"

ConfigurationArguments::ConfigurationArguments(): Configuration ()
{

}

Component<Configuration> getConfigurationArgumentsComponent() {
    return fruit::createComponent()
            .bind<Configuration, ConfigurationArguments>();
}
