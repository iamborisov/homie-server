#include "ContainerDebug.h"

#include "Application/ApplicationConsole.h"
#include "Arguments/ArgumentsConsole.h"
#include "Configuration/Source/ConfigurationSourceFile.h"
#include "Configuration/Source/ConfigurationSourceArguments.h"
#include "Configuration/Resolver/ConfigurationResolverPriority.h"
#include "Configuration/Environment/ConfigurationDebug.h"

#include "Test/TestServiceImpl.h"

ContainerDebug::ContainerDebug( Application* application,
                                Arguments* arguments,
                                Configuration* configuration,
                                TestService* testService) :
    Container( application,
               arguments,
               configuration),
      testService(testService)
{

}

void ContainerDebug::onAttachContainer()
{
    Container::onAttachContainer();
    testService->attach(getContainer());
}

void ContainerDebug::onDetachContainer()
{
    Container::onDetachContainer();
    testService->detach();
}

//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<Container> getContainerDebugComponent() {
    return createComponent()

            // application
            .install(getApplicationConsoleComponent)

            // arguments
            .install(getArgumentsConsoleComponent)

            // configuration
            .addMultibinding<ConfigurationSource, ConfigurationSourceFile>()
            .addMultibinding<ConfigurationSource, ConfigurationSourceArguments>()
            .install(getConfigurationResolverPriorityComponent)
            .install(getConfigurationDebugComponent)

            // test
            .addMultibinding<ConfigurationService, TestServiceImpl>()
            .install(getTestServiceComponent)

            .bind<Container, ContainerDebug>();
}
