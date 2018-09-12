#ifndef CONFIGURATIONOPTION_H
#define CONFIGURATIONOPTION_H

#include <QObject>
#include <QVariant>
#include <QString>

class ConfigurationOption : public QObject
{
    Q_OBJECT
public:
    ConfigurationOption(
        const QString &group,
        const QString &key,
        const QVariant &defaultValue = QVariant(),
        const QString &description = QString(),
        const QString &shortcut = QString()
    );

    ConfigurationOption(
        const QString &group,
        const QString &key,
        const QString &description = QString()
    );

//-----------------------------------------------------------------------------
// Fields
//  - group
//  - key
//  - defaultValue
//  - description
//  - shortcut
//  - value
//-----------------------------------------------------------------------------

public:

    QString getGroup() const;
    void setGroup(const QString &value);

    QString getKey() const;
    void setKey(const QString &value);

    QString getPath() const;

    QVariant getDefaultValue() const;
    void setDefaultValue(const QVariant &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString getShortcut() const;
    void setShortcut(const QString &value);
    bool hasShortcut();

    bool getIsArgument() const;
    void setIsArgument(bool value);

    QVariant getValue() const;
    void setValue(const QVariant &value);

private:
    QString group;
    QString key;
    QVariant defaultValue;
    QString description;
    QString shortcut;
    bool isArgument;
    QVariant value;

};

#endif // CONFIGURATIONOPTION_H
