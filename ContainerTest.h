#ifndef HOMIE_CONTAINER_TEST_H
#define HOMIE_CONTAINER_TEST_H

#include "Container.h"

class ContainerTest : public Container
{
public:
    INJECT(ContainerTest());
};

Component<Container> getContainerTestComponent();

#endif // HOMIE_CONTAINER_TEST_H
