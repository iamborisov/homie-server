#ifndef ARGUMENTSCONSOLE_H
#define ARGUMENTSCONSOLE_H

#include <QCommandLineParser>
#include "fruit.h"
#include "Arguments.h"

class ArgumentsConsole : public Arguments
{
public:
    INJECT(ArgumentsConsole());

    virtual void process() override;

private:
    QCommandLineParser parser;

};

Component<Arguments> getArgumentsConsoleComponent();

#endif // ARGUMENTSCONSOLE_H
