#include "ConfigurationGroup.h"

ConfigurationGroup::ConfigurationGroup(const QString &name, ConfigurationGroup *parent) :
    QObject(nullptr),
    name(name),
    groups(),
    options(),
    parent(parent)
{

}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void ConfigurationGroup::clear()
{
    name.clear();
    groups.clear();
    options.clear();
    parent = nullptr;
}

bool ConfigurationGroup::isEmpty()
{
    return !hasGroups() && !hasOptions();
}

bool ConfigurationGroup::hasGroups()
{
    return groups.count() > 0;
}

bool ConfigurationGroup::hasOptions()
{
    return options.count() > 0;
}

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

QString ConfigurationGroup::getName() const
{
    return name;
}

void ConfigurationGroup::setName(const QString &value)
{
    name = value;
}

QString ConfigurationGroup::getPath() const
{
    QString path;

    if (parent != nullptr) {
        path.append(parent->getPath());
        path.append(".");
    }

    path.append(name);

    return path;
}

QList<ConfigurationGroup*> ConfigurationGroup::getGroups() const
{
    return groups;
}

void ConfigurationGroup::setGroups(const QList<ConfigurationGroup*> &value)
{
    groups = value;
}

void ConfigurationGroup::addGroup(ConfigurationGroup* group)
{
    group->setParent(this);

    groups.append(group);
}

ConfigurationGroup* ConfigurationGroup::addGroup(const QString &name)
{
    ConfigurationGroup* group = new ConfigurationGroup(name, this);

    groups.append(group);

    return group;
}

QList<ConfigurationOption*> ConfigurationGroup::getOptions() const
{
    return options;
}

void ConfigurationGroup::setOptions(const QList<ConfigurationOption*> &value)
{
    options = value;
}

void ConfigurationGroup::addOption(ConfigurationOption* option)
{
    option->setGroup(getPath());

    options.append(option);
}

ConfigurationOption* ConfigurationGroup::addOption(const QString &key, const QVariant &defaultValue, const QString &description, const QString &shortcut)
{
    ConfigurationOption* option = new ConfigurationOption(getPath(), key, defaultValue, description, shortcut);

    options.append(option);

    return option;
}

ConfigurationGroup* ConfigurationGroup::getParent() const
{
    return parent;
}

void ConfigurationGroup::setParent(ConfigurationGroup *value)
{
    parent = value;
}
