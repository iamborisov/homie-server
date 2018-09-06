#ifndef APPLICATIONCONSOLE_H
#define APPLICATIONCONSOLE_H

#include "fruit.h"
#include "Application.h"

class ApplicationConsole : public Application
{
public:
    INJECT(ApplicationConsole(Arguments* arguments));

public slots:
    virtual void onRun() override;
    virtual void onMain() override;
    virtual void onQuit() override;
};

Component<Required<Arguments>, Application> getApplicationConsoleComponent();

#endif // APPLICATIONCONSOLE_H
