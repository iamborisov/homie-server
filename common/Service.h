#ifndef CONTAINERSERVICE_H
#define CONTAINERSERVICE_H

#include <QObject>

class Service : public QObject
{
    Q_OBJECT
public:
    explicit Service();

//-----------------------------------------------------------------------------
// Fields
//  - container
//-----------------------------------------------------------------------------

public:
    Service* getContainer();

//-----------------------------------------------------------------------------
// Methods
//  - attach
//  - detach
//-----------------------------------------------------------------------------

public:
    void attach(Service* container);
    void detach();

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
