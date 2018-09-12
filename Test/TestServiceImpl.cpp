#include "TestServiceImpl.h"

TestServiceImpl::TestServiceImpl():
    TestService ()
{

}


//-----------------------------------------------------------------------------
// Dependency Injection
//-----------------------------------------------------------------------------

Component<TestService> getTestServiceComponent()
{
    return createComponent()
            .bind<TestService, TestServiceImpl>();
}
