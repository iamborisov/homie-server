#include "ConfigurationService.h"
#include <QDebug>

ConfigurationService::ConfigurationService(const QString &name)
{
    configurationGroup = createConfiguration(new ConfigurationGroup(name));
}

ConfigurationService::~ConfigurationService()
{
    delete configurationGroup;
}

ConfigurationGroup* ConfigurationService::getConfigurationGroup()
{
    return configurationGroup;
}

ConfigurationGroup *ConfigurationService::createConfiguration(ConfigurationGroup *root)
{
    qDebug() << "ConfigurationService::createConfiguration";
    return root;
}

