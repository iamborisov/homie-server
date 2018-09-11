#include "ApplicationConsole.h"

ApplicationConsole::ApplicationConsole(Arguments* arguments):
    Application(arguments)
{

}

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

void ApplicationConsole::onInit() {}
void ApplicationConsole::onBeforeStart() {}
void ApplicationConsole::onStart() {}
void ApplicationConsole::onAfterStart() {}
void ApplicationConsole::onBeforeLoop() {}
void ApplicationConsole::onLoop() {}
void ApplicationConsole::onAfterLoop() {}
void ApplicationConsole::onBeforeQuit() {}
void ApplicationConsole::onQuit() {}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Required<Arguments>, Application> getApplicationConsoleComponent()
{
    return fruit::createComponent()
            .bind<Application, ApplicationConsole>();
}
