#ifndef CONFIGURATIONSOURCEFILE_H
#define CONFIGURATIONSOURCEFILE_H

#include <QSettings>

#include "common/fruit.h"

#include "ConfigurationSource.h"

class ConfigurationSourceFile : public ConfigurationSource
{
    Q_OBJECT
public:
    INJECT(ConfigurationSourceFile());
    ~ConfigurationSourceFile() override;

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

private:
    QSettings* settings;

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

public:
    virtual void load(ConfigurationGroup* group) override;

protected:
    virtual void loadGroup(ConfigurationGroup* group) override;
    virtual void loadOption(ConfigurationOption* option) override;
    virtual void resolveOption(ConfigurationOption* option) override;

};

Component<ConfigurationSource> getConfigurationSourceFileComponent();

#endif // CONFIGURATIONSOURCEFILE_H
