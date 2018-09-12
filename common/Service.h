#ifndef CONTAINERSERVICE_H
#define CONTAINERSERVICE_H

#include <QObject>

class Service : public QObject
{
    Q_OBJECT
public:
    Service();

//-----------------------------------------------------------------------------
// Fields
//  - container
//-----------------------------------------------------------------------------

public:
    Service* getContainer();

private:
    Service* container;

//-----------------------------------------------------------------------------
// Methods
//  - attach
//  - detach
//-----------------------------------------------------------------------------

public:
    virtual void attach(Service* container);
    virtual void detach();

//-----------------------------------------------------------------------------
// Events
//  - onAttachContainer
//  - onDetachContainer
//-----------------------------------------------------------------------------

signals:
    void doAttachContainer();
    void doDetachContainer();

protected slots:
    virtual void onAttachContainer();
    virtual void onDetachContainer();

//-----------------------------------------------------------------------------
};

#endif // CONTAINERSERVICE_H
