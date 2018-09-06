#include "ContainerRelease.h"

#include "ApplicationConsole.h"
#include "ArgumentsConsole.h"
#include "ConfigurationFile.h"

ContainerRelease::ContainerRelease( Application* application,
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

Component<Container> getContainerReleaseComponent() {
    return fruit::createComponent()
            .install(getApplicationConsoleComponent)
            .install(getArgumentsConsoleComponent)
            .install(getConfigurationFileComponent)
            .bind<Container, ContainerRelease>();
}
