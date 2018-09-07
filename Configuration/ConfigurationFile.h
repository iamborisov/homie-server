#ifndef CONFIGURATIONFILE_H
#define CONFIGURATIONFILE_H

#include <QSettings>
#include "fruit.h"
#include "Configuration.h"

class ConfigurationFile : public Configuration
{
public:
    INJECT(ConfigurationFile());

private:
    QSettings* settings;
};

Component<Configuration> getConfigurationFileComponent();

#endif // CONFIGURATIONFILE_H
