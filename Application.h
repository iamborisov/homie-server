#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QCoreApplication>

#include "Arguments.h"

class Application : public QObject
{
    Q_OBJECT

public:
    Application(Arguments* arguments);

protected:
    int timeout = 10; //ms

private:
    QCoreApplication* core;
    Arguments* arguments;

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

public:
    int run();
    void quit();

private:
    void main();
    void startTimer(int delay);
    void stopTimer();

private slots:
    void onTimer();
    void onTimerQuit();

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

signals:
    void doRun();
    void doMain();
    void doQuit();

private: // bindings
    void bindRun();
    void bindMain();
    void bindQuit();

public slots:
    virtual void onRun() = 0;
    virtual void onMain() = 0;
    virtual void onQuit() = 0;
};

#endif // APPLICATION_H
