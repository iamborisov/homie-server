#ifndef CONFIGURATIONDEBUG_H
#define CONFIGURATIONDEBUG_H

#include "common/fruit.h"

#include "Configuration/Configuration.h"

class ConfigurationDebug : public Configuration
{
    Q_OBJECT
public:
    INJECT(ConfigurationDebug(ConfigurationResolver* resolver));
};

Component<Required<ConfigurationResolver>, Configuration> getConfigurationDebugComponent();

#endif // CONFIGURATIONDEBUG_H
