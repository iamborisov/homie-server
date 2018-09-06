#include "ContainerDebug.h"
#include "ContainerRelease.h"

ContainerDebug::ContainerDebug(): Container ()
{

}

Component<Container> getContainerDebugComponent() {
  return fruit::createComponent()
          //.replace(Some Release Dependency).with(Some Debug Dependency)
          .install(getContainerReleaseComponent);
}
