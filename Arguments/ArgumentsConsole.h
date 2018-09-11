#ifndef ARGUMENTSCONSOLE_H
#define ARGUMENTSCONSOLE_H

#include <QCommandLineParser>

#include "common/fruit.h"

#include "Arguments.h"

class ArgumentsConsole : public Arguments
{
    Q_OBJECT
public:
    INJECT(ArgumentsConsole());

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

private:
    QCommandLineParser parser;

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

protected slots:
    virtual void onAttachContainer() override;

private slots:
    void onApplicationInit();

//-----------------------------------------------------------------------------
};

Component<Arguments> getArgumentsConsoleComponent();

#endif // ARGUMENTSCONSOLE_H
