#ifndef CONTAINER_TEST_H
#define CONTAINER_TEST_H

#include "common/fruit.h"
#include "Container.h"

class ContainerTest : public Container
{
public:
    INJECT(ContainerTest(
        Application* application,
        Arguments* arguments,
        Configuration* configuration
    ));
};

Component<Container> getContainerTestComponent();

#endif // HOMIE_CONTAINER_TEST_H
