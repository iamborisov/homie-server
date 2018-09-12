#ifndef  CONTAINER_RELEASE_H
#define  CONTAINER_RELEASE_H

#include "common/fruit.h"

#include "Container/Container.h"

class ContainerRelease : public Container
{
    Q_OBJECT
public:
    INJECT(ContainerRelease(
        Application* application,
        Arguments* arguments,
        Configuration* configuration
    ));
};

Component<Container> getContainerReleaseComponent();

#endif //  CONTAINER_RELEASE_H
