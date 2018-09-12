#ifndef CONFIGURATIONRESOLVERPRIORITY_H
#define CONFIGURATIONRESOLVERPRIORITY_H

#include "common/fruit.h"

#include "ConfigurationResolver.h"

class ConfigurationResolverPriority : public ConfigurationResolver
{
    Q_OBJECT
public:
    INJECT(ConfigurationResolverPriority());

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

protected:
    virtual std::vector<ConfigurationSource*> getConfigurationSources() override;
};

Component<ConfigurationResolver> getConfigurationResolverPriorityComponent();

#endif // CONFIGURATIONRESOLVERPRIORITY_H
