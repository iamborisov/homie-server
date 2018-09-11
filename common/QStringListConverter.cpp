#include "QStringListConverter.h"

QStringListConverter::QStringListConverter(QStringList &list)
:_list(list), currIdx(0)
{
}

char* QStringListConverter::operator()()
{
    return _list[currIdx++].toLocal8Bit().data();
}
