#include "ArgumentsConsole.h"

ArgumentsConsole::ArgumentsConsole():
    Arguments(),
    parser()
{
    parser.setApplicationDescription("SmartHome server, 2018");
    parser.addVersionOption();
    parser.addHelpOption();
}

void ArgumentsConsole::process()
{
    parser.process(getArguments());
}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Arguments> getArgumentsConsoleComponent() {
    return fruit::createComponent()
            .bind<Arguments, ArgumentsConsole>();
}
