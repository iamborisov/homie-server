#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QStringList>

#include "common/Service.h"

class Arguments : public Service
{
    Q_OBJECT
public:
    Arguments();

//-----------------------------------------------------------------------------
// Fields
//  - ...
//  - argc
//  - argv
//-----------------------------------------------------------------------------

public:
    void set(QStringList args);
    void set(int &argc, char **argv);
    const QStringList get();

    int& getArgc();
    char** getArgv();

private:
    QStringList arguments;
    int count;

//-----------------------------------------------------------------------------
};

#endif // ARGUMENTS_H
