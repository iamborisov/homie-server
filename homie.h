#ifndef HOMIE_H
#define HOMIE_H

#include <QObject>
#include <QCoreApplication>
#include <QCommandLineParser>
#include <container/container.h>

class Homie : public QObject
{
    Q_OBJECT
public:
    explicit Homie(int &argc, char **argv);

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

public:
    int frequency;

private:
    QCoreApplication application;
    QCommandLineParser arguments;

    Container* container;

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

public:
    int run();
    void quit();

private:
    void main();
    void defer(bool force = false);

private slots:
    void onDefer();

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

private slots:
    void onRun();
    void onMain();
    void onQuit();
};

#endif // HOMIE_H
