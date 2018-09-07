#include "ContainerDebug.h"

#include "Application/ApplicationConsole.h"
#include "Arguments/ArgumentsConsole.h"
#include "Configuration/ConfigurationFile.h"

ContainerDebug::ContainerDebug( Application* application,
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

Component<Container> getContainerDebugComponent() {
    return fruit::createComponent()
            .install(getApplicationConsoleComponent)
            .install(getArgumentsConsoleComponent)
            .install(getConfigurationFileComponent)
            .bind<Container, ContainerDebug>();
}
