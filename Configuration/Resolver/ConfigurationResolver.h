#ifndef CONFIGURATIONRESOLVER_H
#define CONFIGURATIONRESOLVER_H

#include <QString>
#include <QVariant>
#include <vector>

#include "common/Service.h"

#include "Configuration/ConfigurationService.h"
#include "Configuration/Source/ConfigurationSource.h"

class ConfigurationResolver : public Service
{
    Q_OBJECT
public:
    ConfigurationResolver();

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

public:
    virtual void load(ConfigurationService* service);
    virtual void resolve(ConfigurationService* service);

protected:
    virtual std::vector<ConfigurationSource*> getConfigurationSources();
};

#endif // CONFIGURATIONRESOLVER_H
