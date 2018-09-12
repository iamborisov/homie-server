#include "Service.h"
#include <QDebug>
#include "Container/Container.h"

Service::Service() :
    QObject(nullptr)
{
    QObject::connect(this, &Service::doAttachContainer, this, &Service::onAttachContainer);
    QObject::connect(this, &Service::doDetachContainer, this, &Service::onDetachContainer);
}

//-----------------------------------------------------------------------------
// Fields
//-----------------------------------------------------------------------------

Service* Service::getContainer()
{
    if (container == nullptr) {
        qDebug() << "container is NULL";
        return nullptr;
    } else {
        return static_cast<Service*>(container);
    }
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

void Service::attach(Service* container)
{
    if (this->container == container) {
        return;
    }

    if (this->container != nullptr) {
        detach();
    }

    this->container = container;
    emit doAttachContainer();
}

void Service::detach()
{
    if (this->container == nullptr) {
        return;
    }

    emit doDetachContainer();
    container = nullptr;
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
