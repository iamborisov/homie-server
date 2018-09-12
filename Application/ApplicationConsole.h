#ifndef APPLICATIONCONSOLE_H
#define APPLICATIONCONSOLE_H

#include "common/fruit.h"

#include "Application.h"

class ApplicationConsole : public Application
{
    Q_OBJECT
public:
    INJECT(ApplicationConsole(Arguments* arguments));
    ~ApplicationConsole();
//-----------------------------------------------------------------------------
};

Component<Required<Arguments>, Application> getApplicationConsoleComponent();

#endif // APPLICATIONCONSOLE_H
