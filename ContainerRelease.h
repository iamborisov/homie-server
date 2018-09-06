#ifndef  HOMIE_CONTAINER_RELEASE_H
#define  HOMIE_CONTAINER_RELEASE_H

#include "Container.h"

class ContainerRelease : public Container
{
public:
    INJECT(ContainerRelease());
};

Component<Container> getContainerReleaseComponent();

#endif //  HOMIE_CONTAINER_RELEASE_H
