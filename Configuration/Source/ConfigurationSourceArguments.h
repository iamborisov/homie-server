#ifndef CONFIGURATIONSOURCEARGUMENTS_H
#define CONFIGURATIONSOURCEARGUMENTS_H

#include "common/fruit.h"

#include "ConfigurationSource.h"
#include "Arguments/Arguments.h"

class ConfigurationSourceArguments : public ConfigurationSource
{
    Q_OBJECT
public:
    INJECT(ConfigurationSourceArguments(Arguments* arguments));

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

private:
    Arguments* arguments;

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

protected:
    virtual void loadOption(ConfigurationOption* option) override;
    virtual void resolveOption(ConfigurationOption* option) override;

//-----------------------------------------------------------------------------
// Service
//-----------------------------------------------------------------------------

protected slots:
    virtual void onAttachContainer() override;
    virtual void onDetachContainer() override;

//-----------------------------------------------------------------------------
};

Component<Required<Arguments>, ConfigurationSource> getConfigurationSourceArgumentsComponent();

#endif // CONFIGURATIONSOURCEARGUMENTS_H
