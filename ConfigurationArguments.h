#ifndef HOMIE_CONFIGURATION_ARGUMENTS_H
#define HOMIE_CONFIGURATION_ARGUMENTS_H

#include "Configuration.h"

class ConfigurationArguments : public Configuration
{
public:
    INJECT(ConfigurationArguments());
};

Component<Configuration> getConfigurationArgumentsComponent();

#endif // HOMIE_CONFIGURATION_ARGUMENTS_H
