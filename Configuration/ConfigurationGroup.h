#ifndef CONFIGURATIONGROUP_H
#define CONFIGURATIONGROUP_H

#include <QObject>
#include <QString>
#include <QList>

#include "ConfigurationOption.h"

class ConfigurationGroup : public QObject
{
    Q_OBJECT
public:
    ConfigurationGroup(const QString &name = QString(),
                                ConfigurationGroup *parent = nullptr);

//-----------------------------------------------------------------------------
// Methods
//  - clear
//  - isEmpty
//  - hasGroups
//  - hasOptions
//-----------------------------------------------------------------------------

public:
    void clear();
    bool isEmpty();
    bool hasGroups();
    bool hasOptions();

//-----------------------------------------------------------------------------
// Fields
//  - name
//  - groups
//  - options
//  - parent
//-----------------------------------------------------------------------------

public:
    QString getName() const;
    void setName(const QString &value);

    QString getPath() const;

    QList<ConfigurationGroup*> getGroups() const;
    void setGroups(const QList<ConfigurationGroup*> &value);
    void addGroup(ConfigurationGroup* group);
    ConfigurationGroup* addGroup(const QString &name);

    QList<ConfigurationOption*> getOptions() const;
    void setOptions(const QList<ConfigurationOption*> &value);
    void addOption(ConfigurationOption* option);
    ConfigurationOption* addOption(const QString &key,
        const QVariant &defaultValue = QVariant(),
        const QString &description = QString(),
        const QString &shortcut = QString()
    );

    ConfigurationGroup *getParent() const;
    void setParent(ConfigurationGroup *value);

private:
    QString name;
    QList<ConfigurationGroup*> groups;
    QList<ConfigurationOption*> options;
    ConfigurationGroup* parent;
};

#endif // CONFIGURATIONGROUP_H
