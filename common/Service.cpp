#include "Service.h"

#include "Container/Container.h"

Service::Service() :
    QObject(nullptr)
{
    QObject::connect(this, SIGNAL(doAttachContainer()), this, SLOT(onAttachContainer()));
    QObject::connect(this, SIGNAL(doDetachContainer()), this, SLOT(onDetachContainer()));
}

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

Service* Service::getContainer()
{
    return static_cast<Container*>(this->parent());
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void Service::attach(Service* container)
{
    setParent(container);
    emit doAttachContainer();
}

void Service::detach()
{
    emit doDetachContainer();
    setParent(nullptr);
}

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

void Service::onAttachContainer()
{
}

void Service::onDetachContainer()
{
}
