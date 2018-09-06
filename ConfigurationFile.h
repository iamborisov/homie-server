#ifndef HOMIE_CONFIGURATION_FILE_H
#define HOMIE_CONFIGURATION_FILE_H

#include "Configuration.h"

class ConfigurationFile : public Configuration
{
public:
    INJECT(ConfigurationFile());
};

Component<Configuration> getConfigurationFileComponent();

#endif // HOMIE_CONFIGURATION_FILE_H
