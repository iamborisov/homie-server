#ifndef  CONTAINER_RELEASE_H
#define  CONTAINER_RELEASE_H

#include "fruit.h"
#include "Container.h"

class ContainerRelease : public Container
{
public:
    INJECT(ContainerRelease(
        Application* application,
        Arguments* arguments,
        Configuration* configuration
    ));
};

Component<Container> getContainerReleaseComponent();

#endif //  CONTAINER_RELEASE_H
