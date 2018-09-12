#include "ConfigurationSource.h"

ConfigurationSource::ConfigurationSource() :
    Service(),
    priority(prIgnore)
{

}

ConfigurationSourcePriority ConfigurationSource::getPriority() const
{
    return priority;
}

void ConfigurationSource::load(ConfigurationGroup* group)
{
    loadGroup(group);
}

void ConfigurationSource::loadGroup(ConfigurationGroup* group)
{
    if (group->hasOptions()) {
        foreach(ConfigurationOption* option, group->getOptions()) {
            loadOption(option);
        }
    }

    if (group->hasGroups()) {
        foreach(ConfigurationGroup* childGroup, group->getGroups()) {
            loadGroup(childGroup);
        }
    }
}

void ConfigurationSource::resolve(ConfigurationGroup* group)
{
    resolveGroup(group);
}

void ConfigurationSource::resolveGroup(ConfigurationGroup *group)
{
    if (group->hasOptions()) {
        foreach(ConfigurationOption* option, group->getOptions()) {
            resolveOption(option);
        }
    }

    if (group->hasGroups()) {
        foreach(ConfigurationGroup* childGroup, group->getGroups()) {
            resolveGroup(childGroup);
        }
    }
}
