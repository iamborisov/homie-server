// Determine application container type
#if defined(DEBUG)
    #include "Container/ContainerDebug.h"
    #define getContainerComponent getContainerDebugComponent
#elif defined(TEST)
    #include "Container/ContainerTest.h"
    #define getContainerComponent getContainerTestComponent
#else
    #include "Container/ContainerRelease.h"
    #define getContainerComponent getContainerReleaseComponent
#endif

int main(int argc, char *argv[])
{
    // Create container
    Injector<Container> injector(getContainerComponent);
    Container* container = injector.get<Container*>();

    // Pass command line arguments
    container->getArguments()->set(argc, argv);

    // Execute
    return container->getApplication()->exec();
}

