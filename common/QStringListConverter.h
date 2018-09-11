#ifndef QSTRINGLISTCONVERTER_H
#define QSTRINGLISTCONVERTER_H

#include <QStringList>

/**
 * QStringList to char** converter
 *
 * Usage:
 *      QStringList list;
 *      const char** result = new const char*[list.count()];
 *      std::generate(result, result + list.size(), QStringListConverter(list));
 *
 */
class QStringListConverter
{

public:
    QStringListConverter(QStringList &list);
    char* operator()();

private:
    QStringList _list;
    int currIdx;

};

#endif // QSTRINGLISTCONVERTER_H
