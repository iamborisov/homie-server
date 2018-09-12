#ifndef ARGUMENTSCONSOLE_H
#define ARGUMENTSCONSOLE_H

#include <QCommandLineParser>
#include <QCommandLineOption>

#include "common/fruit.h"

#include "Arguments.h"

class ArgumentsConsole : public Arguments
{
    Q_OBJECT
public:
    INJECT(ArgumentsConsole());

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------
public:
    virtual void registerOption(
            const QString &name,
            const QString &description,
            const QString &valueName = QString(),
            const QVariant &defaultValue = QVariant()) override;

    virtual void registerOption(
            const QStringList &names,
            const QString &description,
            const QString &valueName = QString(),
            const QVariant &defaultValue = QVariant()) override;

    virtual void registerArgument(
            const QString &name,
            const QString &description = QString(),
            const QString &syntax = QString()) override;

    virtual QVariant value(
            const QString &name,
            const QVariant &defaultValue = QVariant()) override;

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

private:
    QCommandLineParser parser;

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

protected slots:
    virtual void onAttachContainer() override;

private slots:
    void onApplicationInit();

//-----------------------------------------------------------------------------
};

Component<Arguments> getArgumentsConsoleComponent();

#endif // ARGUMENTSCONSOLE_H
