#include "Application.h"

#include <QTimer>

#include <QDebug>

Application::Application(Arguments* arguments) :
    Service(),
    arguments(arguments)
{
    qDebug() << "new Application";
}

Application::~Application()
{
    qDebug() << "delete Application";
}

void Application::onAttachContainer()
{
    arguments->attach(getContainer());
}

void Application::onDetachContainer()
{
    arguments->detach();
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
            QTimer::singleShot(timeout, this, &Application::onCycle);
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
    QObject::connect(this, &Application::doBeforeInit,  this, &Application::onBeforeInit);
    QObject::connect(this, &Application::doInit,        this, &Application::onInit);
    QObject::connect(this, &Application::doAfterInit,   this, &Application::onAfterInit);

    QObject::connect(this, &Application::doBeforeStart, this, &Application::onBeforeStart);
    QObject::connect(this, &Application::doStart,       this, &Application::onStart);
    QObject::connect(this, &Application::doAfterStart,  this, &Application::onAfterStart);

    QObject::connect(this, &Application::doBeforeLoop,  this, &Application::onBeforeLoop);
    QObject::connect(this, &Application::doLoop,        this, &Application::onLoop);
    QObject::connect(this, &Application::doAfterLoop,   this, &Application::onAfterLoop);

    QObject::connect(this, &Application::doBeforeQuit,  this, &Application::onBeforeQuit);
    QObject::connect(this, &Application::doQuit,        this, &Application::onQuit);

    // Bind application quit
    QObject::connect(core, &QCoreApplication::aboutToQuit, this, &Application::onShutdown);

    // Emit initialization event
    emit doBeforeInit();
    emit doInit();
    emit doAfterInit();
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

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

void Application::onBeforeInit()    {qDebug() << "Application::onBeforeInit";}
void Application::onInit()          {qDebug() << "Application::onInit";}
void Application::onAfterInit()     {qDebug() << "Application::onAfterInit";}
void Application::onBeforeStart()   {qDebug() << "Application::onBeforeStart";}
void Application::onStart()         {qDebug() << "Application::onStart";}
void Application::onAfterStart()    {qDebug() << "Application::onAfterStart";}
void Application::onBeforeLoop()    {}
void Application::onLoop()          {}
void Application::onAfterLoop()     {}
void Application::onBeforeQuit()    {qDebug() << "Application::onBeforeQuit";}
void Application::onQuit()          {qDebug() << "Application::onQuit";}






