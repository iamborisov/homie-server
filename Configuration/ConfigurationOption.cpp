#include "ConfigurationOption.h"

ConfigurationOption::ConfigurationOption(const QString &group,
                                         const QString &key,
                                         const QVariant &defaultValue,
                                         const QString &description,
                                         const QString &shortcut) :
    QObject(nullptr),
    group(group),
    key(key),
    defaultValue(defaultValue),
    description(description),
    shortcut(shortcut),
    isArgument(false)
{

}

ConfigurationOption::ConfigurationOption(
        const QString &group,
        const QString &key,
        const QString &description) :
    QObject(nullptr),
    group(group),
    key(key),
    defaultValue(),
    description(description),
    shortcut(),
    isArgument(true)
{

}


//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

QString ConfigurationOption::getGroup() const
{
    return group;
}

void ConfigurationOption::setGroup(const QString &value)
{
    group = value;
}

QString ConfigurationOption::getKey() const
{
    return key;
}

void ConfigurationOption::setKey(const QString &value)
{
    key = value;
}

QString ConfigurationOption::getPath() const
{
    QString path;

    if (!group.isEmpty()) {
        path.append(group);
        path.append(".");
    }

    path.append(key);

    return path;
}

QVariant ConfigurationOption::getDefaultValue() const
{
    return defaultValue;
}

void ConfigurationOption::setDefaultValue(const QVariant &value)
{
    defaultValue = value;
}

QString ConfigurationOption::getDescription() const
{
    return description;
}

void ConfigurationOption::setDescription(const QString &value)
{
    description = value;
}

QString ConfigurationOption::getShortcut() const
{
    return shortcut;
}

void ConfigurationOption::setShortcut(const QString &value)
{
    shortcut = value;
}

bool ConfigurationOption::hasShortcut()
{
    return !shortcut.isEmpty();
}

bool ConfigurationOption::getIsArgument() const
{
    return isArgument;
}

void ConfigurationOption::setIsArgument(bool value)
{
    isArgument = value;
}

QVariant ConfigurationOption::getValue() const
{
    return value.isNull() ? defaultValue : value;
}

void ConfigurationOption::setValue(const QVariant &value)
{
    this->value = value;
}
