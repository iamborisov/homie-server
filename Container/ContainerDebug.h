#ifndef  CONTAINER_DEBUG_H
#define  CONTAINER_DEBUG_H

#include "common/fruit.h"

#include "Container.h"

class ContainerDebug : public Container
{
    Q_OBJECT
public:
    INJECT(ContainerDebug(
        Application* application,
        Arguments* arguments,
        Configuration* configuration
    ));
};

Component<Container> getContainerDebugComponent();

#endif //  CONTAINER_DEBUG_H
