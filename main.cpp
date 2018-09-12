// Determine application container type
#if defined(DEBUG)
    #include "Container/Environment/ContainerDebug.h"
    #define getContainerComponent getContainerDebugComponent
#elif defined(TEST)
    #include "Container/Environment/ContainerTest.h"
    #define getContainerComponent getContainerTestComponent
#else
    #include "Container/Environment/ContainerRelease.h"
    #define getContainerComponent getContainerReleaseComponent
#endif

int main(int argc, char *argv[])
{
    // Create container
    Injector<Container> injector(getContainerComponent);
    Container* container = injector.get<Container*>();

    container->setInjector(&injector);
    container->attach(container);

    // Pass command line arguments
    container->getArguments()
             ->setArguments(argc, argv);

    // Execute
    return container
            ->getApplication()
            ->exec();
}

