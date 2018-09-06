#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <QObject>
#include <QStringList>

class Arguments : public QObject
{
    Q_OBJECT

public:
    Arguments();

    virtual void process() = 0;

    QStringList getArguments();

    Arguments* setArgc(int &argc);
    int& getArgc();

    Arguments* setArgv(char **argv);
    char** getArgv();

private:
    int argc;
    char **argv;
};

#endif // ARGUMENTS_H
