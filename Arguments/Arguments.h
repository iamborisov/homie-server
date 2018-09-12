#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QString>
#include <QStringList>
#include <QVariant>

#include "common/Service.h"

class Arguments : public Service
{
    Q_OBJECT
public:
    Arguments();

//-----------------------------------------------------------------------------
// Methods
//-----------------------------------------------------------------------------
public:
    virtual void registerOption(
            const QString &name,
            const QString &description,
            const QString &valueName = QString(),
            const QVariant &defaultValue = QVariant()) = 0;

    virtual void registerOption(
            const QStringList &names,
            const QString &description,
            const QString &valueName = QString(),
            const QVariant &defaultValue = QVariant()) = 0;

    virtual void registerArgument(
            const QString &name,
            const QString &description = QString(),
            const QString &syntax = QString()) = 0;

    virtual QVariant value(
            const QString &name,
            const QVariant &defaultValue = QVariant()) = 0;

//-----------------------------------------------------------------------------
// Fields
//  - arguments
//  - argc
//  - argv
//-----------------------------------------------------------------------------

public:
    void setArguments(int &argc, char **argv);
    const QStringList getArguments();

    int& getArgc();
    char** getArgv();

private:
    QStringList arguments;
    int argc;
    char **argv;

//-----------------------------------------------------------------------------
};

#endif // ARGUMENTS_H
