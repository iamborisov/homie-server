#ifndef TESTSERVICEIMPL_H
#define TESTSERVICEIMPL_H

#include "TestService.h"

#include "common/fruit.h"

class TestServiceImpl : public TestService
{
    Q_OBJECT
public:
    INJECT(TestServiceImpl());
};

Component<TestService> getTestServiceComponent();

#endif // TESTSERVICEIMPL_H
