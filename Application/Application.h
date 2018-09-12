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
    ~Application();

//-----------------------------------------------------------------------------
// Fields
//  - finished
//-----------------------------------------------------------------------------

public:
    bool isFinished();

private:
    int timeout = 10; //ms
    bool finished = false;

protected:
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

protected:
    void init();
    void start();
    void cycle();

protected slots:
    void onCycle();
    void onShutdown();

//-----------------------------------------------------------------------------
// Events
//  - onBeforeInit
//  - onInit
//  - onAfterInit
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
    void doBeforeInit();
    void doInit();
    void doAfterInit();
    void doBeforeStart();
    void doStart();
    void doAfterStart();
    void doBeforeLoop();
    void doLoop();
    void doAfterLoop();
    void doBeforeQuit();
    void doQuit();

public slots:
    void onBeforeInit();
    void onInit();
    void onAfterInit();
    void onBeforeStart();
    void onStart();
    void onAfterStart();
    void onBeforeLoop();
    void onLoop();
    void onAfterLoop();
    void onBeforeQuit();
    void onQuit();

//-----------------------------------------------------------------------------
// Service
//-----------------------------------------------------------------------------

protected slots:
    virtual void onAttachContainer() override;
    virtual void onDetachContainer() override;

//-----------------------------------------------------------------------------
};

#endif // APPLICATION_H
