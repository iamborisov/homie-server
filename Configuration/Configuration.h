#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QVariant>
#include <QString>
#include <vector>

#include "common/Service.h"

#include "Configuration/ConfigurationService.h"
#include "Configuration/Resolver/ConfigurationResolver.h"

class Configuration : public Service
{
    Q_OBJECT
public:
    Configuration(ConfigurationResolver* resolver);

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

private:
    ConfigurationResolver* resolver;

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

protected:
    std::vector<ConfigurationService*> getConfigurableServices();

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

public slots:
    virtual void onApplicationBeforeInit();
    virtual void onApplicationAfterInit();

//-----------------------------------------------------------------------------
// Service
//-----------------------------------------------------------------------------

protected slots:
    virtual void onAttachContainer() override;
    virtual void onDetachContainer() override;

//-----------------------------------------------------------------------------

};

#endif // CONFIGURATION_H
