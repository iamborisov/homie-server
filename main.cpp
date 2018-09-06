// Determine application container type
#if defined(DEBUG)
    #include "ContainerDebug.h"
    #define getContainer getContainerDebugComponent
#elif defined(TEST)
    #include "ContainerTest.h"
    #define getContainer getContainerTestComponent
#else
    #include "ContainerRelease.h"
    #define getContainer getContainerReleaseComponent
#endif

int main(int argc, char *argv[])
{
    // Create container
    Injector<Container> injector(getContainer);
    Container* container = injector.get<Container*>();

    // Handle command line arguments
    container->getArguments()
            ->setArgc(argc)
            ->setArgv(argv)
            ->process();

    // Execute
    return container->getApplication()->run();
}
