#ifndef CONFIGURATIONFILE_H
#define CONFIGURATIONFILE_H

#include <QSettings>

#include "common/fruit.h"

#include "Configuration.h"

class ConfigurationFile : public Configuration
{
    Q_OBJECT
public:
    INJECT(ConfigurationFile());

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

private:
    QSettings* settings;

//-----------------------------------------------------------------------------
};

Component<Configuration> getConfigurationFileComponent();

#endif // CONFIGURATIONFILE_H
