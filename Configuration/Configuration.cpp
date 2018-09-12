#include "Configuration.h"
#include "Container/Container.h"
#include <QDebug>

Configuration::Configuration(ConfigurationResolver* resolver) :
    Service(),
    resolver(resolver)
{
}

void Configuration::onAttachContainer()
{
    qDebug() << "Configuration::onAttachContainer";

    resolver->attach(getContainer());

    Container* container = static_cast<Container*>(getContainer());

    Application* application = container->getApplication();
    Configuration* configuration = container->getConfiguration();

    QObject::connect(
        application, &Application::doBeforeInit,
        configuration, &Configuration::onApplicationBeforeInit
    );
    QObject::connect(
        application, &Application::doAfterInit,
        configuration, &Configuration::onApplicationAfterInit
    );
}

void Configuration::onDetachContainer()
{
    resolver->detach();
}

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------

std::vector<ConfigurationService*> Configuration::getConfigurableServices()
{
    Container* container = static_cast<Container*>(getContainer());

    return container
            ->getInjector()
            ->getMultibindings<ConfigurationService>();
}

//-----------------------------------------------------------------------------
// Events
//-----------------------------------------------------------------------------

void Configuration::onApplicationBeforeInit()
{
    qDebug() << "Configuration::onApplicationBeforeInit()";

    foreach(ConfigurationService* service, getConfigurableServices()) {
        resolver->load(service);
    }
}

void Configuration::onApplicationAfterInit()
{
    qDebug() << "Configuration::onApplicationAfterInit()";

    foreach(ConfigurationService* service, getConfigurableServices()) {
        resolver->resolve(service);
    }
}
