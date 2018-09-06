#include "homie.h"
#include <QTimer>
#include <fruit/fruit.h>

using fruit::Component;
using fruit::Injector;

Homie::Homie(int &argc, char **argv) :
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
    Injector<Container> injector(getContainerComponent);
    container = injector.get<Container*>();
}

//-----------------------------------------------------------------------------
// Main loop timer
//-----------------------------------------------------------------------------

void Homie::defer(bool force)
{
    if (force || frequency > 0) {
        QTimer::singleShot(frequency, this, SLOT(onDefer()));
    }
}

void Homie::onDefer()
{
    main();
    defer();
}

//-----------------------------------------------------------------------------
// "Run" event
//-----------------------------------------------------------------------------

int Homie::run()
{
    emit doRun();

    arguments.process(application);

    return application.exec();
}

void Homie::bindRun()
{
    QObject::connect(
        this, SIGNAL(doRun()),
        this, SLOT(onRun())
    );
}

void Homie::onRun()
{
    // TODO: load resources

    defer(true);
}

//-----------------------------------------------------------------------------
// "Main" event
//-----------------------------------------------------------------------------

void Homie::main()
{
    emit doMain();
}

void Homie::bindMain()
{
    QObject::connect(
        this, SIGNAL(doMain()),
        this, SLOT(onMain())
    );
}

void Homie::onMain()
{
    // TODO: main loop
}

//-----------------------------------------------------------------------------
// "Quit" event
//-----------------------------------------------------------------------------

void Homie::quit()
{
    emit doQuit();
}

void Homie::bindQuit()
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

void Homie::onQuit()
{
    frequency = 0;

    // TODO: free resources
}





