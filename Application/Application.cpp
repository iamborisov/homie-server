#include "Application.h"

#include <QTimer>

Application::Application(Arguments* arguments) :
    Service(),
    arguments(arguments)
{
}

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

bool Application::isFinished()
{
    return finished;
}

//-----------------------------------------------------------------------------
// Main cycle
//-----------------------------------------------------------------------------

void Application::cycle()
{
    if (!finished) {
        if (timeout >= 0) {
            QTimer::singleShot(timeout, this, SLOT(onCycle()));
        } else {
            onCycle();
        }
    }
}

void Application::onCycle()
{
    if (!finished) {
        emit doBeforeLoop();
        emit doLoop();
        emit doAfterLoop();

        cycle();
    }
}

void Application::onShutdown()
{
    finished = true;

    emit doBeforeQuit();
    emit doQuit();
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void Application::init()
{
    // Init application core
    core = new QCoreApplication(arguments->getArgc(), arguments->getArgv());
    core->setApplicationName(APP_NAME);
    core->setApplicationVersion(APP_VERSION);

    // Bind events slots
    QObject::connect(this, SIGNAL(doInit()), this, SLOT(onInit()));

    QObject::connect(this, SIGNAL(doBeforeStart()), this, SLOT(onBeforeStart()));
    QObject::connect(this, SIGNAL(doStart()), this, SLOT(onStart()));
    QObject::connect(this, SIGNAL(doAfterStart()), this, SLOT(onAfterStart()));

    QObject::connect(this, SIGNAL(doBeforeLoop()), this, SLOT(onBeforeLoop()));
    QObject::connect(this, SIGNAL(doLoop()), this, SLOT(onLoop()));
    QObject::connect(this, SIGNAL(doAfterLoop()), this, SLOT(onAfterLoop()));

    QObject::connect(this, SIGNAL(doBeforeQuit()), this, SLOT(onBeforeQuit()));
    QObject::connect(this, SIGNAL(doQuit()), this, SLOT(onQuit()));

    // Bind application quit
    QObject::connect(core, SIGNAL(aboutToQuit()), this, SLOT(onShutdown()));

    // Emit initialization event
    emit doInit();
}

void Application::start()
{
    emit doBeforeStart();
    emit doStart();
    emit doAfterStart();

    // Start main loop
    cycle();
}

int Application::exec()
{
    init();
    start();

    return core->exec();
}

void Application::quit()
{
    core->quit();
}






