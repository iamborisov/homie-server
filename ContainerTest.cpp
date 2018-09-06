#include "ContainerTest.h"

#include "ApplicationConsole.h"
#include "ArgumentsConsole.h"
#include "ConfigurationFile.h"

ContainerTest::ContainerTest( Application* application,
                              Arguments* arguments,
                              Configuration* configuration) :
    Container( application,
               arguments,
               configuration)
{

}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Container> getContainerTestComponent() {
    return fruit::createComponent()
            .install(getApplicationConsoleComponent)
            .install(getArgumentsConsoleComponent)
            .install(getConfigurationFileComponent)
            .bind<Container, ContainerTest>();
}
