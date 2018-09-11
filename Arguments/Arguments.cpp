#include "Arguments.h"

#include "common/QStringListConverter.h"

Arguments::Arguments():
    Service(),
    arguments()
{
}

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

void Arguments::set(const QStringList args)
{
    arguments.clear();

    foreach(QString s, args) {
        arguments << s;
    }

    count = arguments.count();
}

void Arguments::set(int &argc, char **argv)
{
    arguments.clear();

    for (int a = 0; a < argc; ++a) {
        arguments << QString::fromLocal8Bit(argv[a]);
    }

    count = argc;
}

const QStringList Arguments::get()
{
    return arguments;
}

int& Arguments::getArgc()
{
    return count;
}

char** Arguments::getArgv()
{
    char** result = new char*[arguments.count()];

    std::generate(result, result + arguments.size(), QStringListConverter(arguments));

    return result;
}
