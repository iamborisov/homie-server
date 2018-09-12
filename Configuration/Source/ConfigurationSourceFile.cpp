#include "ConfigurationSourceFile.h"

ConfigurationSourceFile::ConfigurationSourceFile():
    ConfigurationSource()
{
    priority = ConfigurationSourcePriority::prNormal;
}

ConfigurationSourceFile::~ConfigurationSourceFile()
{
    if (settings != nullptr) {
        delete settings;
    }
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void ConfigurationSourceFile::load(ConfigurationGroup* group)
{
    if (settings != nullptr) {
        delete settings;
    }

    settings = new QSettings(group->getName() + ".ini", QSettings::IniFormat);

    loadGroup(group);
}

void ConfigurationSourceFile::loadGroup(ConfigurationGroup* group)
{
    settings->beginGroup(group->getName());
    ConfigurationSource::loadGroup(group);
    settings->endGroup();
}

void ConfigurationSourceFile::loadOption(ConfigurationOption* option)
{
    if (!settings->contains(option->getKey())) {
        settings->setValue(option->getKey(), option->getDefaultValue());
    }
}

void ConfigurationSourceFile::resolveOption(ConfigurationOption *option)
{
    option->setValue(
        settings->value(
            option->getKey(),
            option->getDefaultValue()
        )
    );
}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<ConfigurationSource> getConfigurationSourceFileComponent() {
    return createComponent()
            .bind<ConfigurationSource, ConfigurationSourceFile>();
}
