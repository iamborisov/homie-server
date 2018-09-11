#include "ArgumentsConsole.h"

#include "Container/Container.h"
#include "Application/Application.h"

ArgumentsConsole::ArgumentsConsole():
    Arguments(),
    parser()
{
    parser.setApplicationDescription("SmartHome server, 2018");
    parser.addVersionOption();
    parser.addHelpOption();
}

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

void ArgumentsConsole::onAttachContainer()
{
    Container* container = static_cast<Container*>(getContainer());

    QObject::connect(
        container->getApplication(), SIGNAL(doInit()),
        this, SLOT(onApplicationInit())
    );
}

void ArgumentsConsole::onApplicationInit()
{
    parser.process(get());
}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Arguments> getArgumentsConsoleComponent() {
    return fruit::createComponent()
            .bind<Arguments, ArgumentsConsole>();
}
