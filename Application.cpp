#include "Application.h"
#include <QTimer>

Application::Application(Arguments* arguments) :
    QObject(nullptr),
    arguments(arguments)
{
}

//-----------------------------------------------------------------------------
// Main loop timer
//-----------------------------------------------------------------------------

void Application::startTimer(int delay)
{
    if (delay > 0) {
        QTimer::singleShot(delay, this, SLOT(onTimer()));
    } else if (delay == 0) {
        onTimer();
    }
}

void Application::stopTimer()
{
    timeout = -1;
}

void Application::onTimer()
{
    main();
    startTimer(timeout);
}

void Application::onTimerQuit()
{
    stopTimer();
}

//-----------------------------------------------------------------------------
// "Run" event
//-----------------------------------------------------------------------------

int Application::run()
{
    // Init application core
    core = new QCoreApplication(arguments->getArgc(), arguments->getArgv());
    core->setApplicationName(APP_NAME);
    core->setApplicationVersion(APP_VERSION);

    // Events bindings
    bindRun();
    bindMain();
    bindQuit();

    // Emit event
    emit doRun();

    // Start main loop
    startTimer(timeout);

    // Run application core
    return core->exec();
}

void Application::bindRun()
{
    QObject::connect(
        this, SIGNAL(doRun()),
        this, SLOT(onRun())
    );
}

//-----------------------------------------------------------------------------
// "Main" event
//-----------------------------------------------------------------------------

void Application::main()
{
    emit doMain();
}

void Application::bindMain()
{
    QObject::connect(
        this, SIGNAL(doMain()),
        this, SLOT(onMain())
    );
}

//-----------------------------------------------------------------------------
// "Quit" event
//-----------------------------------------------------------------------------

void Application::quit()
{
    emit doQuit();
}

void Application::bindQuit()
{
    QObject::connect(
        this, SIGNAL(doQuit()),
        core, SLOT(quit())
    );

    QObject::connect(
        core, SIGNAL(aboutToQuit()),
        this, SLOT(onTimerQuit())
    );
    QObject::connect(
        core, SIGNAL(aboutToQuit()),
        this, SLOT(onQuit())
    );
}





