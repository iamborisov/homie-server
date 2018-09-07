#include "ContainerRelease.h"

#include "Application/ApplicationConsole.h"
#include "Arguments/ArgumentsConsole.h"
#include "Configuration/ConfigurationFile.h"

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
