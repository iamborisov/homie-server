#include "TestService.h"

TestService::TestService():
    Service (),
    ConfigurationService(QString("TestService"))
{
    configurationGroup = createConfiguration(configurationGroup);
}

ConfigurationGroup* TestService::createConfiguration(ConfigurationGroup *root)
{
    root->addOption("test", QVariant(true));

    return root;
}
