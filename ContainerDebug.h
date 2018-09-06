#ifndef  HOMIE_CONTAINER_DEBUG_H
#define  HOMIE_CONTAINER_DEBUG_H

#include "Container.h"

class ContainerDebug : public Container
{
public:
    INJECT(ContainerDebug());
};

Component<Container> getContainerDebugComponent();

#endif //  HOMIE_CONTAINER_DEBUG_H
