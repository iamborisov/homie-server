#ifndef CONFIGURATIONSOURCE_H
#define CONFIGURATIONSOURCE_H

#include "common/Service.h"
#include "Configuration/ConfigurationGroup.h"
#include "Configuration/ConfigurationOption.h"

enum ConfigurationSourcePriority {
    prIgnore,
    prLow,
    prNormal,
    prHigh
};

class ConfigurationSource : public Service
{
    Q_OBJECT
public:

    ConfigurationSource();

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

public:
    virtual void load(ConfigurationGroup* group);
    virtual void resolve(ConfigurationGroup* group);

protected:
    virtual void loadGroup(ConfigurationGroup* group);
    virtual void loadOption(ConfigurationOption* option) = 0;

    virtual void resolveGroup(ConfigurationGroup* group);
    virtual void resolveOption(ConfigurationOption* option) = 0;

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------
public:
    ConfigurationSourcePriority getPriority() const;

protected:
    ConfigurationSourcePriority priority;

};

#endif // CONFIGURATIONSOURCE_H
