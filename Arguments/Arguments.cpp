#include "Arguments.h"

Arguments::Arguments():
    Service(),
    arguments()
{
    this->argc = 0;
}

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

void Arguments::setArguments(int &argc, char **argv)
{
    arguments.clear();

    for (int a = 0; a < argc; ++a) {
        arguments << QString::fromLocal8Bit(argv[a]);
    }

    this->argc = argc;
    this->argv = argv;
}

const QStringList Arguments::getArguments()
{
    return arguments;
}

int& Arguments::getArgc()
{
    return argc;
}

char** Arguments::getArgv()
{
    return argv;
}
