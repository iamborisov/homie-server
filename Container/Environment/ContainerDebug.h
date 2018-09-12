#ifndef  CONTAINER_DEBUG_H
#define  CONTAINER_DEBUG_H

#include "common/fruit.h"

#include "Container/Container.h"
#include "Test/TestService.h"

class ContainerDebug : public Container
{
    Q_OBJECT
public:
    INJECT(ContainerDebug(
        Application* application,
        Arguments* arguments,
        Configuration* configuration,
        TestService* testService
    ));

private:
    TestService* testService;

//-----------------------------------------------------------------------------
// Service
//-----------------------------------------------------------------------------

//public:
//    virtual void attach(Service* container) override;
//    virtual void detach() override;

protected slots:
    virtual void onAttachContainer() override;
    virtual void onDetachContainer() override;

//-----------------------------------------------------------------------------
};

Component<Container> getContainerDebugComponent();

#endif //  CONTAINER_DEBUG_H
