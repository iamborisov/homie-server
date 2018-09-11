#ifndef APPLICATIONCONSOLE_H
#define APPLICATIONCONSOLE_H

#include "common/fruit.h"

#include "Application.h"

class ApplicationConsole : public Application
{
    Q_OBJECT
public:
    INJECT(ApplicationConsole(Arguments* arguments));

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

public slots:
    virtual void onInit() override;
    virtual void onBeforeStart() override;
    virtual void onStart() override;
    virtual void onAfterStart() override;
    virtual void onBeforeLoop() override;
    virtual void onLoop() override;
    virtual void onAfterLoop() override;
    virtual void onBeforeQuit() override;
    virtual void onQuit() override;

//-----------------------------------------------------------------------------
};

Component<Required<Arguments>, Application> getApplicationConsoleComponent();

#endif // APPLICATIONCONSOLE_H
