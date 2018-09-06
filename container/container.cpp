#include "container.h"

Container::Container() : QObject(nullptr)
{

}

Component<Container> getContainerComponent() {
  return fruit::createComponent();
          //.bind<Writer, StdoutWriter>()
          //.bind<Greeter, GreeterImpl>();
}
