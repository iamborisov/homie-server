#ifndef  CONTAINER_DEBUG_H
#define  CONTAINER_DEBUG_H

#include "fruit.h"
#include "Container.h"

class ContainerDebug : public Container
{
public:
    INJECT(ContainerDebug(
        Application* application,
        Arguments* arguments,
        Configuration* configuration
    ));
};

Component<Container> getContainerDebugComponent();

#endif //  CONTAINER_DEBUG_H
