#include "Application.h"
#include <QTimer>
#include <fruit/fruit.h>

#if defined(DEBUG)
    #include "ContainerDebug.h"
#elif defined(TEST)
    #include "ContainerTest.h"
#else
    #include "ContainerRelease.h"
#endif

using fruit::Component;
using fruit::Injector;

Application::Application(int &argc, char **argv) :
    QObject(nullptr),
    frequency(0),
    application(argc, argv),
    arguments()
{
    // Application info
    application.setApplicationName(APP_NAME);
    application.setApplicationVersion(APP_VERSION);

    // CLI Arguments parser
    arguments.setApplicationDescription(APP_DESCRIPTION);
    arguments.addVersionOption();
    arguments.addHelpOption();

    // Events bindings
    bindRun();
    bindMain();
    bindQuit();

    // Dependency Injection container
#if defined(DEBUG)
    Injector<Container> injector(getContainerDebugComponent);
#elif defined(TEST)
    Injector<Container> injector(getContainerTestComponent);
#else
    Injector<Container> injector(getContainerReleaseComponent);
#endif

    container = injector.get<Container*>();
}

//-----------------------------------------------------------------------------
// Main loop timer
//-----------------------------------------------------------------------------

void Application::defer(bool force)
{
    if (force || frequency > 0) {
        QTimer::singleShot(frequency, this, SLOT(onDefer()));
    }
}

void Application::onDefer()
{
    main();
    defer();
}

//-----------------------------------------------------------------------------
// "Run" event
//-----------------------------------------------------------------------------

int Application::run()
{
    emit doRun();

    arguments.process(application);

    return application.exec();
}

void Application::bindRun()
{
    QObject::connect(
        this, SIGNAL(doRun()),
        this, SLOT(onRun())
    );
}

void Application::onRun()
{
    // TODO: load resources

    defer(true);
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

void Application::onMain()
{
    // TODO: main loop
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
        &application, SLOT(quit())
    );
    QObject::connect(
        &application, SIGNAL(aboutToQuit()),
        this, SLOT(onQuit())
    );
}

void Application::onQuit()
{
    frequency = 0;

    // TODO: free resources
}





