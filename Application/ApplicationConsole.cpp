#include "ApplicationConsole.h"
#include <QDebug>

ApplicationConsole::ApplicationConsole(Arguments* arguments):
    Application(arguments)
{

}

void ApplicationConsole::onRun()
{
    qDebug() << "ApplicationConsole::onRun";
}

void ApplicationConsole::onMain()
{
    qDebug() << "ApplicationConsole::onMain";
}

void ApplicationConsole::onQuit()
{
    qDebug() << "ApplicationConsole::onQuit";
}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Required<Arguments>, Application> getApplicationConsoleComponent()
{
    return fruit::createComponent()
            .bind<Application, ApplicationConsole>();
}
