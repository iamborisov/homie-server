#ifndef TESTSERVICE_H
#define TESTSERVICE_H

#include "common/Service.h"

#include "Configuration/ConfigurationService.h"

class TestService : public Service, public ConfigurationService
{
    Q_OBJECT
public:
    TestService();

//-----------------------------------------------------------------------------
// ConfigurationService
//-----------------------------------------------------------------------------

protected:
    virtual ConfigurationGroup* createConfiguration(ConfigurationGroup* root) override;

//-----------------------------------------------------------------------------
};

#endif // TESTSERVICE_H
