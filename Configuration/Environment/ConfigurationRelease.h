#ifndef CONFIGURATIONRELEASE_H
#define CONFIGURATIONRELEASE_H

#include "common/fruit.h"

#include "Configuration/Configuration.h"

class ConfigurationRelease : public Configuration
{
    Q_OBJECT
public:
    INJECT(ConfigurationRelease(ConfigurationResolver* resolver));
};

Component<Required<ConfigurationResolver>, Configuration> getConfigurationReleaseComponent();

#endif // CONFIGURATIONRELEASE_H
