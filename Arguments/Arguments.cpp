#include "Arguments.h"

Arguments::Arguments(): QObject(nullptr)
{
}

Arguments* Arguments::setArgc(int &argc)
{
    this->argc = argc;

    return this;
}

int& Arguments::getArgc()
{
    return this->argc;
}

Arguments* Arguments::setArgv(char **argv)
{
    this->argv = argv;

    return this;
}

char** Arguments::getArgv()
{
    return this->argv;
}

QStringList Arguments::getArguments()
{
    QStringList list;

    const int ac = argc;
    char ** const av = argv;
    for (int a = 0; a < ac; ++a) {
        list << QString::fromLocal8Bit(av[a]);
    }

    return list;
}
