#ifndef CONFIGURATIONSERVICE_H
#define CONFIGURATIONSERVICE_H

#include <QString>

#include "ConfigurationGroup.h"

class ConfigurationService
{
public:
    ConfigurationService(const QString &name = QString());
    virtual ~ConfigurationService();

//-----------------------------------------------------------------------------
// Fields
//  - configurationGroup
//-----------------------------------------------------------------------------

public:
    ConfigurationGroup* getConfigurationGroup();

protected:
    ConfigurationGroup* configurationGroup;
    virtual ConfigurationGroup* createConfiguration(ConfigurationGroup* root);
};

#endif // CONFIGURATIONSERVICE_H
