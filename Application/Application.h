#ifndef APPLICATION_H
#define APPLICATION_H

#include <QCoreApplication>

#include "common/Service.h"

#include "Arguments/Arguments.h"

class Application : public Service
{
    Q_OBJECT
public:
    Application(Arguments* arguments);

//-----------------------------------------------------------------------------
// Fields
//  - finished
//-----------------------------------------------------------------------------

public:
    bool isFinished();

private:
    int timeout = 10; //ms
    bool finished = false;

    QCoreApplication* core;
    Arguments* arguments;

//-----------------------------------------------------------------------------
// Methods
//  - exec
//  - quit
//-----------------------------------------------------------------------------

public:
    int exec();
    void quit();

private:
    void init();
    void start();
    void cycle();

private slots:
    void onCycle();
    void onShutdown();

//-----------------------------------------------------------------------------
// Events
//  - onInit
//  - onBeforeStart
//  - onStart
//  - onAfterStart
//  - onBeforeLoop
//  - onLoop
//  - onAfterLoop
//  - onBeforeQuit
//  - onQuit
//-----------------------------------------------------------------------------

signals:
    void doInit();
    void doBeforeStart();
    void doStart();
    void doAfterStart();
    void doBeforeLoop();
    void doLoop();
    void doAfterLoop();
    void doBeforeQuit();
    void doQuit();

public slots:
    virtual void onInit() = 0;
    virtual void onBeforeStart() = 0;
    virtual void onStart() = 0;
    virtual void onAfterStart() = 0;
    virtual void onBeforeLoop() = 0;
    virtual void onLoop() = 0;
    virtual void onAfterLoop() = 0;
    virtual void onBeforeQuit() = 0;
    virtual void onQuit() = 0;

//-----------------------------------------------------------------------------
};

#endif // APPLICATION_H
