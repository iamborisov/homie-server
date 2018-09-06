#include "ContainerTest.h"
#include "ContainerRelease.h"

ContainerTest::ContainerTest(): Container ()
{

}

Component<Container> getContainerTestComponent() {
  return fruit::createComponent()
          //.bind<Interface, Test>();
          //.replace(Some Release Dependency).with(Some Debug Dependency)
          .install(getContainerReleaseComponent);
}
