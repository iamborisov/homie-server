#include "ContainerRelease.h"

#include "Application/ApplicationConsole.h"
#include "Arguments/ArgumentsConsole.h"
#include "Configuration/Source/ConfigurationSourceFile.h"
#include "Configuration/Source/ConfigurationSourceArguments.h"
#include "Configuration/Resolver/ConfigurationResolverPriority.h"
#include "Configuration/Environment/ConfigurationRelease.h"

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
    return createComponent()

            // application
            .install(getApplicationConsoleComponent)

            // arguments
            .install(getArgumentsConsoleComponent)

            // configuration
            .addMultibinding<ConfigurationSource, ConfigurationSourceFile>()
            .addMultibinding<ConfigurationSource, ConfigurationSourceArguments>()
            .install(getConfigurationResolverPriorityComponent)
            .install(getConfigurationReleaseComponent)

            .bind<Container, ContainerRelease>();
}
