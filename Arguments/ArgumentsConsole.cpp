#include "ArgumentsConsole.h"

#include "Container/Container.h"
#include "Application/Application.h"

#include <QDebug>

ArgumentsConsole::ArgumentsConsole():
    Arguments(),
    parser()
{
    parser.setApplicationDescription("SmartHome server, 2018");
    parser.addVersionOption();
    parser.addHelpOption();
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void ArgumentsConsole::registerOption(
        const QString &name,
        const QString &description,
        const QString &valueName,
        const QVariant &defaultValue)
{
    QCommandLineOption option(
                name,
                description,
                valueName,
                defaultValue.toString());

    parser.addOption(option);
}

void ArgumentsConsole::registerOption(
        const QStringList &names,
        const QString &description,
        const QString &valueName,
        const QVariant &defaultValue)
{
    QCommandLineOption option(
                names,
                description,
                valueName,
                defaultValue.toString());

    parser.addOption(option);
}

void ArgumentsConsole::registerArgument(
        const QString &name,
        const QString &description,
        const QString &syntax)
{
    parser.addPositionalArgument(name, description, syntax);
}

QVariant ArgumentsConsole::value(const QString &name, const QVariant &defaultValue)
{
    return parser.isSet(name) ? parser.value(name) : defaultValue;
}

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

void ArgumentsConsole::onAttachContainer()
{
    qDebug() << "ArgumentsConsole::onAttachContainer";

    Container* container = static_cast<Container*>(getContainer());

    QObject::connect(
        container->getApplication(), &Application::doInit,
        this, &ArgumentsConsole::onApplicationInit
    );
}

void ArgumentsConsole::onApplicationInit()
{
    parser.process(getArguments());
}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Arguments> getArgumentsConsoleComponent()
{
    return createComponent()
            .bind<Arguments, ArgumentsConsole>();
}
