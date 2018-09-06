#include "ContainerRelease.h"

ContainerRelease::ContainerRelease(): Container ()
{

}

Component<Container> getContainerReleaseComponent() {
  return fruit::createComponent()
          .bind<Container, ContainerRelease>();
}
