#include "ApplicationConsole.h"

#include <QDebug>

ApplicationConsole::ApplicationConsole(Arguments* arguments):
    Application(arguments)
{
    qDebug() << "new ApplicationConsole";
}

ApplicationConsole::~ApplicationConsole()
{
    qDebug() << "delete ApplicationConsole";
}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Required<Arguments>, Application> getApplicationConsoleComponent()
{
    return createComponent()
            .bind<Application, ApplicationConsole>();
}
